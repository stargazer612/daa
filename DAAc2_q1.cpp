#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int> > &arr, int sRow, int eRow, int sColumn, int eColumn, int key) {
    // If the value of the key less than minimum value or greater than the maximum value in the matrix 
    // key cannot be in the matrix 
    if(key < arr[sRow][sColumn] or key >arr[eRow][eColumn])
    {
        return false;
    }
    // If this is a single element in the matrix 
    if (sRow == eRow and sColumn == eColumn) {
        if (key == arr[sRow][sColumn]) {
            cout << key << " Found at (" << sRow << "," << sColumn << ")" << endl;
            return true;
        } else {
            return false;
        }

    }
    int midRow = (sRow + eRow) / 2;
    int midColumn = (sColumn + eColumn) / 2;
    // If the middle element is equal to the key 
    if (arr[midRow][midColumn] == key) {
        cout << key << " Found at (" << midRow << "," << midColumn << ")" << endl;
        return true;
    } else if (key < arr[midRow][midColumn]) {
        bool a = false, b = false;
        if (midRow - 1 >= sRow) {
            a = search(arr, sRow, midRow - 1, midColumn, eColumn, key);
        }
        if (midColumn - 1 >= sColumn) {
            b = search(arr, sRow, eRow, sColumn, midColumn - 1, key);
        }

        return (a or b);
    } else // if key is greater than middle element 
    {
        bool a = false, b = false;
        //  If midColumn+1 does not exceed the number of Columns in the matrix 
        if (midColumn + 1 <= eColumn) {
            a = search(arr, sRow, midRow, midColumn + 1, eColumn, key);
        }
        // If midRow+1 does not exceed the number of row in the matrix 
        if (midRow + 1 <= eRow) {
            b = search(arr, midRow + 1, eRow, sColumn, eColumn, key);
        }
        // If the we can get key from any of the two calls return true
        return (a or b);
    }

}

int main() {
    
    int n=10; 
    //cout<<"Enter the value of n \n"; cin>>n
    vector<vector<int>> arr;
    arr.resize(n,vector<int>(n));

    int count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cin>>arr[i][j];
            arr[i][j] = count;
            count++;
        }
    }
    cout<<"The Given Matrix is\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<arr[i][j]<< " ";
            
        }
        cout << endl;
    }
    int key = 79; 
    cout<<"Enter the value of key \n"; cin>>key;

    if (search(arr, 0, n - 1, 0, n - 1, key) == false) {
                cout << key << " Not Found\n";
    }

    // checking code for every element in the matrix
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (search(arr, 0, n - 1, 0, n - 1, arr[i][j]) == false) {
    //             cout << arr[i][j] << " Not Found\n";
    //         }
    //     }
    // }

}