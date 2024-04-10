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

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.f, p.s); }
    template <class T> void re(vector<T> &a) { for (int i = 0; i < sz(a); i++) re(a[i]); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (int i = 0; i < SZ; i++) re(a[i]); }
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

// union_find {{{
#include <vector>
#include <numeric>
#include <iostream>

struct union_find {
    struct node {
        int parent, rank, size;
        node (int id = 0) : parent(id), rank(0), size(1) {}
    };

    mutable std::vector<node> data;

    union_find(int SZ = 0) : data(SZ) {
        iota(data.begin(), data.end(), 0);
    }

    // Returns the root of the component containing i
    int find(int i) const {
        if (i != data[i].parent)
            data[i].parent = find(data[i].parent);
        return data[i].parent;
    }

    bool is_root(int i) const {
        return i == find(i);
    }

    node& root_node(int i) const {
        return data[find(i)];
    }

    /* Unites the components containing a and b if they are different.
     * Returns a boolean indicating whether a and b were in different components.
     */
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (data[a].rank < data[b].rank)
            std::swap(a, b);

        data[b].parent = a;
        data[a].size += data[b].size;
        if (data[a].rank == data[b].rank)
            data[a].rank++;

        return true;
    }

    friend void pr(const union_find& u) {
        std::cout << "{";
        bool first = 1;
        for (int i = 0; i < int(u.data.size()); i++) {
            if (u.is_root(i)) {
                if (!first) std::cout << ", ";
                else first = 0;
                std::cout << "[ " << i << " | rank=" << u.data[i].rank
                    << " size=" << u.data[i].size << " ]";
            }
        }
        std::cout << "}";
    }
};
// }}}
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

// clang-format on

const int INF = 1e9;

int main() {
    setIO();

    int n, m;
    re(n, m);
    int k, w;
    re(k, w);

    vector<vector<string>> levels(k, vector<string>(n));
    re(levels);

    vvi adj(k + 1, vi(k + 1, INF));
    ckmin(adj[0][0], 0);
    for (int i = 0; i < k; i++) {
        ckmin(adj[i + 1][0], n * m);
        ckmin(adj[0][i + 1], n * m);
        ckmin(adj[i + 1][i + 1], 0);
        for (int j = i + 1; j < k; j++) {
            int d = 0;
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    d += (levels[i][r][c] != levels[j][r][c]);
                }
            }
            ckmin(adj[i + 1][j + 1], d * w);
            ckmin(adj[j + 1][i + 1], d * w);
        }
    }

    vpii best(k + 1);
    for (int i = 0; i < k + 1; i++) {
        best[i] = {INF, -1};
    }
    vb visited(k + 1);

    auto visit = [&](int i) {
        visited[i] = true;
        for (int j = 0; j < k + 1; j++) {
            if (visited[j])
                continue;
            ckmin(best[j], {adj[i][j], i});
        }
    };
    visit(0);

    vector<pii> output;
    ll ans = 0;
    for (int step = 0; step < k; step++) {
        int next = min_element(all(best)) - best.begin();

        output.push_back({next, best[next].second});
        ans += best[next].first;
        visit(next);

        best[next] = {INF, -1};
    }

    ps(ans);
    for (auto [u, v] : output)
        ps(u, v);

    return 0;
}