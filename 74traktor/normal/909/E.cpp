#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
vector < int > g[maxn];
set < int > G[maxn];
int a[maxn];
set < pair < int, int > > Q[2];

void dfs(int x) {
    while ((int)Q[x].size() > 0) {
        auto p = (*Q[x].begin());
        if (p.first != 0) return;
        Q[x].erase(p);
        for (auto u : g[p.second]) {
            Q[a[u]].erase({(int)G[u].size(), u});
            G[u].erase(p.second);
            Q[a[u]].insert({(int)G[u].size(), u});
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[v].push_back(u);
        G[u].insert(v);
    }
    for (int i = 0; i < n; ++i) {
        Q[a[i]].insert({(int)G[i].size(), i});
    }
    while ((int)Q[1].size() > 0) {
        dfs(0);
        dfs(1);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}