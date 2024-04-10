#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 5e5 + 5;
vector < pair < int, int > > g[maxn];
int dp[maxn][2];
int k;

void dfs(int v, int p) {
    dp[v][0] = 0, dp[v][1] = 0;
    int child = 0;
    for (auto u : g[v]) {
        if (u.first != p) {
            dfs(u.first, v);
            child++;
        }
    }
    if (child != 0) {
        vector < pair < int, int > > sorted;
        for (auto u : g[v]) {
            if (u.first != p) {
                int to = u.first;
                int x1 = dp[to][0] + u.second, x2 = dp[to][1];
                sorted.push_back({x1 - max(dp[to][0], dp[to][1]), max(dp[to][0], dp[to][1])});
            }
        }
        sort(sorted.begin(), sorted.end());
        reverse(sorted.begin(), sorted.end());
        for (int i = 0; i < (int)sorted.size(); ++i) {
            if (i < k) dp[v][1] += (sorted[i].first + sorted[i].second);
            else dp[v][1] += sorted[i].second;
            if (i < k - 1) dp[v][0] += max((sorted[i].first + sorted[i].second), sorted[i].second);
            else dp[v][0] += sorted[i].second;
        }
    }
}

void solve() {
    int n, u, v, w;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i] = {};
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}