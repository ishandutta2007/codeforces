#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 3005;

int n, down[MN][MN], dp[MN][MN], par[MN][MN];
vector<int> a[MN];

void dfs(int cur, int pre, int st) {
    par[st][cur] = pre;
    down[st][cur] = 1;
    for (int nxt : a[cur]) {
        if (nxt == pre) continue;
        dfs(nxt, cur, st);
        down[st][cur] += down[st][nxt];
    }
}

int calc(int u, int v) {
    if (u == v) return 0;
    if (dp[u][v] != -1) return dp[u][v];
    dp[u][v] = down[u][v] * down[v][u] + max(calc(par[v][u], v), calc(u, par[u][v]));
    return dp[u][v];
}

int32_t main() {
    boost();

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dfs(i, 0, i);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, calc(i, j));
        }
    }
    printf("%lld\n", ans);

    return 0;
}