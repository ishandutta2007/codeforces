#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn];
int dp[maxn], cnt[2][maxn];
vector < int > g[maxn];

void dfs(int v, int p, int imin) {
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, min(imin, a[v]));
            dp[v] += dp[u];
            for (int j = 0; j <= 1; ++j) cnt[j][v] += cnt[j][u];
        }
    }
    if (c[v] != b[v]) cnt[b[v]][v]++;
    if (a[v] < imin) {
        dp[v] += min(cnt[0][v], cnt[1][v]) * a[v] * 2;
        int val = min(cnt[0][v], cnt[1][v]);
        cnt[0][v] -= val, cnt[1][v] -= val;
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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, a[1] + 1);
    if (cnt[0][1] + cnt[1][1] > 0) cout << -1;
    else cout << dp[1];
    return 0;
}