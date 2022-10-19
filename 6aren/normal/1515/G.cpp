#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n), radj(n);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].emplace_back(v, c);
        radj[v].emplace_back(u, c);
    }
    vector<int> orders;
    vector<bool> visited(n, false);

    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (auto e : adj[u]) {
            int to = e.first;
            if (!visited[to])
                dfs(to);
        }
        orders.push_back(u);
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) 
            dfs(i);
    }
    vector<int> comp(n, -1);
    int cc = -1;

    function<void(int)> rdfs = [&](int u) {
        comp[u] = cc;
        for (auto e : radj[u]) {
            int to = e.first;
            if (comp[to] == -1)
                rdfs(to);
        }
    };

    vector<long long> dist(n, -1);
    vector<long long> gcd;

    for (int i = orders.size() - 1; i >= 0; i--) {
        int u = orders[i];
        if (comp[u] == -1) {
            ++cc;
            rdfs(u);
            vector<int> bfs(1, u);
            dist[u] = 0;
            for (size_t j = 0; j < bfs.size(); j++) {
                int v = bfs[j];
                for (auto e : adj[v]) {
                    int to = e.first;
                    if (comp[to] != cc || dist[to] != -1)
                        continue;
                    dist[to] = dist[v] + e.second;
                    bfs.push_back(to);
                }
            }
            long long GCD = 0;
            for (size_t j = 0; j < bfs.size(); j++) {
                int v = bfs[j];
                for (auto e : adj[v]) {
                    if (comp[e.first] != cc) 
                        continue;
                    GCD = __gcd(GCD, dist[v] + e.second - dist[e.first]);
                }
            }
            gcd.push_back(GCD);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int v, s, t;
        cin >> v >> s >> t;
        v--;
        bool condition = s % __gcd(gcd[comp[v]], (long long) t) == 0;
        cout << (condition ? "YES\n" : "NO\n");
    }

    return 0;
}