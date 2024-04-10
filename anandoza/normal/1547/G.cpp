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
}
using namespace __algorithm;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}

// clang-format on

// bfs {{{
#include <algorithm>
#include <queue>

struct BFS {
    std::vector<int> distance;
    std::vector<int> parent;

    BFS(const std::vector<std::vector<int>> &adj, const std::vector<int> &sources) {
        const int n = adj.size();
        distance.assign(n, -1);
        parent.assign(n, -1);

        std::queue<int> q;
        for (int i : sources) {
            q.push(i);
            distance[i] = 0;
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            for (int j : adj[i]) {
                if (distance[j] != -1)
                    continue;

                q.push(j);
                distance[j] = distance[i] + 1;
                parent[j] = i;
            }
        }
    }

    std::vector<int> get_path(int destination) {
        if (distance[destination] == -1)
            return {};
        std::vector<int> path{};
        for (int i = destination; i != -1; i = parent[i])
            path.push_back(i);
        std::reverse(path.begin(), path.end());
        return path;
    }
};
// }}}
// tarjan {{{
#include <vector>

struct scc {
    int components;
    std::vector<int> label;
};

// Labels strongly connected components in reverse topological order.
// That means for any edge u-->v label[u] >= label[v].
scc strongly_connected_components(const std::vector<std::vector<int>> &graph) {
    const int N = int(graph.size());

    int C = 0, V = 0, top = 0;
    std::vector<int> comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto &&self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1)
                low = std::min(low, self(self, nbr));
            else if (comp[nbr] == -1)
                low = std::min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return {C, comp};
}
// }}}

void solve() {
    int n, m;
    re(n, m);
    vvi adj(n);
    vvi rev(n);
    set<int> self;
    for (int i = 0; i < m; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        adj[u].push_back(v);
        rev[v].push_back(u);

        if (u == v)
            self.insert(u);
    }

    vi ans(n, 1e9);
    set<int> rem;
    for (int i = 0; i < n; i++)
        rem.insert(i);
    auto assign = [&](int i, int v) {
        ans[i] = v;
        assert(rem.count(i));
        rem.erase(i);
    };

    // no paths
    BFS from_start(adj, {0});
    for (int i = 0; i < n; i++) {
        if (from_start.distance[i] == -1)
            assign(i, 0);
    }

    // find loops/cycles
    auto [C, label] = strongly_connected_components(adj);
    vvi comp(C);
    for (int i = 0; i < n; i++)
        comp[label[i]].push_back(i);
    for (auto &c : comp) {
        if (sz(c) > 1)
            self.insert(all(c));
    }

    vi reachable_loop;
    for (int i : self)
        if (from_start.distance[i] != -1)
            reachable_loop.push_back(i);

    // infinite paths
    BFS from_loop(adj, vi{all(reachable_loop)});
    for (int i = 0; i < n; i++) {
        if (from_loop.distance[i] != -1)
            assign(i, -1);
    }

    // 1 vs 2 paths
    vector<int> ways(C, 0);
    ways[label[0]] = 1;
    for (auto &c : reversed(comp)) {
        for (int i : c) {
            for (int j : adj[i]) {
                ways[label[j]] += ways[label[i]];
                ckmin(ways[label[j]], 2);
            }
        }
    }
    for (int i : vi(all(rem))) {
        assign(i, ways[label[i]]);
    }

    pc(ans);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}