#include <bits/stdc++.h>

using namespace std;

#ifdef GAREN
#include <cp-template/debugger.hpp>
#else
#define debug(...) 42
#endif

void run_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> visited(n), dep(n);
    vector<vector<int>> p(n, vector<int>(20));
    function<void(int)> build_tree = [&](int u) {
        visited[u] = true;
        for (int e : g[u]) {
            if (!visited[e]) {
                p[e][0] = u;
                dep[e] = dep[u] + 1;
                build_tree(e); 
            }
        }
    };

    build_tree(0);

    p[0][0] = -1;


    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            p[j][i] = (p[j][i - 1] == -1 ? -1 : p[p[j][i - 1]][i - 1]);
        }
    }

    auto lca = [&](int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 19; i >= 0; i--) {
            if (dep[v] - (1 << i) >= dep[u]) v = p[v][i];
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; i--) {
            if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i]; 
        }
        return p[u][0];
    };

    auto path = [&](int u, int v) {
        int _lca = lca(u, v);
        vector<int> res_u, res_v;
        while (u != _lca) {
            res_u.push_back(u);
            u = p[u][0];
        }
        while (v != _lca) {
            res_v.push_back(v);
            v = p[v][0];
        }
        vector<int> res;
        for (int e : res_u) res.push_back(e);
        res.push_back(_lca);
        reverse(res_v.begin(), res_v.end());
        for (int e : res_v) res.push_back(e);
        return res;
    };

    int q;
    cin >> q;
    vector<int> deg(n);
    vector<vector<int>> res;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        auto foo = path(u, v);
        res.push_back(foo);
        deg[u]++, deg[v]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += deg[i] % 2;
    if (cnt) {
        cout << "NO\n";
        cout << cnt / 2 << '\n';
    } else {
        cout << "YES\n";
        for (auto v : res) {
            cout << v.size() << '\n';
            for (int e : v) cout << e + 1 << ' ';
            cout << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    for (int test = 1; test <= tests; test++) run_case(test);
    return 0;
}