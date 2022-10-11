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
// dijkstra {{{
#include <cstdlib>
#include <queue>
#include <cassert>
#include <algorithm>
#include <cstring>

template<typename EdgeWeight>
struct WeightedDirectedGraph {
    struct Edge {
        int neighbor;
        EdgeWeight weight;
    };

    int N;
    std::vector<std::vector<Edge>> adj;

    WeightedDirectedGraph (int _N) : N(_N), adj(_N) {}

    void add_directed_edge(int u, int v, EdgeWeight w) {
        adj[u].push_back({v, w});
    }
};

template<typename PathWeight>
struct ShortestPathTree {
    std::vector<int> parent;
    std::vector<PathWeight> shortest_path_wt;

    template<typename EdgeWeight, typename JoinPathAndEdge, typename PathWeightLessThan>
    ShortestPathTree(WeightedDirectedGraph<EdgeWeight> g, const std::vector<int> &sources,
            PathWeight init, JoinPathAndEdge join, PathWeightLessThan less_than) {
        struct Path {
            int destination;
            PathWeight weight;
        };

        auto path_cmp = [&less_than](const Path &a, const Path &b) {
            return less_than(b.weight, a.weight);
        };

        std::priority_queue<Path, std::vector<Path>, decltype(path_cmp)> pq(path_cmp);

        parent.assign(g.N, -1);
        shortest_path_wt.assign(g.N, init);

        for (int source : sources) {
            parent[source] = source;
            pq.push({ source, shortest_path_wt[source] });
        }

        while (!pq.empty()) {
            Path path = pq.top();
            pq.pop();

            if (memcmp(&path.weight, &shortest_path_wt[path.destination], sizeof(PathWeight)))
                continue;

            for (auto edge : g.adj[path.destination]) {
                PathWeight candidate = join(path.weight, edge.weight);
                if (parent[edge.neighbor] == -1 || less_than(candidate, shortest_path_wt[edge.neighbor])) {
                    parent[edge.neighbor] = path.destination;
                    shortest_path_wt[edge.neighbor] = candidate;
                    pq.push({ edge.neighbor, shortest_path_wt[edge.neighbor] });
                }
            }
        }
    }

    bool is_reachable(int destination) const {
        return parent[destination] != -1;
    }

    PathWeight distance(int destination) const {
        if (!is_reachable(destination)) assert(false);
        return shortest_path_wt[destination];
    }

    std::vector<int> list_vertices_on_path(int destination) const {
        if (!is_reachable(destination)) assert(false);

        std::vector<int> path;
        while (parent[destination] != destination) {
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(destination);

        std::reverse(path.begin(), path.end());
        return path;
    }
};
// }}}

// clang-format on

constexpr int INF = 1e9;

void solve() {
    int n, k;
    re(n, k);

    using C = pii;
    auto ind = [&](int i, int j) { return C{i / 2 + k / 2, j / 2 + k / 2}; };
    auto f = [&](pair<C, C> p) -> pair<C, C> { return {{k - p.f.f, k - p.f.s}, {k - p.s.f, k - p.s.s}}; };
    map<pair<C, C>, int> costs;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        re(a, b, c, d);
        a *= 2, b *= 2, c *= 2, d *= 2;
        a -= k + 1;
        b -= k + 1;
        c -= k + 1;
        d -= k + 1;
        pd(a, b, c, d);

        if (a == c) {
            auto u = ind(a - 1, (b + d) / 2);
            auto v = ind(a + 1, (b + d) / 2);
            pd(u, v, f({u, v}));
            if (u > v)
                swap(u, v);
            costs[{u, v}]++;
            costs[{v, u}]++;
            costs[f({u, v})]++;
            costs[f({v, u})]++;
        }

        if (b == d) {
            auto u = ind((a + c) / 2, b - 1);
            auto v = ind((a + c) / 2, b + 1);
            pd(u, v);
            if (u > v)
                swap(u, v);
            costs[{u, v}]++;
            costs[{v, u}]++;
            costs[f({u, v})]++;
            costs[f({v, u})]++;
        }
    }

    pd(costs);

    vvi dist(k + 1, vi(k + 1, INF));
    auto g_ind = [&](int i, int j) { return i * (k + 1) + j; };
    WeightedDirectedGraph<int> g((k + 1) * (k + 1));
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (i + 1 <= k) {
                C u = {i, j};
                C v = {i + 1, j};
                pd(u, v);
                auto x = g_ind(i, j);
                auto y = g_ind(i + 1, j);
                auto w = costs[{u, v}];
                pd(x, y, w);
                g.add_directed_edge(x, y, w);
                g.add_directed_edge(y, x, w);
            }
            if (j + 1 <= k) {
                C u = {i, j};
                C v = {i, j + 1};
                auto x = g_ind(i, j);
                auto y = g_ind(i, j + 1);
                auto w = costs[{u, v}];
                pd(u, v);
                pd(x, y, w);
                g.add_directed_edge(x, y, w);
                g.add_directed_edge(y, x, w);
            }
        }
    }
    auto start = g_ind(k / 2, k / 2);
    pd(start);
    ShortestPathTree spt(g, {start}, 0, plus<int>(), less<int>());

    int ans = INF;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 || j == 0 || i == k || j == k) {
                auto x = g_ind(i, j);
                if (spt.is_reachable(x))
                    ckmin(ans, spt.distance(x));
            }
        }
    }

    ps(n - ans);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}