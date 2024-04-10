#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
vector<int> g[100];

int dfs(int v, int p, int dep) {
    int ret = dep;
    for(int to : g[v])
        if(to != p)
            ret = max(ret, dfs(to, v, dep + 1));
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        for(int i = 0; i < m; i++) g[i].clear();
        for(int i = 0; i < m - 1; i++) {
            int u, v; cin >> u >> v; --u; --v;
            g[u].push_back(v); g[v].push_back(u);
        }
        int hi = 0;
        for(int j = 0; j < m; j++)
            hi = max(hi, dfs(j, -1, 0));
        ret += hi;
    }
    cout << ret;
}