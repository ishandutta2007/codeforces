#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()

const int maxn = 2e5 + 9;
int a[maxn];
int b[maxn];
int n, q;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    map<pii, int> m;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int s, t, u;
        cin >> s >> t >> u;
        s--; u--;
        if (m.find(mp(s, t)) != m.end())
        {
            int v = m[mp(s, t)];
            ans -= max(0ll, a[v] - b[v]);
            b[v]--;
            ans += max(0ll, a[v] - b[v]);
            m.erase(mp(s, t));
        }
        if (u == -1)
        {
            cout << ans << "\n";
            continue;
        }
        m[mp(s, t)] = u;
        ans -= max(0ll, a[u] - b[u]);
        b[u]++;
        ans += max(0ll, a[u] - b[u]);
        cout << ans << "\n";
    }
}