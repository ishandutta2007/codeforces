/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    int n, h;
    cin >> n >> h;
    double S = h/(double)2 / (double) n;
    double cur = 0;
    double p = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double l = cur, r = h;
        int it = 60;
        while (it--)
        {
            double m = (l + r) / 2;
            double len = m / h;
            if (((p + len) / 2) * (m - cur) <= S)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        cur = l;
        p = cur / h;
        cout << fixed << setprecision(20) << cur << ' ';
    }
}