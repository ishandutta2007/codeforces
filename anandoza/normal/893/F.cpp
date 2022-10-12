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
#define rall(x) (x).rbegin(), (x).rend()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto &l, const auto &r) { return y; })

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

template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template <class T1, class T2> void re(pair<T1, T2> &p);
    template <class T> void re(vector<T> &a);
    template <class T, size_t SZ> void re(array<T, SZ> &a);

    template <class T> void re(T &x) { cin >> x; }
    void re(double &x) { string t; re(t); x = stod(t); }
    template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first); re(rest...); }

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.f, p.s); }
    template <class T> void re(vector<T> &a) { F0R (i, sz(a)) re(a[i]); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { F0R (i, SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template <typename T> struct is_outputtable { template <typename C> static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; } template <typename C> static constexpr bool test(...) { return false; } static constexpr bool value = test<T>(int()); };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type> void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())> void pr(const T &x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args> void pr(const Arg &first, const Args &...rest) { pr(first); pr(rest...); }

    template <class T, bool pretty = true> void prContain(const T &x) { if (pretty) pr("{"); bool fst = 1; for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0; if (pretty) pr("}"); }

    template <class T> void pc(const T &x) { prContain<T, false>(x); pr("\n"); }
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.f, ", ", x.s, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
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
    template <typename T> void dedup(vector<T> &v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    template <typename T> typename vector<T>::const_iterator find(const vector<T> &v, const T &x) { auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end(); }
    template <typename T> size_t index(const vector<T> &v, const T &x) { auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin(); }
    template <typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(const vector<pair<T1, T2>> &v, const T1 &x) { return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; }); }
    template <typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(const vector<pair<T1, T2>> &v, const T1 &x) { return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; }); }
    template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
    template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
}
using namespace __algorithm;

struct __monostate {
    friend istream &operator>>(istream &is, const __attribute__((unused)) __monostate &ms) { return is; }
    friend ostream &operator<<(ostream &os, const __attribute__((unused)) __monostate &ms) { return os; }
} ms;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}
// tree {{{
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

struct edge {
    int u_xor_v;

    edge() : u_xor_v(0) {}

    edge(int _u_xor_v) : u_xor_v(_u_xor_v) {}

    int get_nbr(int u) const {
        assert(u_xor_v);
        return u ^ u_xor_v;
    }
};

template<typename Data>
struct edge_with_data : edge {
    Data data;

    edge_with_data() : edge() {}

    edge_with_data(int _u_xor_v, Data _data) : edge(_u_xor_v), data(_data) {}
};

enum TreeInputFormat { EDGE_LIST, PARENT_LIST };
template<typename Edge>
struct tree {
    int V, root;
    std::vector<std::vector<Edge>> neighbors;

    std::vector<int> parent, depth, subtree_size, preorder, reverse_preorder;

    tree() : V(0), root(-1) {}

    tree(int _V, int _root) : V(_V), root(_root), neighbors(V) {}

    void add_edge(int u, int v, Edge e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.u_xor_v = u ^ v;
        neighbors[u].push_back(e);
        neighbors[v].push_back(e);
    }

    const Edge& parent_edge(int u) const {
        assert(u != root);
        return neighbors[u].front();
    }

    template<typename Function>
    void for_each_child(int u, Function fn) const {
        for (int i = u != root; i < int(neighbors[u].size()); i++)
            fn(neighbors[u][i]);
    }

    static void DefaultEdgeDataReader(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataReader = void(*)(Edge&)>
    friend void re(tree &t, TreeInputFormat Format, int FirstIndex,
			EdgeDataReader read = DefaultEdgeDataReader) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            std::cin >> u, u -= FirstIndex;
            if (Format == PARENT_LIST) v = i + 1;
            else std::cin >> v, v -= FirstIndex;
            Edge e;
            read(e);
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void reroot(int _root) {
        root = _root;
        init();
    }

    void init() {
        parent.resize(V), depth.resize(V), subtree_size.resize(V);

        parent[root] = -1;
        depth[root] = 0;

        traverse(root);

        for (int u = 0; u < V; u++) {
            sort(neighbors[u].begin(), neighbors[u].end(), [&](const Edge &a, const Edge &b) {
                return subtree_size[a.get_nbr(u)] > subtree_size[b.get_nbr(u)];
            });
        }

        preorder.clear();
        build_preorder(root);

        reverse_preorder = preorder;
        std::reverse(reverse_preorder.begin(), reverse_preorder.end());
    }

    void traverse(int u) {
        subtree_size[u] = 1;
        for (Edge e : neighbors[u]) {
            int v = e.get_nbr(u);
            if (v == parent[u]) continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subtree_size[u] += subtree_size[v];
        }
    }

    void build_preorder(int u) {
        preorder.push_back(u);
        for_each_child(u, [&](Edge e) { build_preorder(e.get_nbr(u)); });
    }

    static void DefaultEdgeDataWriter(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataWriter = void(*)(Edge&)>
    friend void pr(const tree& t, EdgeDataWriter write = DefaultEdgeDataWriter) {
        std::cout << "{V=" << t.V << " root=" << t.root << " |";
        for (int u = 0; u < t.V; u++) {
            std::cout << " " << u << "--{";
            t.for_each_child(u, [&](Edge e) {
                std::cout << "(ch=" << e.get_nbr(u);
                write(e);
                std::cout << ")";
            });
            std::cout << "}";
        }
        std::cout << "}";
    }
};
// }}}
// segment_tree_persistent {{{
#include <vector>
#include <limits>
#include <cassert>
#include <algorithm>

template<typename T, typename AssociativeOperation, typename Timestamp = int>
struct segment_tree_persistent {
    struct node {
        T v;
        int left, right;
    };
    struct snapshot {
        Timestamp t;
        int root;
        int data_size;
        bool operator < (const snapshot &o) const { return t < o.t; }
    };

    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<node> data;
    std::vector<snapshot> history;

    segment_tree_persistent() {}

    segment_tree_persistent(int _SZ, T _identity, AssociativeOperation _TT) : identity(_identity), TT(_TT) {
        SZ = 1 << (32 - __builtin_clz(_SZ - 1));
        assert(SZ >= _SZ && __builtin_popcount(SZ) == 1);

        data.push_back({ identity, -1, -1 });
        for (int loc = 1; loc <= __builtin_ctz(SZ); loc++)
            data.push_back({ TT(data[loc - 1].v, data[loc - 1].v), loc - 1, loc - 1 });

        history.push_back({ std::numeric_limits<Timestamp>::min(), int(data.size()) - 1, int(data.size()) });
    }

private:
    int modify_leaf(int i, T v, int loc, int L, int R, int immutable, bool overwrite) {
        node updated;
        if (R - L == 1) {
            updated = { overwrite ? v : TT(data[loc].v, v), -1, -1 };
        } else {
            int M = L + (R - L) / 2;
            int left  = i <  M ? modify_leaf(i, v, data[loc].left,  L, M, immutable, overwrite) : data[loc].left;
            int right = M <= i ? modify_leaf(i, v, data[loc].right, M, R, immutable, overwrite) : data[loc].right;
            updated = { TT(data[left].v, data[right].v), left, right };
        }
        if (loc < immutable) {
            loc = int(data.size());
            data.push_back(updated);
        } else {
            data[loc] = updated;
        }
        return loc;
    }

    void modify_leaf(int i, T v, Timestamp t, bool overwrite) {
        int current_root = history.back().root;
        if (history.back().t == t) history.pop_back();

        int immutable = history.back().data_size;
        int updated_root = modify_leaf(i, v, current_root, 0, SZ, immutable, overwrite);
        history.push_back({ t, updated_root, int(data.size()) });
    }

    T accumulate(int i, int j, T init, int loc, int L, int R) const {
        if (L == i && j == R) {
            init = TT(init, data[loc].v);
        } else {
            int M = L + (R - L) / 2;
            if (i < M) init = accumulate(i, std::min(j, M), init, data[loc].left,  L, M);
            if (M < j) init = accumulate(std::max(i, M), j, init, data[loc].right, M, R);
        }
        return init;
    }

public:
    // Assigns v at index i during moment t
    void assign(int i, T v, Timestamp t) {
        assert(0 <= i && i < SZ && history.back().t <= t);
        modify_leaf(i, v, t, true);
    }

    // Replaces the current value at index i with TT(current value, v) during moment t
    void combine_and_assign(int i, T v, Timestamp t) {
        assert(0 <= i && i < SZ && history.back().t <= t);
        modify_leaf(i, v, t, false);
    }

    // Accumulates the elements at indices in [first, last) as they were before t (after all assignments with t' < t)
    T accumulate(int first, int last, Timestamp t) const {
        if (first >= last) return identity;
        assert(0 <= first && last <= SZ);
        int root_before_t = std::prev(std::lower_bound(history.begin(), history.end(), snapshot{ t, -1, -1 }))->root;
        return accumulate(first, last, identity, root_before_t, 0, SZ);
    }
};
// }}}

// clang-format on

using E = edge;
const int INF = numeric_limits<int>::max();

int main() {
    setIO();

    int n, r;
    re(n, r);
    r--;

    vi a(n);
    re(a);

    tree<E> tree(n, r);
    re(tree, EDGE_LIST, 1);

    vector<int> index(n);
    for (int i = 0; i < n; i++)
        index[tree.preorder[i]] = i;

    segment_tree_persistent st(n, INF, [](int u, int v) { return min(u, v); });

    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return tree.depth[i] < tree.depth[j]; });
    for (int i : order)
        st.assign(index[i], a[i], tree.depth[i]);

    int m;
    re(m);
    int ans = 0;
    for (int query = 0; query < m; query++) {
        int p, q;
        re(p, q);
        int x = (p + ans) % n;
        int k = 1 + (q + ans) % n;

        ans = st.accumulate(index[x], index[x] + tree.subtree_size[x], tree.depth[x] + k);
        ps(ans);
    }

    return 0 * 1;
}