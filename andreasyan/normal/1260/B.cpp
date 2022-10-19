#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;
        if ((2 * b - a) % 3 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        long long x = (2 * b - a) / 3;
        long long y = (b - 2 * x);
        if (x < 0 || y < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}