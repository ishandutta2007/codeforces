#include <bits/stdc++.h>

using namespace std;

int a[10000];

main()
{
    int n;
    cin >> n;
    int qua1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        qua1 += a[i];
    }
    int maxbalance = -11110;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int balance = 0;
            for (int k = i; k <= j; k++)
                if (a[k] == 0)
                    balance++;
                else
                    balance--;
            maxbalance = max(maxbalance, balance);
        }
    cout << qua1 + maxbalance;
}