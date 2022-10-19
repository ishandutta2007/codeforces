#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

vector<int> g[maxn];

int cmp[maxn];

struct edge {
    int u, v, w;

    edge() {
        u = v = w = 0;
    }

    edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }

    bool operator<(edge b) {
        return w < b.w;
    }

    bool operator==(edge b) {
        return u == b.u && v == b.v && w == b.w;
    }
};

struct DSU {
    int n;
    vector<int> h, p;

    DSU() {
        n = 0;
    }

    DSU(int _n) {
        n = _n;
        h.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int pr(int v) {
        if (p[v] == v) {
            return v;
        }
        return p[v] = pr(p[v]);
    }

    bool unite(int a, int b) {
        a = pr(a), b = pr(b);
        if (a == b) {
            return false;
        }
        if (h[a] > h[b]) {
            p[b] = a;
        } else if (h[a] < h[b]) {
            p[a] = b;
        } else {
            p[b] = a, h[a]++;
        }
        return true;
    }
};

set<int> s;

void dfs(int v, int c) {
    cmp[v] = c;
    s.erase(v);
    for (int i = 0; i + 1 < (int)g[v].size(); ++i) {
        while (true) {
            auto it = s.upper_bound(g[v][i]);
            if (it != s.end() && *it < g[v][i + 1]) {
                dfs(*it, c);
            } else {
                break;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n * 1LL * (n - 1) / 2 - m > n - 1) {
        vector<edge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].u--, edges[i].v--;
            g[edges[i].u].push_back(edges[i].v);
            g[edges[i].v].push_back(edges[i].u);
        }
        for (int i = 0; i < n; ++i) {
            s.insert(i);
            g[i].push_back(-1);
            g[i].push_back(n);
            sort(g[i].begin(), g[i].end());
        }
        for (int i = 0; i < n; ++i) {
            if (s.count(i)) {
                dfs(i, i);
            }
        }
        DSU d(n);
        for (int i = 0; i < n; ++i) {
            d.unite(i, cmp[i]);
        }
        sort(edges.begin(), edges.end());
        long long ans = 0;
        for (auto e : edges) {
            ans += e.w * 1LL * d.unite(e.u, e.v);
        }
        cout << ans << '\n';
    } else {
        vector<vector<int>> g(n, vector<int>(n));
        vector<edge> edges(m);
        int xr = 0;
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].u--, edges[i].v--;
            g[edges[i].u][edges[i].v] = g[edges[i].v][edges[i].u] = 1;
            xr ^= edges[i].w;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!g[i][j]) {
                    edges.emplace_back(i, j, 0);
                }
            }
        }
        edges.emplace_back(-1, -1, xr);
        sort(edges.begin(), edges.end());
        long long ans = (1LL << 60);
        for (int i = 0; i < (int)edges.size(); ++i) {
            if (edges[i].w != 0) {
                continue;
            }
            DSU d(n);
            long long ans_nw = 0;
            for (auto e : edges) {
                if (e == edges[i]) {
                    continue;
                } else if (e.u == -1) {
                    ans_nw += e.w * 1LL * d.unite(edges[i].u, edges[i].v);
                } else {
                    ans_nw += e.w * 1LL * d.unite(e.u, e.v);
                }
            }
            ans = min(ans, ans_nw);
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}