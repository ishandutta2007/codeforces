#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn];
vector < int > g[maxn];
int dp[maxn][3][2];
int inf = 1e18;

void dfs(int v, int p) {
    for (int j = 0; j <= 2; ++j) {
        for (int i = 0; i <= 1; ++i) {
            dp[v][j][i] = -inf;
        }
    }
    dp[v][1][1] = a[v];
    dp[v][0][0] = 0;
    int mx1 = 0, mx2 = 0;
    multiset < int > one, two;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            one.insert(dp[u][1][1]);
            two.insert(dp[u][1][0]);
            dp[v][1][0] = max(dp[v][1][0], dp[u][1][0]);
            dp[v][1][1] = max(dp[v][1][1], dp[u][1][1] + a[v]);
            dp[v][2][0] = max(dp[v][2][0], dp[u][2][0]);
            dp[v][2][1] = max(dp[v][2][1], dp[u][2][1] + a[v]);
            if (dp[u][1][0] > mx1) mx2 = mx1, mx1 = dp[u][1][0];
            else if (dp[u][1][0] > mx2) mx2 = dp[u][1][0];
        }
    }
    dp[v][2][0] = max(dp[v][2][0], mx1 + mx2);
    for (auto u : g[v]) {
        if (u == p) continue;
        if ((int)one.size() > 1) {
            one.erase(one.find(dp[u][1][1]));
            dp[v][1][0] = max(dp[v][1][0], dp[u][1][1] + (*one.rbegin()) + a[v]);
            dp[v][2][0] = max(dp[v][2][0], dp[u][2][1] + (*one.rbegin()) + a[v]);
            one.insert(dp[u][1][1]);
        }
    }
    for (auto u : g[v]) {
        if (u == p) continue;
        if ((int)two.size() > 1) {
            two.erase(two.find(dp[u][1][0]));
            dp[v][2][1] = max(dp[v][2][1], dp[u][1][1] + a[v] + (*two.rbegin()));
            two.insert(dp[u][1][0]);
        }
    }
    for (auto u : g[v]) {
        if (u == p) continue;
        if ((int)one.size() > 2) {
            one.erase(one.find(dp[u][1][1]));
            int s = a[v];
            vector < int > add;
            for (int j = 1; j <= 2; ++j) {
                s += (*one.rbegin());
                add.push_back((*one.rbegin()));
                one.erase(one.find(add.back()));
            }
            for (auto elem : add) one.insert(elem);
            dp[v][2][0] = max(dp[v][2][0], dp[u][1][0] + s);
            one.insert(dp[u][1][1]);
        }
    }
    for (int i = 0; i <= 2; ++i) dp[v][i][0] = max(dp[v][i][0], dp[v][i][1]);
    for (int i = 1; i <= 2; ++i) {
        for (int j = 0; j <= 1; ++j) dp[v][i][j] = max(dp[v][i][j], dp[v][i - 1][j]);
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
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 0; i <= 2; ++i) ans = max({ans, dp[1][i][0], dp[1][i][1]});
    cout << ans << '\n';
    return 0;
}