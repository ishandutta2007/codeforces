#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const maxn = 3005;
vector < int > g[maxn];
ll dp[maxn][maxn];
int sz[maxn][maxn], ptr[maxn], used[maxn], lst[maxn][maxn], where[maxn][maxn];
vector < pair < int, int > > go[maxn];

void dfs(int s, int v, int p) {
    sz[s][v] = 1;
    for (auto u : g[v]) {
        if (u == p) continue;
        if (p == 0) where[s][u] = u;
        else where[s][u] = where[s][v];
        dfs(s, u, v);
        sz[s][v] += sz[s][u];
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) dfs(i, i, 0);
    for (int i = 1; i <= n; ++i) {
        for (auto to : g[i]) dp[i][to] = min(sz[1][i], sz[1][to]) * (n - min(sz[1][i], sz[1][to]));
    }
    for (int i = 1; i <= n; ++i) {
        go[i].push_back({i, 0});
        used[i] = i;
        int head = 0;
        while (head != n) {
            auto tmp = go[i][head++];
            for (auto u : g[tmp.first]) {
                if (used[u] != i) {
                    used[u] = i;
                    lst[i][u] = tmp.first;
                    go[i].push_back({u, tmp.second + 1});
                }
            }
        }
        while (ptr[i] < n && go[i][ptr[i]].second < 2) ptr[i]++;
    }
    for (int dist = 2; dist <= n; ++dist) {
         for (int i = 1; i <= n; ++i) {
            while (ptr[i] < n && go[i][ptr[i]].second <= dist) {
                v = i, u = go[i][ptr[i]].first;
                dp[v][u] = max(dp[v][lst[v][u]] + (ll)sz[v][u] * (ll)(n - sz[v][where[v][u]]), dp[lst[u][v]][u] + (ll)sz[u][v] * (ll)(n - sz[u][where[u][v]]));
                ptr[i]++;
            }
         }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) ans = max(ans, dp[i][j]);
    }
    cout << ans << '\n';
    return 0;
}