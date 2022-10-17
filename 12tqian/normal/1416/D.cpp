#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }
template<class T> struct SegTree {
    const T ID = {0, 0};
    T comb(T a, T b) {
        return max(a, b);
    }
    int n;
    vector<T> seg;
    void init(int _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }
    void pull(int p) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }
    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};
struct DSU {
    vector<int> e;
    void init(int n) {
        e = vector<int>(n, -1);
    }
    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool same_set(int a, int b) {
        return get(a) == get(b);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};
struct LCAJump {
    int n;
    vector<vector<int>> par;
    vector<vector<int>> adj;
    vector<int> depth;
    void init(int _n) {
        n = _n;
        int d = 1;
        while ((1 << d) < n) d++;
        par.assign(d, vector<int>(n));
        adj.resize(n);
        depth.resize(n);
    }
    void ae(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void gen(int root = 0) {
        par[0][root] = root;
        dfs(root);
    }
    void dfs(int src = 0) {
        for (int i = 1; i < par.size(); i++) {
            par[i][src] = par[i - 1][par[i - 1][src]];
        }
        for (int nxt: adj[src]) {
            if (nxt == par[0][src]) continue;
            depth[nxt] = depth[par[0][nxt] = src] + 1;
            dfs(nxt);
        }
    }
    int jump(int x, int d) {
        for (int i = 0; i < par.size(); i++) {
            if ((d >> i) & 1) {
                x = par[i][x];
            }
        }
        return x;
    }
    int lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        x = jump(x, depth[x] - depth[y]);
        if (x == y) return x;
        for (int i = par.size() - 1; i >= 0; i--) {
            int nx = par[i][x];
            int ny = par[i][y];
            if (nx != ny) x = nx, y = ny;
        }
        return par[0][x];
    }
};
int main() {
    const int INF = 1e9;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<array<int, 2>> edges(m);
    vector<bool> used(m, true);
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }
    vector<array<int, 2>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][1]--;
        if (queries[i][0] == 2) {
            used[queries[i][1]] = false;
        }
    }
    int big = 3 * n;
    DSU D;
    D.init(big);
    LCAJump L;
    L.init(big);
    vector<int> root(big);
    vector<int> label(big);
    vector<int> value(big);
    for (int i = 0; i < m; i++) {
        if (used[i] == false) {
            continue;
        }
        D.unite(edges[i][0], edges[i][1]);
    }
    map<int, vector<int>> comps;
    for (int i = 0; i < n; i++) {
        comps[D.get(i)].emplace_back(i);
    }
    int cur = n;
    auto ae = [&](int u, int v) {
        L.ae(u, v);
    };
    for (auto c: comps) {
        vector<int> verts = c.second;
        int root = cur++;
        for (int nxt: verts) {
            label[nxt] = INF;
            ae(root, nxt);
            D.unite(root, nxt);
            value[D.get(root)] = root;
        }
        label[root] = INF;
    }
    for (int i = q - 1; i >= 0; i--) {
        if (queries[i][0] == 1) {
            continue;
        }
        int u = edges[queries[i][1]][0];
        int v = edges[queries[i][1]][1];
        int x = D.get(u);
        int y = D.get(v);
        if (D.same_set(u, v)) {
            continue;
        }
        int root = cur++;
        ae(root, value[x]);
        ae(root, value[y]);
        D.unite(root, value[x]);
        D.unite(root, value[y]);
        label[root] = i;
        value[D.get(root)] = root;
    }
    vector<int> id(big);
    vector<int> ri(big);
    vector<int> roots;
    for (int i = 0; i < cur; i++) {
        if (value[D.get(i)] == i) {
            roots.push_back(i);
        }
    }
    int vals = 0;
    function<int(int, int)> dfs = [&](int src, int par) -> int {
        id[src] = vals++;
        ri[src] = id[src];
        for (int nxt: L.adj[src]) {
            if (nxt == par) {
                continue;
            }
            ri[src] = max(dfs(nxt, src), ri[src]);
        }
        return ri[src];
    };
    for (int root: roots) {
        dfs(root, -1);
        L.gen(root);
    }
    SegTree<pair<int, int>> seg;
    seg.init(big);
    for (int i = 0; i < n; i++) {
        seg.upd(id[i], {p[i], id[i]});
    }
    auto query = [&](int src) -> int {
        auto res = seg.query(id[src], ri[src]);
        int val = res.first;
        int idx = res.second;
        seg.upd(idx, {0, idx});
        return val;
    };
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 2) {
            continue;
        }
        int vert = queries[i][1];
        int up = vert;
        for (int d = (int) (L.par).size() - 1; d >= 0; d--) {
            if (label[L.par[d][up]] >= i) {
                up = L.par[d][up];
            }
        }
        cout << query(up) << '\n';
    }
    return 0;
}