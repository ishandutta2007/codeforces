#include <bits/stdc++.h>

using namespace std;

int n, m, q;

template <class T> T reduce(std::vector<T>& b, T x) {
    for (auto& t : b) {
        x = std::min(x, x ^ t);
    }

    return x;
}

template <class T> bool add(std::vector<T>& b, T x) {
    if (!(x = reduce(b, x))) return false;

    int ind = 0;
    while (ind < int(b.size()) && b[ind] > x) ind++;
    b.insert(b.begin() + ind, x);

    return true;
}

struct DSURollBack {
    vector<int> e;
    // stores the distance to 0
    vector<int> dist;
    vector<int> basis;
    
    void init(int n) {
        e = vector<int>(n, -1);
        dist = vector<int>(n, 0);
    }
    
    int get(int x) {
        return e[x] < 0 ? x : get(e[x]);
    }
    
    bool same_set(int a, int b) {
        return get(a) == get(b);
    }
    
    int size(int x) {
        return -e[get(x)];
    }
    
    vector<array<int, 6>> mod;
    vector<int> basis_mod;
    
    int root_dist(int u) {
        int res = 0;

        while (e[u] >= 0) {
            res ^= dist[u];
            u = e[u];
        }

        return res;
    }
    
    int path(int u, int v) {
        return root_dist(u) ^ root_dist(v);
    }
    
    bool unite(int x, int y, int d) {
        int ox = x;
        int oy = y;

        x = get(x), y = get(y);

        if (x == y) {
            mod.push_back({-1, -1, -1, -1, -1, -1});

            int val = d ^ path(ox, oy);
            int nxt = reduce(basis, val);

            if (add(basis, val)) {
                basis_mod.push_back(nxt);
            } else {
                basis_mod.push_back(-1);
            }

            return false;
        }

        if (e[x] > e[y]) swap(x, y), swap(ox, oy);

        mod.push_back({x, y, e[x], e[y], dist[x], dist[y]});
        basis_mod.push_back(-1);

        dist[y] = root_dist(ox) ^ root_dist(oy) ^ d;
        e[x] += e[y], e[y] = x;
        return true;
    }
    
    void rollback() {
        auto a = mod.back();
        auto b = basis_mod.back();

        mod.pop_back();
        basis_mod.pop_back();

        if (a[0] != -1) {
            e[a[0]] = a[2];
            e[a[1]] = a[3];
            dist[a[0]] = a[4];
            dist[a[1]] = a[5];
        }

        if (b != -1) {
            basis.erase(find(basis.begin(), basis.end(), b));
        }
    }
};

struct OfflineDynamicConnectivity {
    DSURollBack D;
    
    int sz;
    
    vector<vector<array<int, 3>>> seg;
    vector<vector<pair<int, int>>> queries;
    vector<int> ans;
    
    void upd(int l, int r, int u, int v, int w) {
        // add edge p from time [l, r]
        for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) seg[l++].push_back({u, v, w});
            if (r & 1) seg[--r].push_back({u, v, w});
        }
    }

    void process(int ind) {
        for (auto& t : seg[ind]) {
            D.unite(t[0], t[1], t[2]);
        }
        if (ind >= sz) {
            // Process the queries at time ti
            // Do stuff with D
            int ti = ind - sz; 
            for (auto& qq : queries[ti]) {
                int u = qq.first;
                int v = qq.second; 
                int path = D.path(u, v);
                ans.push_back(reduce(D.basis, path));
            }
        } else {
            process(2 * ind); process(2 * ind + 1);
        }
        for (auto& t : seg[ind]) {
            D.rollback();
        }
    }

    void add_query(int ti, int u, int v) {
        queries[ti].emplace_back(u, v);
    }

    void init(int max_time) {
        sz = 1;
        while (sz < max_time) sz *= 2;
        seg.assign(2 * sz, {});
        queries.assign(sz, {});
        D.init(2 * sz);
    }

    vector<int> solve() {
        process(1);
        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    vector<array<int, 4>> queries;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;

        queries.push_back({1, u, v, w});
    }

    cin >> q;

    for (int i = 0; i < q; i++ ) {
        int type; cin >> type;
        if (type == 1) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;

            queries.push_back({1, u, v, w});
        } else if (type == 2) {
            int u, v; cin >> u >> v;
            u--, v--;

            queries.push_back({2, u, v, -1});
        } else {
            int u, v; cin >> u >> v; 
            u--, v--;

            queries.push_back({3, u, v, -1});
        }
    }

    OfflineDynamicConnectivity O;

    O.init(n + m + q + 1);

    set<array<int, 3>> edges;

    map<pair<int, int>, int> weight;

    for (int i = 0; i < m + q; i++) {
        int type = queries[i][0];

        if (type == 1) {
            int u = queries[i][1];
            int v = queries[i][2];
            int w = queries[i][3];

            edges.insert({u, v, i});

            weight[{u, v}] = w;

        } else if (type == 2) {
            int u = queries[i][1];
            int v = queries[i][2];

            auto e = *edges.lower_bound({u, v, -1});

            O.upd(e[2], i, u, v, weight[{u, v}]);

            edges.erase(e);

        } else {
            int u = queries[i][1];
            int v = queries[i][2];

            O.add_query(i, u, v);

        }
    }

    for (auto e : edges) {
        O.upd(e[2], m + q, e[0], e[1], weight[{e[0], e[1]}]);
    }

    auto ans = O.solve();

    for (auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}