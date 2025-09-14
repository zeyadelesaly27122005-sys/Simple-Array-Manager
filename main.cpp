
// Simple Array Manager
// Author: Zeyad Elesaly
// Date: 14-09-2025

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class ArrayManager
{
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayManager()
    {
        size = 0;
    }

    void insertAtEnd(int value)
    {
        if (size < MAX_SIZE)
        {
            arr[size++] = value;
        }
        else
        {
            cout << "Array is full.\n";
        }
        display();
    }

    void insertAtPosition(int value, int pos)
    {
        if (pos < 0 || pos > size || size >= MAX_SIZE)
        {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = size; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
        display();
    }

    void removeFromEnd()
    {
        if (size > 0)
        {
            size--;
            cout << "Last element removed.\n";
        }
        else
        {
            cout << "Array is empty.\n";
        }
        display();
    }

    void removeFromPosition(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element removed from position " << pos << ".\n";
        display();
    }

    void searchElement(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                cout << "Element found at index: " << i << endl;
                return;
            }
        }
        cout << "Element not found.\n";
    }

    void editElement(int pos, int newValue)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Invalid position.\n";
            return;
        }
        arr[pos] = newValue;
        cout << "Element at position " << pos << " updated.\n";
        display();
    }

    void display()
    {
        cout << "Current Array: ";
        if (size == 0)
        {
            cout << "Empty\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ArrayManager manager;
    int choice, value, pos;

    while (true)
    {
        cout << "\n--- Array Manager Menu ---\n";
        cout << "1. Insert at end\n2. Insert at position\n3. Remove from end\n";
        cout << "4. Remove from position\n5. Search element\n";
        cout << "6. Edit element\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            manager.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            manager.insertAtPosition(value, pos);
            break;
        case 3:
            manager.removeFromEnd();
            break;
        case 4:
            cout << "Enter position to remove: ";
            cin >> pos;
            manager.removeFromPosition(pos);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            manager.searchElement(value);
            break;
        case 6:
            cout << "Enter position and new value: ";
            cin >> pos >> value;
            manager.editElement(pos, value);
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
