#include <bits/stdc++.h>

using namespace std;

bool fi[2][100];

int main()
{
    int n, k;
    cin >> n >> k;
    if (k > (n - 2) * 2)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int i = 0;
    while (k > 1 && i < (n - 2) / 2)
    {
        fi[0][i] = true;;
        fi[0][n - 3 - i] = true;
        k -= 2;
        i++;
    }
    if (k > 0)
    {
        fi[0][(n - 2) / 2] = true;
        k--;
    }
    i = 0;
    while (k > 1 && i < (n - 2) / 2)
    {
        fi[1][i] = true;;
        fi[1][n - 3 - i] = true;
        k -= 2;
        i++;
    }
    if (k > 0)
    {
        fi[1][(n - 2) / 2] = true;
        k--;
    }
    for (int i = 0; i < n; i++)
        cout << '.';
    cout << "\n.";
    for (int i = 0; i < n - 2; i++)
    {
        if (fi[0][i])
            cout << '#';
        else
            cout << '.';
    }
    cout << ".\n.";
    for (int i = 0; i < n - 2; i++)
    {
        if (fi[1][i])
            cout << '#';
        else
            cout << '.';
    }
    cout << ".\n";
    for (int i = 0; i < n; i++)
        cout << '.';
}