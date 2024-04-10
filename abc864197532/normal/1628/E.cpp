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
const int mod = 1e9 + 7, N = 300001, logN = 20, K = 48763;

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

struct Seg {
    int l, r, m, valmn, valmx, mn, mx, lz;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &idx) : l(_l), r(_r), m(l + r >> 1), lz(-1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, idx);
            ch[1] = new Seg(m, r, idx);
            pull();
        } else {
            valmn = valmx = idx[l];
            mn = 1 << 30, mx = -1 << 30;
        }
    }
    void pull() {
        mn = min(ch[0]->mn, ch[1]->mn);
        mx = max(ch[0]->mx, ch[1]->mx);
        valmn = min(ch[0]->valmn, ch[1]->valmn);
        valmx = max(ch[0]->valmx, ch[1]->valmx);
    }
    void give(int x) {
        lz = x;
        if (x)
            mn = valmn, mx = valmx;
        else
            mn = 1 << 30, mx = -1 << 30;
    }
    void push() {
        if (lz == -1)
            return;
        ch[0]->give(lz), ch[1]->give(lz);
        lz = -1;
    }
    void modify(int a, int b, int x) {
        if (a <= l && r <= b)
            give(x);
        else {
            push();
            if (a < m)
                ch[0]->modify(a, b, x);
            if (m < b)
                ch[1]->modify(a, b, x);
            pull();
        }
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    LineTree lt(n);
    for (int i = 0, u, v, w; i < n - 1; ++i) {
        cin >> u >> v >> w, --u, --v;
        lt.add_edge(u, v, w);
    }
    lt.build();
    vector <int> idx(n, 0);
    for (int i = 0; i < n; ++i)
        idx[lt.order[i]] = i;
    SparseTableMax ST(lt.weight);
    Seg root(0, n, idx);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r, --l;
            root.modify(l, r, 1);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r, --l;
            root.modify(l, r, 0);
        } else {
            int v;
            cin >> v, --v;
            int mn = root.mn, mx = root.mx;
            if (mn == 1 << 30)
                cout << -1 << endl;
            else {
                int ans = -1;
                {
                    int x = idx[v], y = mn;
                    if (x > y)
                        swap(x, y);
                    ans = max(ans, ST.query(x, y));
                }
                {
                    int x = idx[v], y = mx;
                    if (x > y)
                        swap(x, y);
                    ans = max(ans, ST.query(x, y));
                }
                cout << ans << endl;
            }
        }
    }
}