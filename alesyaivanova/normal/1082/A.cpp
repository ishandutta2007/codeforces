#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        int w = abs(x - y);
        if (y == 1 || y == n)
            cout << (w + d - 1) / d;
        else if (w % d == 0)
            cout << w / d;
        else
        {
            int k1 = -1;
            int k2 = -1;
            if (y % d == 1)
                k1 = (x - 1 + d - 1) / d + y / d;
            if ((n - y) % d == 0)
                k2 = ((n - x) + d - 1) / d + (n - y) / d;
            if (k1 == -1)
                cout << k2;
            else if (k2 == -1)
                cout << k1;
            else
                cout << min(k1, k2);
        }
        cout << "\n";
    }
}