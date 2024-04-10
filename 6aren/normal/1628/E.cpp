#include <bits/stdc++.h>

using namespace std;

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


const int INF = 1000000001;
const int N = 300005;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct DSU {
    int n;
    vector<int> par;
    DSU(int n): n(n) {
        par.resize(n, -1);
    }
    
    int root(int x) {
        if (par[x] == -1) par[x] = x;
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }

    int merge(int x, int y) {
        x = root(x);
        y = root(y);
        par[x] = y;
        return y;
    }
};

struct SparseTable {
    int n;
    vector<vector<int>> mat;

    SparseTable(const vector<int> &a) {
        int n = a.size();
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = max(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int get(int from, int to) const {
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return max(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

int n, q;
vector<Edge> edges;

vector<Edge> linearizeTree() {
    sort(edges.begin(), edges.end(), [](Edge x, Edge y) {return x.w < y.w;});
    vector<Edge> linearTree;
    DSU dsu(n + 1);
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) l[i] = r[i] = i;
    for (auto [u, v, w] : edges) {
        u = dsu.root(u);
        v = dsu.root(v);
        linearTree.emplace_back(r[u], l[v], w);
        int z = dsu.merge(u, v);
        tie(l[z], r[z]) = make_pair(l[u], r[v]);
    }
    return linearTree;
}

struct Node {
    int mxAll, mnAll;
    int mxOf, mnOf;

    Node() {}
    Node(int mxAll, int mnAll, int mxOf, int mnOf) : mxAll(mxAll), mnAll(mnAll), mxOf(mxOf), mnOf(mnOf) {}
};

struct SegmentTree {
    vector<Node> it;
    vector<int> lazy, val;
    int n;

    void combine(int k) {
        it[k].mxOf = max(it[2 * k].mxOf, it[2 * k + 1].mxOf);
        it[k].mnOf = min(it[2 * k].mnOf, it[2 * k + 1].mnOf);
    }

    void combineInit(int k) {
        it[k].mxAll = max(it[2 * k].mxAll, it[2 * k + 1].mxAll);
        it[k].mnAll = min(it[2 * k].mnAll, it[2 * k + 1].mnAll);
        combine(k);
    }

    void build(int k, int l, int r) {
        if (l == r) {
            it[k] = Node(val[l], val[l], -INF, INF);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * k, l, mid);
        build(2 * k + 1, mid + 1, r);
        combineInit(k);
    }

    SegmentTree(int n, const vector<int> &val) : n(n), val(val) {
        it.resize(4 * (n + 1));
        lazy.resize(4 * (n + 1));
        build(1, 1, n - 1);
    }

    void apply(Node &node, int type) {
        if (type == 1) {
            node.mxOf = node.mxAll;
            node.mnOf = node.mnAll;
        } else {
            node.mxOf = -INF;
            node.mnOf = INF;
        }
    }

    void down(int k) {
        int v = lazy[k];
        lazy[k] = 0;
        if (v == 0) return;
        lazy[2 * k] = lazy[2 * k + 1] = v;
        apply(it[2 * k], v);
        apply(it[2 * k + 1], v);
    }

    void update(int k, int l, int r, int u, int v, int type) {
        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            apply(it[k], type);
            lazy[k] = type;
            return;
        }
        down(k);
        int mid = (l + r) / 2;
        update(2 * k, l, mid, u, v, type);
        update(2 * k + 1, mid + 1, r, u, v, type);
        combine(k);
    }

    void update(int u, int v, int type) {
        update(1, 1, n - 1, u, v, type);
    }

    pair<int, int> getRes() {
        return make_pair(it[1].mnOf, it[1].mxOf);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    edges.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }
    vector<Edge> linearTree = linearizeTree();
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> edgeW(n);
    vector<int> pos(n + 1);
    for (auto [u, v, w] : linearTree) {
        debug(u, v, w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto [v, w] : g[u]) {
            if (v == p) continue;
            edgeW[pos[u]] = w;
            pos[v] = pos[u] + 1;
            dfs(v, u);
        }
    };

    int first = 0;
    for (int i = 1; i <= n; i++) if (g[i].size() == 1) {
        first = i;
        break;
    }

    dfs(first, -1);

    debug(pos);
    SparseTable sp(edgeW);
    SegmentTree segTree(n + 1, pos);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1 || type == 2) {
            int l, r;
            cin >> l >> r;
            segTree.update(l, r, type);
        } else {
            int x;
            cin >> x;
            auto [l, r] = segTree.getRes();
            if (l == INF || (l == r && l == pos[x])) {
                cout << "-1\n";
                continue;
            }
            debug(l, r);
            l = min(l, pos[x]);
            r = max(r, pos[x]);
            debug(l, r);
            cout << sp.get(l, r - 1) << '\n';
        }
    }
}