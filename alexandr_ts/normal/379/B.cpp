#include <bits/stdc++.h>

using namespace std;

int a[10000];

main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 300; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] > 0)
            {
                cout << 'P';
                a[j]--;
            }
            if (j == 0)
            {
                cout << "RL";
            }
            if (j == n - 1)
            {
                cout << "LR";
            }
            if (j != n - 1)
                cout << 'R';
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[j] > 0)
            {
                cout << 'P';
                a[j]--;
            }
            if (j == 0)
            {
                cout << "RL";
            }
            if (j == n - 1)
            {
                cout << "LR";
            }
            if (j != 0)
                cout << 'L';
        }
    }
}