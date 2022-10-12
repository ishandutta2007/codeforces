#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
using vvb = vector<vb>;
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

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.first, p.second); }
    template <class T> void re(vector<T> &a) { for (auto &x : a) re(x); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (auto &x : a) re(x); }
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
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.first, ", ", x.second, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
}
using namespace __output;

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
    template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
    template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
    template <typename I> struct _range_struct { const I first_, last_; explicit _range_struct(const I first, const I last) : first_{first}, last_{last} {} I begin() const { return first_; } I end() const { return last_; } };
    template <typename I> _range_struct<I> range(const I first, const I last) { return _range_struct<I>(first, last); }
}
using namespace __algorithm;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}
// union_find_bipartite {{{
#include <vector>
#include <cassert>
#include <numeric>

struct union_find_bipartite {
    struct node {
        int parent, rank, size, status;
        bool parent_edge_parity;
        bool is_bipartite;
        int ct_nodes_on_root_side;

        node() {}

        node(int id) : parent(id), rank(0), size(1), status(-1),
                parent_edge_parity(0), is_bipartite(true), ct_nodes_on_root_side(1) {}

        int count_bipartitions() const {
            return !is_bipartite ? 0 : status == -1 ? 2 : 1;
        }

        int min_nodes_on_side_1() const {
            switch (status) {
                case  1: return ct_nodes_on_root_side;
                case  0: return size - ct_nodes_on_root_side;
                case -1: return std::min(ct_nodes_on_root_side, size - ct_nodes_on_root_side);
                default: assert(false);
            }
        }
    };

    int ct_components, ct_bipartite_components, degrees_of_freedom, min_nodes_on_side_1;
    mutable std::vector<node> data;

    union_find_bipartite(int N = 0) : ct_components(N), ct_bipartite_components(N),
            degrees_of_freedom(N), min_nodes_on_side_1(0), data(N) {
        iota(data.begin(), data.end(), 0);
    }

private:
    void subtract_component(int u) {
        ct_components--;
        if (data[u].is_bipartite) {
            ct_bipartite_components--;
            degrees_of_freedom -= data[u].status == -1;
            min_nodes_on_side_1 -= data[u].min_nodes_on_side_1();
        }
    }

    void add_component(int u) {
        ct_components++;
        if (data[u].is_bipartite) {
            ct_bipartite_components++;
            degrees_of_freedom += data[u].status == -1;
            min_nodes_on_side_1 += data[u].min_nodes_on_side_1();
        }
    }

public:
    int find(int u) const {
        if (u == data[u].parent) return u;
        find(data[u].parent);
        data[u].parent_edge_parity ^= data[data[u].parent].parent_edge_parity;
        return data[u].parent = data[data[u].parent].parent;
    }

    bool can_constrain_node_to_side(int u, bool side) const {
        find(u);
        side ^= data[u].parent_edge_parity;
        u = data[u].parent;

        return data[u].is_bipartite &&
            (data[u].status == -1 || data[u].status == side);
    }

    bool constrain_node_to_side(int u, bool side) {
        find(u);
        side ^= data[u].parent_edge_parity;
        u = data[u].parent;

        subtract_component(u);

        if (data[u].status == -1) {
            data[u].status = side;
        } else {
            data[u].is_bipartite &= data[u].status == side;
        }

        add_component(u);
        return data[u].is_bipartite;
    }

    bool can_add_constraint_on_nodes(int u, int v, bool edge_parity) const {
        find(u);
        edge_parity ^= data[u].parent_edge_parity;
        u = data[u].parent;

        find(v);
        edge_parity ^= data[v].parent_edge_parity;
        v = data[v].parent;

        if (u == v)
            return data[u].is_bipartite && edge_parity == 0;

        return data[u].is_bipartite && data[v].is_bipartite &&
            (data[u].status == -1 || data[v].status == -1 || (data[u].status ^ data[v].status) == edge_parity);
    }

    struct result {
        bool added_connectivity;
        bool component_is_bipartite;
    };

    result unite(int u, int v, bool edge_parity) {
        find(u);
        edge_parity ^= data[u].parent_edge_parity;
        u = data[u].parent;

        find(v);
        edge_parity ^= data[v].parent_edge_parity;
        v = data[v].parent;

        if (u == v) {
            subtract_component(u);
            if (edge_parity)
                data[u].is_bipartite = false;
            add_component(u);
            return {false, data[u].is_bipartite};
        }

        if (data[u].rank < data[v].rank)
            std::swap(u, v);

        subtract_component(u);
        subtract_component(v);

        data[v].parent = u;

        data[v].parent_edge_parity = edge_parity;

        if (data[u].rank == data[v].rank)
            data[u].rank++;

        data[u].size += data[v].size;

        data[u].is_bipartite &= data[v].is_bipartite;

        if (edge_parity)
            data[u].ct_nodes_on_root_side += data[v].size - data[v].ct_nodes_on_root_side;
        else
            data[u].ct_nodes_on_root_side += data[v].ct_nodes_on_root_side;

        if (data[v].status != -1) {
            bool implied_u_status = data[v].status ^ edge_parity;
            if (data[u].status == -1)
                data[u].status = implied_u_status;
            else
                data[u].is_bipartite &= data[u].status == implied_u_status;
        }

        add_component(u);
        return {true, data[u].is_bipartite};
    }

    bool can_constrain_to_be_same      (int u, int v) const { return can_add_constraint_on_nodes(u, v, 0); }
    bool can_constrain_to_be_different (int u, int v) const { return can_add_constraint_on_nodes(u, v, 1); }

    result constrain_to_be_same        (int u, int v) { return unite(u, v, 0); }
    result constrain_to_be_different   (int u, int v) { return unite(u, v, 1); }
};
// }}}

// clang-format on

void solve() {
    int n, m;
    re(n, m);

    union_find_bipartite uf(n);

    while (m--) {
        int u, v;
        re(u, v);
        u--, v--;
        string s;
        re(s);

        bool parity = (s == "imposter");

        uf.unite(u, v, parity);
    }

    if (uf.ct_components != uf.ct_bipartite_components) {
        ps(-1);
        return;
    }

    ps(n - uf.min_nodes_on_side_1);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}