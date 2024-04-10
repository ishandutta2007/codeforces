
#ifdef LOCAL
//#define _GLIBCXX_DEBUG
#endif
//#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
//#endif

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

// #define int ll
#define endl '\n'

const int INF = 1e9 + 228;

struct edge {
    int a, b, c;
};

bool operator<(const edge &a, const edge &b) {
    return a.c < b.c;
}

struct Tree {
    int n;
    vector<edge> edges;

    Tree() {}

    void init(int n_) {
        n = n_;
    }
    void addEdge(int a, int b, int c) {
        edges.push_back({a, b, c});
    }

    tuple<vector<int>, vector<int>, vector<int>> buildLineTree() { // {vers, inds, weights}
        vector<vector<int>> comps(n), weights(n);
        vector<int> cind(n);
        for (int i = 0; i < n; i++) {
            comps[i].push_back(i);
            cind[i] = i;
        }
        sort(edges.begin(), edges.end());
        for (auto e : edges) {
            int a = e.a;
            int b = e.b;
            int i = cind[a];
            int j = cind[b];
            assert(i != j);
            if (comps[j].size() > comps[i].size())
                swap(i, j);
            for (int el : comps[j]) {
                cind[el] = i;
                comps[i].push_back(el);
            }
            comps[j].clear();
            weights[i].push_back(e.c);
            for (int el : weights[j]) {
                weights[i].push_back(el);
            }
        }
        vector<int> vers, weights2, inds(n);
        vers = comps[cind[0]];
        weights2 = weights[cind[0]];
        for (int i = 0; i < n; i++) {
            inds[vers[i]] = i;
        }
        return {vers, inds, weights2};
    }
};

struct DSU {
    vector<int> pa, ra;

    DSU() {
    }

    void init(int n) {
        pa.resize(n);
        ra.resize(n);
        iota(pa.begin(), pa.end(), 0);
        fill(ra.begin(), ra.end(), 1);
    }

    int get(int v) {
        if (pa[v] == v)
            return v;
        return pa[v] = get(pa[v]);
    }

    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        assert(a != b);
        if (ra[b] > ra[a])
            swap(a, b);
        pa[b] = a;
        ra[a] += ra[b];
    }
};

int tree[4 * 200000 + 100];

void build(int v, int l, int r, vector<int> &inds, int ql, int qr, int val) {
    if (ql == qr) {
        return;
    }
    assert(l <= inds[ql] && inds[ql] < r);
    assert(l <= inds[qr - 1] && inds[qr - 1] < r);
    if (l + 1 == r) {
        tree[v] = val;
        return;
    }
    int m = (l + r) / 2;
    int qm = (int) (lower_bound(inds.begin() + ql, inds.begin() + qr, m) - inds.begin());
    build(2 * v + 1, l, m, inds, ql, qm, val);
    build(2 * v + 2, m, r, inds, qm, qr, val);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

int find_first(int v, int l, int r, vector<int> &inds, int ql, int qr, int i) {
    if (r <= i + 1) {
        return -1;
    }
    if (l <= i) {
        int m = (l + r) / 2;
        int qm = (int) (lower_bound(inds.begin() + ql, inds.begin() + qr, m) - inds.begin());
        int a = find_first(2 * v + 1, l, m, inds, ql, qm, i);
        if (a != -1)
            return a;
        return find_first(2 * v + 2, m, r, inds, qm, qr, i);

    }
    if (tree[v] == 0) {
        if (qr - ql == r - l) {
            return -1;
        }
        for (int i = 0; i < qr - ql; i++) {
            if (l + i != inds[ql + i]) {
                return l + i;
            }
        }
        return l + qr - ql;
    }
    if (tree[v] == r - l) {
        return -1;
    }
    int m = (l + r) / 2;
    if (ql == qr) {
        if (tree[v] == 0) {
            return l;
        }
    }
    int qm = (int) (lower_bound(inds.begin() + ql, inds.begin() + qr, m) - inds.begin());
    int a = find_first(2 * v + 1, l, m, inds, ql, qm, i);
    if (a != -1)
        return a;
    return find_first(2 * v + 2, m, r, inds, qm, qr, i);
}

int find_last(int v, int l, int r, vector<int> &inds, int ql, int qr, int i) {
    if (i <= l) {
        return -1;
    }
    if (i < r) {
        int m = (l + r) / 2;
        int qm = (int) (lower_bound(inds.begin() + ql, inds.begin() + qr, m) - inds.begin());
        int a = find_last(2 * v + 2, m, r, inds, qm, qr, i);
        if (a != -1)
            return a;
        return find_last(2 * v + 1, l, m, inds, ql, qm, i);
        
    }
    if (tree[v] == 0) {
        if (qr - ql == r - l) {
            return -1;
        }
        for (int i = 0; i < qr - ql; i++) {
            if (r - i - 1 != inds[qr - i - 1]) {
                return r - i - 1;
            }
        }
        return r - 1 - (qr - ql);
    }
    if (tree[v] == r - l) {
        return -1;
    }
    int m = (l + r) / 2;
    if (ql == qr) {
        if (tree[v] == 0) {
            return r - 1;
        }
    }
    int qm = (int) (lower_bound(inds.begin() + ql, inds.begin() + qr, m) - inds.begin());
    int a = find_last(2 * v + 2, m, r, inds, qm, qr, i);
    if (a != -1)
        return a;
    return find_last(2 * v + 1, l, m, inds, ql, qm, i);
}

pair<int, int> find_first_last(vector<int> &inds, int m, int i) { // {-1, -1} if not found
    return {
        find_first(0, 0, m, inds, 0, (int) inds.size(), i),
        find_last(0, 0, m, inds, 0, (int) inds.size(), i)
    };
}

struct RMQ {
    int n;
    vector<vector<int>> sp;
    int LOG;
    vector<int> lg;
    RMQ(){}
    void clear() {
        n = -1;
        sp.clear();
        LOG = -1;
        lg.clear();
    }
    void build(vector<int> arr) {
        n = (int) arr.size();
        LOG = 0;
        while ((1 << LOG) < n) {
            LOG++;
        }
        LOG++;
        sp.resize(n, vector<int> (LOG));
        for (int i = 0; i < n; i++) {
            sp[i][0] = arr[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
            }
        }
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
    }

    int min(int l, int r) {
        int j = lg[r - l];
        return max(sp[l][j], sp[r - (1 << j)][j]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    // first graph
    vector<edge> edges1(m);
    vector<vector<int>> g1(n);
    for (int i = 0; i < m; i++) {
        cin >> edges1[i].a;
        cin >> edges1[i].b;
        cin >> edges1[i].c;
        edges1[i].a--;
        edges1[i].b--;
        g1[edges1[i].a].push_back(edges1[i].b);
        g1[edges1[i].b].push_back(edges1[i].a);
    }
    auto edges1_init = edges1;
    sort(edges1.begin(), edges1.end());
    DSU dsu1;
    dsu1.init(n);
    Tree tree1;
    tree1.init(n);
    for (auto e : edges1) {
        int a = e.a;
        int b = e.b;
        int c = e.c;
        if (dsu1.get(a) != dsu1.get(b)) {
            dsu1.merge(a, b);
            tree1.addEdge(a, b, c);
        }
    }

    // build second graph
    
    auto [vers, inds, weights] = tree1.buildLineTree();
    RMQ rmq;
    rmq.build(weights);
    auto get_edge = [&](int from_ind, int to_ind) -> edge {
        if (to_ind < from_ind) {
            swap(from_ind, to_ind);
        }
        int w = rmq.min(from_ind, to_ind);
        return {vers[from_ind], vers[to_ind], w};
    };
    DSU dsu2;
    dsu2.init(n);
    Tree tree2;
    tree2.init(n);
    // Boruvka
    while (true) {
        vector<vector<int>> comps(n);
        for (int i = 0; i < n; i++) {
            comps[dsu2.get(i)].push_back(i);
        }
        {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (!comps[i].empty())
                    cnt++;
            }
            if (cnt == 1)
                break;
        }
        for (auto comp : comps) {
            vector<int> cinds; // indexes of component vertices in line tree
            cinds.resize(comp.size());
            for (int i = 0; i < (int) comp.size(); i++) {
                cinds[i] = inds[comp[i]];
            }
            sort(cinds.begin(), cinds.end());
            // build segment tree
            build(0, 0, n, cinds, 0, (int) cinds.size(), 1);
            // find neighbours
            edge best = {-1, -1, INF};
            for (int v : comp) {
                vector<int> neighbours = g1[v];
                for (int &el : neighbours) {
                    el = inds[el];
                }
                sort(neighbours.begin(), neighbours.end());
                pair<int, int> first_last = find_first_last(neighbours, n, inds[v]);
                if (first_last.first != -1) {
                    auto e1 = get_edge(first_last.first, inds[v]);
                    best = min(best, e1);
                }
                if (first_last.second != -1) {
                    auto e2 = get_edge(first_last.second, inds[v]);
                    best = min(best, e2);
                }
            }
            if (best.a != -1 && dsu2.get(best.a) != dsu2.get(best.b)) {
                dsu2.merge(best.a, best.b);
                tree2.addEdge(best.a, best.b, best.c);
            }
            build(0, 0, n, cinds, 0, (int) cinds.size(), 0);
        }
    }
    tie(vers, inds, weights) = tree2.buildLineTree();
    rmq.clear();
    rmq.build(weights);
    for (auto e : edges1_init) {
        auto e2 = get_edge(inds[e.a], inds[e.b]);
        cout << e2.c << " ";
    }
    cout << endl;
}

signed main() {
#ifdef _GLIBCXX_DEBUG
    cerr << "GLIBCXX is on!" << endl;
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}