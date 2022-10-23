#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e6 + 10;
int a[N], ps[N], n, best[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, g = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i], ps[i] = 0;
        for (int i = 1, x; i <= m; ++i) cin >> x, g = __gcd(g, x);
        ll res = 0;
        for (int i = 1; i <= n; ++i) res += abs(a[i]);
        if (g == 1)
        {
            cout << res << "\n";
            continue;
        }
        int par = 0;
        for (int i = 1; i <= n - g; ++i)
        {
            par ^= ps[i];
            if (par) a[i] *= -1;
            if (a[i] < 0)
            {
                ps[i] ^= 1;
                par ^= 1;
                a[i] *= -1;
                ps[i + g] ^= 1;
            }
        }
        for (int i = n - g + 1; i <= n; ++i)
        {
            par ^= ps[i];
            if (par) a[i] *= -1;
        }
        for (int i = 0; i < g; ++i) best[i] = 1e9;
        for (int i = 1; i <= n; ++i) best[i % g] = min(best[i % g], abs(a[i]));
        ll sum1 = 0, sum2 = 0;
        for (int i = n - g + 1; i <= n; ++i)
            if (a[i] > 0) sum1 += best[i % g];
            else if (a[i] < 0) sum2 += best[i % g];
        cout << res - 2 * min(sum1, sum2) << "\n";
    }
    return 0;
}