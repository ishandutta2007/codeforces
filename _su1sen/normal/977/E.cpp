#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    vector<int> stack;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<int> con;
        stack.push_back(i);
        vis[i] = true;
        while (stack.size()) {
            int u = stack.back();
            stack.pop_back();
            con.push_back(u);
            for (int v : g[u]) {
                if (!vis[v]) {
                    stack.push_back(v);
                    vis[v] = true;
                }
            }
        }
        bool ok = true;
        for (int v : con) ok &= g[v].size() == 2;
        ans += ok;
    }
    cout << ans << '\n';
    return 0;
}