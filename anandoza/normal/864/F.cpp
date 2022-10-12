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

// clang-format on

constexpr int L = 12;
constexpr int INF = 1e9;

int main() {
    setIO();

    int n, m, queries;
    re(n, m, queries);
    vvi adj(n), rev(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        re(u, v);
        u--, v--;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    struct Q {
        int start, k, index;
    };
    vector<vector<Q>> by_end(n);
    for (int query = 0; query < queries; query++) {
        int start, end, k;
        re(start, end, k);
        start--, end--, k--;
        by_end[end].push_back({start, k, query});
    }

    vi ans(queries);
    for (int end = 0; end < n; end++) {
        vb reachable(n);

        // BFS
        {
            queue<int> q;
            reachable[end] = true;
            q.push(end);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int next : rev[cur]) {
                    if (reachable[next])
                        continue;

                    reachable[next] = true;
                    q.push(next);
                }
            }
        }

        vi parent(n, -1);
        for (int i = 0; i < n; i++) {
            if (i == end)
                continue;
            if (!reachable[i])
                continue;
            int next = INF;
            for (int j : adj[i]) {
                if (!reachable[j])
                    continue;
                ckmin(next, j);
            }
            if (next != INF)
                parent[i] = next;
        }

        union_find uf(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                uf.unite(i, parent[i]);
        }
        for (int i = 0; i < n; i++) {
            if (uf.find(i) != uf.find(end))
                parent[i] = -1;
        }

        vvi anc(L, vi(n, -1)); // anc[l][i] is distance 2^l away from i
        for (int i = 0; i < n; i++)
            anc[0][i] = parent[i];
        for (int l = 0; l + 1 < L; l++) {
            for (int i = 0; i < n; i++) {
                if (anc[l][i] == -1)
                    continue;
                anc[l + 1][i] = anc[l][anc[l][i]];
            }
        }

        auto solve = [&](int start, int k) {
            if (parent[start] == -1)
                return -1;

            int cur = start;
            for (int l = 0; l < L && cur != -1; l++) {
                int s = 1 << l;
                if (s & k) {
                    cur = anc[l][cur];
                }
            }

            return cur;
        };

        for (auto [start, k, index] : by_end[end])
            ans[index] = solve(start, k);
    }

    for (int &i : ans) {
        if (i != -1)
            i++;

        ps(i);
    }

    return 0;
}