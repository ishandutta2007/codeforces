#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], cmp[maxn];
vector < int > g[maxn];
set < int > in[maxn];
int ans;

void dfs(int v, int p, int cur) {
    cur ^= a[v];
    cmp[v] = v;
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v, cur);
        if (in[cmp[u]].size() > in[cmp[v]].size()) cmp[v] = cmp[u];
    }
    int flag = 1;
    for (auto u : g[v]) {
        if (u == p || cmp[u] == cmp[v]) continue;
        for (auto key : in[cmp[u]]) {
            if (in[cmp[v]].find((key^a[v])) != in[cmp[v]].end()) flag = 0;
        }
        for (auto key : in[cmp[u]]) in[cmp[v]].insert(key);
    }
    if (in[cmp[v]].find((cur^a[v])) != in[cmp[v]].end()) flag = 0;
    in[cmp[v]].insert(cur);
    if (!flag) ans++, in[cmp[v]] = {};
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}