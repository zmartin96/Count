#include "NumberList.h" 
using namespace std;

int NumberList::count(ListNode* aList) const
{
    if (aList == nullptr)
        return 0;
    else
        return 1 + count(aList->next);
}
//*****************************************************
// add adds a new element to the end of the list.     *
//*****************************************************
void NumberList::add(double number)
{
   if (head == nullptr)
      head = new ListNode(number);
   else
     {
       // The list is not empty
       // Use nodePtr to traverse the list
       ListNode *nodePtr = head;
       while (nodePtr->next != nullptr)
          nodePtr = nodePtr->next;

       // nodePtr->next is nullptr so nodePtr points to the last node
       // Create a new node and put it after the last node
       nodePtr->next = new ListNode(number);
     }
}

//**********************************************
// Removes a number from a list. The function  *
// does not assume that the list is sorted.    *
//**********************************************
void NumberList::remove(int number)
{
  ListNode *nodePtr, *previousNodePtr=nullptr;
   // If the list is empty, do nothing
   if (number<1)  return;

   // Determine if the first node is the one to delete
   if (number==1)
   {
     nodePtr = head;
     head = head->next;
     delete nodePtr;
   }
   else
   {
     // Initialize nodePtr to the head of the list
     nodePtr = head;

     // Skip nodes whose value member is not num
     for (int i=2;i<=number;i++)
     {
        previousNodePtr = nodePtr;
        nodePtr = nodePtr->next;
     }
     // Link the previous node to the node after
     // nodePtr, then delete nodePtr
     if (nodePtr)
     {
        previousNodePtr->next = nodePtr->next;
        delete nodePtr;
     }
   }
}


//***************************************************
// displayList outputs a sequence of all values     *
// currently stored in the list.                    *
//***************************************************
void NumberList::displayList() const
{
   ListNode *nodePtr = head;   // Start at head of list
   while (nodePtr)
   {
      // Print the value in the current node
      cout << nodePtr->value << "    ";
      // Move on to the next node
      nodePtr = nodePtr->next;
   }
}

//******************************************************
// Destructor deallocates the memory used by the list. *
//******************************************************
NumberList::~NumberList()
{
  ListNode *nodePtr = head;  // Start at head of list
  while (nodePtr != nullptr)
  {
      // garbage keeps track of node to be deleted
      ListNode *garbage = nodePtr;
      // Move on to the next node, if any
      nodePtr = nodePtr->next;
      // Delete the "garbage" node
      delete garbage;
  }
}