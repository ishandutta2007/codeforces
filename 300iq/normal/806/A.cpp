/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cl(int a, int b)
{
    return (a / b) + bool(a % b);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (p == 0)
        {
            if (x == 0)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
            continue;
        }
        int k = max(cl(x, p), cl(y, q));
        if (k * (ll) p - x <= k * (ll) q - y)
        {
            cout << k * (ll) q - y << '\n';
        }
        else
        {
            int l = k, r = 1e9 + 7;
            bool good = false;
            while (l < r - 1)
            {
                int m = (l + r) / 2;
                if (m * (ll) p - x <= m * (ll) q - y)
                {
                    r = m;
                    good = true;
                }
                else
                {
                    l = m;
                }
            }
            if (good)
            {
                cout << r * (ll) q - y << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }
}