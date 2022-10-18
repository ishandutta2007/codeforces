#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
vector < pair < int, int > > g[maxn];
int sz[maxn];
int dp[maxn];
int inf = 1e18, ans, k;

void dfs(int v, int p) {
    dp[v] = 0;
    sz[v] = 1;
    int sum = 0;
    for (auto u : g[v]) {
        int to = u.first;
        if (to == p) continue;
        dfs(to, v);
        ans += min(sz[to], 2 * k - sz[to]) * u.second;
        if (sz[to] % 2 == 1) {
            sum += u.second;
        }
        sz[v] += sz[to], dp[v] += dp[to];
    }
    dp[v] += sum;
}

void solve() {
    int u, v, t;
    cin >> k;
    for (int i = 1; i <= 2 * k; ++i) g[i] = {};
    for (int i = 1; i < 2 * k; ++i) {
        cin >> u >> v >> t;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }
    ans = 0;
    dfs(1, 0);
    cout << dp[1] << " " << ans << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}