#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200100, logN = 20, M = 6e6;

struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

struct LineTree {
    struct edge {
        int u, v, w;
        bool operator < (const edge &e) {
            return w < e.w;
        }
    };
    struct Dsu {
        vector <vector <int>> cc, weight;
        vector <int> rt;
        Dsu (int n) {
            for (int i = 0; i < n; ++i)
                cc.pb({i}), weight.pb({}), rt.pb(i);
        }
        void Union(int u, int v, int w) {
            assert(rt[u] != rt[v]);
            u = rt[u], v = rt[v];
            if (cc[u].size() > cc[v].size())
                swap(u, v);
            weight[v].pb(w);
            for (int i : cc[u])
                cc[v].pb(i), rt[i] = v;
            for (int w : weight[u])
                weight[v].pb(w);
            cc[u].clear(), weight[u].clear();
        }
    };
    int n;
    vector <edge> E;
    vector <int> order, weight;
    LineTree (int _n) : n(_n) {}
    void add_edge (int u, int v, int w) {
        E.pb({u, v, w});
    }
    void build() {
        Dsu dsu(n);
        sort(all(E));
        for (auto e : E) {
            dsu.Union(e.u, e.v, e.w);
        }
        order = dsu.cc[dsu.rt[0]], weight = dsu.weight[dsu.rt[0]];
    }
};

struct SparseTableMax {
    vector <vector <int>> table;
    SparseTableMax (vector <int> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <int> (m, 0));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = max(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        if (l == r)
            return -1;
        int g = __lg(r - l);
        return max(table[l][g], table[r - (1 << g)][g]);
    }
};

template <typename T>
struct SparseTableMin {
    // 0-indexed, [l, r)
    vector <vector <T>> table;
    SparseTableMin () = default;
    SparseTableMin (vector <T> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <T> (m, 0));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        if (l >= r)
            return 1 << 30;
        int g = __lg(r - l);
        return min(table[l][g], table[r - (1 << g)][g]);
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        Dsu dsu(n);
        LineTree lt(n);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v, --u, --v;
            if (dsu.Union(u, v))
                lt.add_edge(u, v, i + 1);
        }
        lt.build();
        vector <int> idx(n, 0);
        for (int i = 0; i < n; ++i)
            idx[lt.order[i]] = i;
        SparseTableMax ST(lt.weight);
        SparseTableMax idxmx(idx);
        SparseTableMin <int> idxmn(idx);
        while (q--) {
            int l, r;
            cin >> l >> r, --l;
            if (r - l == 1) {
                cout << 0 << ' ';
            } else {
                int a = idxmn.query(l, r), b = idxmx.query(l, r);
                cout << ST.query(a, b) << ' ';
            }
        }
        cout << '\n';
    }
}