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

const int N = 1e5 + 10;
int a[N], p[N], n, vis[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> p[a[i]], vis[i] = 0;
        int d = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
            {
                int x = i, cnt = 0;
                while (!vis[x])
                {
                    vis[x] = 1;
                    cnt++;
                    x = p[x];
                }
                d += cnt / 2;
            }
        ll res = 0;
        for (int i = 1; i <= d; ++i)
            res += ((n - i + 1) - i) * 2;
        cout << res << "\n";
    }
    return 0;
}