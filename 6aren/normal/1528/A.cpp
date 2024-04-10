#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int l[N], r[N];
long long dp[N][2];
vector<int> g[N];

void dfs(int u, int p) {
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u);
        dp[u][0] += max(dp[e][0] + abs(l[u] - l[e]), dp[e][1] + abs(l[u] - r[e]));
        dp[u][1] += max(dp[e][0] + abs(r[u] - l[e]), dp[e][1] + abs(r[u] - r[e]));
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << '\n';
    }

    return 0;
}