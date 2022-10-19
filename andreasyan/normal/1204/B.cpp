#include <bits/stdc++.h>
using namespace std;

int n, l, r;

int main()
{
    cin >> n >> l >> r;
    int maxu = 0;
    int u = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i < r)
        {
            maxu += u;
            u *= 2;
        }
        else
        {
            maxu += u;
        }
    }
    int minu = 0;
    u = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i < (n - l + 1))
        {
            minu += u;
        }
        else
        {
            minu += u;
            u *= 2;
        }
    }
    cout << minu << ' ' << maxu << endl;
    return 0;
}