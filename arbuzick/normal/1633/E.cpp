#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

struct edge {
    int u, v, w, ind;

    edge() {
        u = v = w = ind = 0;
    }

    edge(int _u, int _v, int _w, int _ind) {
        u = _u, v = _v, w = _w, ind = _ind;
    }

    bool operator<(edge b) {
        return make_pair(w, ind) < make_pair(b.w, b.ind);
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--, edges[i].v--;
        edges[i].ind = i;
    }
    vector<pair<int, int>> add, cnt;
    for (int i = 0; i < m; ++i) {
        auto check = [&](int ind, int x) {
            vector<edge> edges_nw = edges;
            for (auto &e : edges_nw) {
                e.w = abs(e.w - x);
            }
            sort(edges_nw.begin(), edges_nw.end());
            DSU d(n);
            for (auto e : edges_nw) {
                if (e.ind == ind) {
                    return d.unite(e.u, e.v);
                }
                d.unite(e.u, e.v);
            }
            return true;
        };
        if (!check(i, edges[i].w)) {
            continue;
        }
        int l = -1, r = edges[i].w;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(i, m)) {
                r = m;
            } else {
                l = m;
            }
        }
        add.emplace_back(r, edges[i].w);
        add.emplace_back(edges[i].w + 1, -edges[i].w);
        cnt.emplace_back(r, 1);
        cnt.emplace_back(edges[i].w + 1, -1);
        l = edges[i].w, r = inf;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(i, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        add.emplace_back(edges[i].w + 1, -edges[i].w);
        add.emplace_back(r, edges[i].w);
    }
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<int> q(p);
    for (int i = 0; i < p; ++i) {
        cin >> q[i];
    }
    for (int i = p; i < k; ++i) {
        q.push_back((q.back() * 1LL * a + b) % c);
    }
    sort(add.begin(), add.end());
    sort(cnt.begin(), cnt.end());
    sort(q.begin(), q.end());
    int pos_add = 0, pos_cnt = 0, sum_cnt = 0;
    long long ans = 0, sum_add = 0;
    for (auto x : q) {
        while (pos_add != add.size() && add[pos_add].first <= x) {
            sum_add += add[pos_add].second;
            pos_add++;
        }
        while (pos_cnt != cnt.size() && cnt[pos_cnt].first <= x) {
            sum_cnt += cnt[pos_cnt].second;
            pos_cnt++;
        }
        long long ans_nw = sum_add - x * 1LL * sum_cnt + x * 1LL * (n - 1 - sum_cnt);
        ans ^= ans_nw;
    }
    cout << ans << '\n';
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