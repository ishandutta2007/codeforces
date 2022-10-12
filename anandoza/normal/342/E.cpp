#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

#define Lu(...) [&] (auto &&u) { return __VA_ARGS__; }
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { pr(first); pr(rest...); }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("{",x.f,", ",x.s,"}"); }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { pr(first); ps(); }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { pr(first," "); ps(rest...); }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#ifdef ANAND_LOCAL
#define pd(...) pr("\033[1;31m"), __pn((__VA_ARGS__)), ps(__VA_ARGS__), pr("\033[0m"), cout << flush
#else
#define pd(...)
#endif

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) { auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end(); }
    template<typename T> size_t index(const vector<T>& v, const T& x) { auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin(); }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}
// tree {{{
struct edge {
    int uv; //int id;
    edge (int _uv = 0, __attribute__((unused))__monostate _ = ms) : uv(_uv) {}
    int operator()(int u) const { assert(uv); return uv ^ u; }
    __monostate& wt() const { return ms; }
    struct path { int len;
        path operator+(const path& p) const { return {len+p.len}; }
        friend void pr(const path& p) { pr(p.len);}
    }; explicit operator path() { return {1}; }
};
template<typename W> struct wedge : edge {
    mutable W w;
    wedge (int _uv = 0, W _w = {}) : edge(_uv), w(_w) {}
    W& wt() const { return w; }
    struct path { int len; W wt;
        path operator+(const path& p) { return {len+p.len, wt+p.wt}; }
    }; explicit operator path() { return {1, w}; }
};

enum INPUT_FORMAT { EDGE_LIST, PARENT_LIST };
template<typename E> struct tree {
    int V, root;
    vector<vector<E>> nbrs, children;

    vi par, depth, subt_sz;
    vi preorder, reverse_preorder;

    tree() : V(0), root(-1) {}
    tree(int _V, int _root) : V(_V), root(_root), nbrs(V) {}

    const E& up_edge(int u) const {
        assert(u != root);
        return nbrs[u].front();
    }

    void add_edge(int u, int v, E e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.uv = u ^ v;
        nbrs[u].pb(e);
        nbrs[v].pb(e);
    }

    template<INPUT_FORMAT FMT = EDGE_LIST, bool FIRST_INDEX = 1>
    friend void re(tree& t) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            re(u), u -= FIRST_INDEX;
            if (FMT == PARENT_LIST) v = i+1;
            else re(v), v -= FIRST_INDEX;
            E e{}; re(e.wt()); // e.id = i
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void init() {
        children.resz(V), par.resz(V), depth.resz(V), subt_sz.resz(V);
        par[root] = -1, depth[root] = 0;

        traverse(root);
        for (int u = 0; u < V; u++) {
            sort_by(nbrs[u], subt_sz[a(u)] > subt_sz[b(u)]);
            children[u].clear();
            copy(nbrs[u].begin() + (u != root), nbrs[u].end(), back_inserter(children[u]));
        }

        preorder.clear(), preorder.reserve(V), build_preorder(root);
        reverse_preorder = preorder, reverse(all(reverse_preorder));
    }
    void reroot(int _root) { root = _root; init(); }

    void traverse(int u) {
        subt_sz[u] = 1;
        for (E e : nbrs[u]) {
            int v = e(u);
            if (v == par[u]) continue;
            par[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subt_sz[u] += subt_sz[v];
        }
    }

    void build_preorder(int u) {
        preorder.pb(u);
        for (E e : children[u]) build_preorder(e(u));
    }

    friend void pr(const tree& t) {
        pr("{V=", t.V, " root=", t.root, " |");
        for (int u = 0; u < t.V; u++) {
            pr(" ", u, "--{");
            for (E e : t.children[u])
                pr("(ch=", e(u), " wt=", e.wt(), ")");
            pr("}");
        }
        pr("}");
    }
};
// }}}
// centroid_decomposition {{{
template<typename E, int MAXV, bool PREORDER>
struct centroid_decomposition {
    static const int L = 33 - __builtin_clz(MAXV - 1);

    const tree<E>& t;
    using P = typename E::path;
    struct visit { int node; E in; };
    vi layer;                        // 0-indexed depth in the centroid tree
    vpii par;                        // {parent, index among parent's children}
    vi child_ct;                     // number of children
    vector<array<P, L>> anc_path;    // paths to ancestors, by layer
    vector<vector<visit>> preorder;  // preorder traversals recording {node, incoming edge}
    vvi ch_sz;                       // child tree sizes in traversal order

    centroid_decomposition(const tree<E>& _t) : t(_t),
            layer(t.V, -1), par(t.V), child_ct(t.V), anc_path(t.V) {
        assert(t.V <= MAXV);
        if (PREORDER) preorder.resz(t.V), ch_sz.resz(t.V);
        subt_sz = t.subt_sz, decompose(t.root), subt_sz.clear();
    }

    vi subt_sz;
    int centroid(int r) {
        int c = r;
        FIND: for (E e : t.nbrs[c]) if (int u = e(c); layer[u] == -1) {
            if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[r]) {
                c = u; goto FIND;
            }
        }
        return c;
    }

    int ly = 0, rt = 0;
    void traverse(int u, E in) {
        if (PREORDER) preorder[rt].pb({u, in});
        subt_sz[u] = 1;
        for (E e : t.nbrs[u]) if (int v = e(u); v != in(u) && layer[v] == -1) {
            anc_path[v][ly] = anc_path[u][ly] + P(e);
            traverse(v, e);
            subt_sz[u] += subt_sz[v];
        }
    }

    void decompose(int r = 0, int p = -1, int i = 0) {
        par[r = centroid(r)] = {p, i}, i = 0;
        layer[r] = ly;
        if (PREORDER) preorder[r] = {{r, E()}};
        subt_sz[r] = 1;
        for (E e : t.nbrs[r]) if (int u = e(r); layer[u] == -1) {
            if (PREORDER) ch_sz[r].pb(-sz(preorder[r]));
            rt = r, anc_path[u][ly] = P(e), traverse(u, e);
            if (PREORDER) ch_sz[r].back() += sz(preorder[r]);
            subt_sz[r] += subt_sz[u], child_ct[r]++;
            ly++, decompose(u, r, i++), ly--;
        }
    }

    int lca(int u, int v) const {
        if (layer[u] < layer[v]) swap(u, v);
        while (layer[u] != layer[v]) u = par[u].f;
        while (u != v) u = par[u].f, v = par[v].f;
        return u;
    }

    P dist(int u, int v) const {
        int clca = lca(u, v);
        return anc_path[u][layer[clca]] + anc_path[v][layer[clca]];
    }
};
// }}}

// clang-format on

using E = edge;
int main() {
    setIO();

    int n, m;
    re(n, m);
    tree<E> tree(n, 0);
    re<EDGE_LIST, 1>(tree);

    centroid_decomposition<E, 200'000, false> cd(tree);

    vi a(n, n);
    auto paint = [&](int u) {
        for (int v = u; v >= 0; v = cd.par[v].first) {
            ckmin(a[v], cd.dist(u, v).len);
        }
    };
    paint(0);

    F0R (query, m) {
        int type;
        re(type);
        int u;
        re(u);
        u--;
        if (type == 1) {
            paint(u);
        } else if (type == 2) {
            int ans = INT_MAX;
            for (int v = u; v >= 0; v = cd.par[v].first) {
                ckmin(ans, a[v] + cd.dist(u, v).len);
            }
            ps(ans);
        }
    }

    return 0;
}