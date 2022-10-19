#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

struct dsu {
    vector <int> p;
    vector <vector <int>> all_vertex, all_weight;

    dsu(int n) {
        p.resize(n);
        all_vertex.resize(n);
        all_weight.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            all_vertex[i].push_back(i);
        }
    }

    inline void unite(int a, int b, int w) {
        a = p[a];
        b = p[b];
        if ((int)all_vertex[a].size() < (int)all_vertex[b].size()) {
            for (int i : all_vertex[a]) {
                p[i] = b;
                all_vertex[b].push_back(i);
            }
            all_weight[b].push_back(w);
            for (int i : all_weight[a]) {
                all_weight[b].push_back(i);
            }
            all_vertex[a].clear();
            all_weight[a].clear();
        } else {
            for (int i : all_vertex[b]) {
                p[i] = a;
                all_vertex[a].push_back(i);
            }
            all_weight[a].push_back(w);
            for (int i : all_weight[b]) {
                all_weight[a].push_back(i);
            }
            all_vertex[b].clear();
            all_weight[b].clear();
        }
    }

    inline vector <int> get_vertexes() {
        for (auto& i : all_vertex) {
            if (!i.empty()) return i;
        }
    }

    inline vector <int> get_weights() {
        for (auto& i : all_weight) {
            if (!i.empty()) return i;
        }
    }
};

struct SegTreeMax {
    int n;
    vector <int> t;

    void build(int v, int l, int r, vector <int>& w) {
        if (l == r) {
            t[v] = w[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, w);
        build(2 * v + 1, m + 1, r, w);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    SegTreeMax(int n, vector <int>& w) : n(n) {
        t.resize(4 * n);
        build(1, 0, n - 1, w);
    }

    int get_max(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return -1;
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return max(get_max(2 * v, l, m, A, B), get_max(2 * v + 1, m + 1, r, A, B));
    }

    int get_max(int l, int r) {
        return get_max(1, 0, n - 1, l, r);
    }
};

struct SegTree {
    int n;
    vector <int> t_max, t_min, p, t1, t2;

    void build(int v, int l, int r, vector <int>& pos) {
        if (l == r) {
            t_max[v] = pos[l];
            t_min[v] = pos[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, pos);
        build(2 * v + 1, m + 1, r, pos);
        t_max[v] = max(t_max[2 * v], t_max[2 * v + 1]);
        t_min[v] = min(t_min[2 * v], t_min[2 * v + 1]);
    }

    SegTree(int n, vector <int>& pos) : n(n) {
        t1.resize(4 * n);
        t2.resize(4 * n, n);
        p.resize(4 * n, -1);
        t_max.resize(4 * n);
        t_min.resize(4 * n);
        build(1, 0, n - 1, pos);
    }

    inline void push(int v) {
        if (p[v] == -1) return;
        if (p[v] == 0) {
            t1[2 * v] = t1[2 * v + 1] = -1;
            t2[2 * v] = t2[2 * v + 1] = n;
        } else {
            t1[2 * v] = t_max[2 * v];
            t1[2 * v + 1] = t_max[2 * v + 1];
            t2[2 * v] = t_min[2 * v];
            t2[2 * v + 1] = t_min[2 * v + 1];
        }
        p[2 * v] = p[2 * v + 1] = p[v];
        p[v] = -1;
    }

    void update_seg(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            if (x == 0) t1[v] = -1;
            else t1[v] = t_max[v];
            if (x == 0) t2[v] = n;
            else t2[v] = t_min[v];
            p[v] = x;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update_seg(2 * v, l, m, A, B, x);
        update_seg(2 * v + 1, m + 1, r, A, B, x);
        t1[v] = max(t1[2 * v], t1[2 * v + 1]);
        t2[v] = min(t2[2 * v], t2[2 * v + 1]);
    }

    void update(int l, int r, int x) {
        update_seg(1, 0, n - 1, l, r, x);
    }

    int get_max(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return -1;
        if (A <= l && r <= B) return t1[v];
        push(v);
        int m = (l + r) / 2;
        return max(get_max(2 * v, l, m, A, B), get_max(2 * v + 1, m + 1, r, A, B));
    }

    int get_max(int l, int r) {
        return get_max(1, 0, n - 1, l, r);
    }

    int get_min(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return -1;
        if (A <= l && r <= B) return t2[v];
        push(v);
        int m = (l + r) / 2;
        return max(get_min(2 * v, l, m, A, B), get_min(2 * v + 1, m + 1, r, A, B));
    }

    int get_min(int l, int r) {
        return get_min(1, 0, n - 1, l, r);
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    vector <array <int, 3>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0]; --edges[i][1]; --edges[i][2];
    }
    sort(edges.begin(), edges.end());
    dsu now(n);
    for (auto i : edges) now.unite(i[1], i[2], i[0]);
    vector <int> vert = now.get_vertexes();
    vector <int> w = now.get_weights();
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) pos[vert[i]] = i;
    SegTreeMax TreeMax(n, w);
    SegTree Tree(n, pos);
    while (q--) {
        int type;
        cin >> type;
        if (type <= 2) {
            int l, r;
            cin >> l >> r; --l; --r;
            Tree.update(l, r, (type - 1) ^ 1);
        } else {
            int v;
            cin >> v; v = pos[v - 1];
            int l = Tree.get_min(0, n - 1);
            int r = Tree.get_max(0, n - 1);
            int res = max(TreeMax.get_max(l, v - 1), TreeMax.get_max(v, r - 1));
            cout << res << "\n";
        }
    }
}