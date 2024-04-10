#include <bits/stdc++.h>
using namespace std;

bool c[10];

bool stg(int x)
{
    memset(c, false, sizeof c);
    while (x)
    {
        if (c[x % 10])
            return false;
        c[x % 10] = true;
        x /= 10;
    }
    return true;
}

int main()
{
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i)
    {
        if (stg(i))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}