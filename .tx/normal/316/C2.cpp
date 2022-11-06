#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

namespace MC {
    using F = int;
    using W = int;

    const int N = int(1e4);

    const int INF = numeric_limits<W>::max() / 2;
    const int FINF = numeric_limits<F>::max();

    struct edge {
        int to;
        F f, c;
        W w;
    };

    vector<edge> es;
    vector<int> g[N];
    W d[N];
    int par[N];
    int vis[N];
    int vt = 0;
    F tf[N];

    void add_edge(int from, int to, F cap, W w) {
        g[from].push_back(int(es.size()));
        es.push_back({to, 0, cap, w});
        g[to].push_back(int(es.size()));
        es.push_back({from, 0, 0, -w});
    }

    void fb(int s, int n) {
        fill_n(d, n, INF);
        d[s] = 0;
        vector<int> q(n + 1);
        vector<int> in_q(n);
        bool change = true;
        for (int it = 0; it + 1 < n && change; it++) {
            change = false;
            int qh = 0, qt = 0;
            q[qt++] = s;
            in_q[s] = 1;
            while (qh != qt) {
                int v = q[qh++];
                if (qh == n + 1) {
                    qh = 0;
                }
                in_q[v] = 0;
                for (int i : g[v]) {
                    edge& e = es[i];
                    if (e.f != e.c && d[e.to] > d[v] + e.w) {
                        d[e.to] = d[v] + e.w;
                        if (!in_q[e.to]) {
                            q[qt++] = e.to;
                            if (qt == n + 1) {
                                qt = 0;
                            }
                            in_q[e.to] = 1;
                        }
                        change = true;
                    }
                }
            }
        }
        assert(!change);
    }

//    void dij(int s, int n) {
//        fill_n(d, n, INF);
//        fill_n(par, n, -1);
//        d[s] = 0;
//        tf[s] = numeric_limits<F>::max();
//        priority_queue<pair<int, int>> q;
//        q.push({0, s});
//        while (!q.empty()) {
//            auto [vd, v] = q.top();
//            q.pop();
//            if (d[v] != -vd) {
//                continue;
//            }
//            for (int i : g[v]) {
//                edge& e = es[i];
//                if (e.f != e.c && d[e.to] > d[v] + e.w + phi[v] - phi[e.to]) {
//                    d[e.to] = d[v] + e.w + phi[v] - phi[e.to];
//                    tf[e.to] = min(tf[v], e.c - e.f);
//                    par[e.to] = i;
//                    q.push({-d[e.to], e.to});
//                }
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            phi[i] += d[i];
//        }
//    }

    int find_flow(int v, int t, F f) {
        if (v == t || !f) {
            return f;
        }
        vis[v] = vt;
        F cf = f;
        for (int i : g[v]) {
            edge& e = es[i];
            if (v == 3 && e.to == 7) {
                v++;
                v -= 1;
            }
            if (e.f != e.c && vis[e.to] != vt && d[e.to] == d[v] + e.w) {
                F rf = find_flow(e.to, t, min(cf, e.c - e.f));
                if (rf) {
                    cf -= rf;
                    es[i].f += rf;
                    es[i ^ 1].f -= rf;
                }
            }
        }
        return f - cf;
    }

    bool modify_d(int n) {
        W mn = INF;
        for (int v = 0; v < n; v++) {
            if (vis[v] == vt) {
                for (int i : g[v]) {
                    edge &e = es[i];
                    if (vis[e.to] != vt && e.f != e.c) {
                        mn = min(mn, d[v] + e.w - d[e.to]);
                    }
                }
            }
        }
        if (mn == INF) {
            return false;
        }
        for (int v = 0; v < n; v++) {
            if (vis[v] != vt) {
                d[v] += mn;
            }
        }
        return true;
    }

    pair<F, W> flow(int s, int t, int n = N) {
        fb(s, n);

        F f = 0;
        W w = 0;

        do {
            F cf;
            while (vt++, cf = find_flow(s, t, FINF)) {
                f += cf;
                w += d[t] * cf;
            }
        } while (modify_d(n));

        return {f, w};
    }
}

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    using namespace MC;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    for (int i = 0; i < n; i++) {
        for (int j = i & 1; j < m; j += 2) {
            for (int t = 0; t < 4; t++) {
                int x = i + dx[t];
                int y = j + dy[t];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    continue;
                }
                add_edge(i * m + j, x * m + y, 1, a[i][j] != a[x][y]);
            }
            add_edge(n * m, i * m + j, 1, 0);
        }
        for (int j = 1 - (i & 1); j < m; j += 2) {
            add_edge(i * m + j, n * m + 1, 1, 0);
        }
    }

    auto [f, w] = flow(n * m, n * m + 1, n * m + 2);
    assert(f == n * m / 2);

//    for (int i = 0; i < isz(es); i++) {
//        int f = es[i ^ 1].to;
//        int t = es[i].to;
//
//        if (es[i].f == 1) {
//            cout << f / m << " " << f % m << " - " << t / m << " " << t % m << " | " << es[i].w << "\n";
//        }
//    }

    cout << w << "\n";

    return 0;
}