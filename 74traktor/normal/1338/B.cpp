#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int dp[maxn][2], check = 1, h[maxn];
vector < int > g[maxn];
int was[maxn][2];

void dfs(int v, int p) {
    h[v] = h[p] + 1;
    int cnt = 0;
    int ok = 0, oks = 0;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            if ((int)g[u].size() > 1 || !ok) cnt++;
            if ((int)g[u].size() == 1) ok = 1;
            for (int j = 0; j <= 1; ++j) was[v][j] = (was[v][j]|was[u][j]);
        }
    }
    dp[v][1] = cnt;
    for (auto u : g[v]) if (u != p) dp[v][1] += dp[u][1];
    if ((int)g[v].size() == 1) was[v][h[v] % 2] = 1;
    if ((was[v][0]&was[v][1])) check = 0;
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
    for (int i = 1; i <= n; ++i) {
        if ((int)g[i].size() > 1) v = i;
    }
    dfs(v, 0);
    if (check) dp[v][0] = 1;
    else dp[v][0] = 3;
    cout << dp[v][0] << " " << dp[v][1] << '\n';
    return 0;
}