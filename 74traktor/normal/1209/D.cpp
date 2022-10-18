#include <bits/stdc++.h>

using namespace std;

vector < int > g[100005];
int used[100005];
int cur;

void dfs(int v) {
    used[v] = 1;
    cur++;
    for (auto u : g[v]) if (used[u] == 0) dfs(u);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            cur = 0;
            dfs(i);
            ans += (cur - 1);
        }
    }
    cout << m - ans << '\n';
    return 0;
}