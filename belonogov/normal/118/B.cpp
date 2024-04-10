#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
            cout << "  ";
        for (j = 0; j <= i; j++)
        {
            if (j)
                cout << " ";
            cout << j;
        }
        for (j = i - 1; j >= 0; j--)
            cout << " " << j;
        cout << "\n";
    }
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < n - i; j++)
            cout << "  ";
        for (j = 0; j <= i; j++)
        {
            if (j)
                cout << " ";
            cout << j;
        }
        for (j = i - 1; j >= 0; j--)
            cout << " " << j;
        cout << "\n";
    }


    return 0;
}