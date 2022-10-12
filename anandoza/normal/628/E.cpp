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

// Returns first i in [l, r] s.t. predicate(i) is true. Never evaluates r.
template <typename I, typename P> I binarysearch(const P &predicate, I l, I r) {
    l--;
    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        if (predicate(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main() {
    setIO();

    int n, m;
    re(n, m);
    vector<vector<bool>> g(n, vector<bool>(m));
    {
        for (int i = 0; i < n; i++) {
            string line;
            re(line);
            for (int j = 0; j < m; j++)
                g[i][j] = line[j] == 'z';
        }
    }

    auto slow = [&]() {
        vvi left(n, vi{0});
        for (int i = 0; i < n; i++) {
            for (bool j : g[i]) {
                left[i].push_back(j ? left[i].back() + 1 : 0);
            }
        }

        vvi diag(n + m - 1, vi{0});
        for (int d = 0; d < n + m - 1; d++) {
            for (int x = 0; x <= d; x++) {
                int y = d - x;
                bool v = (x >= n || y >= m) ? 0 : g[x][y];
                diag[d].push_back(v ? diag[d].back() + 1 : 0);
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!g[i][j])
                    continue;
                for (int len = 1; i + len <= n && j + len <= m; len++) {
                    int top = left[i][j + len];
                    int bot = left[i + len - 1][j + len];
                    int d = i + len - 1 + j;
                    int mid = diag[d][i + len];

                    if (top >= len && bot >= len && mid >= len)
                        ans++;
                }
            }
        }

        return ans;
    };

    vvi left(n, vi{0});
    for (int i = 0; i < n; i++) {
        for (bool j : g[i]) {
            left[i].push_back(j ? left[i].back() + 1 : 0);
        }
    }

    vvi diag(n + m - 1, vi{0});
    for (int d = 0; d < n + m - 1; d++) {
        for (int x = max(0, d - m + 1); x <= min(n - 1, d); x++) {
            int y = d - x;
            diag[d].push_back(g[x][y] ? diag[d].back() + 1 : 0);
        }
    }

    ll ans = 0;
    for (int start = 0; start < n + m - 1; start++) {
        segment_tree_persistent st(n + m + 1, 0, std::plus<int>());
        for (int i = max(0, start - m + 1); i < n && i <= start; i++) {
            int j = start - i;

            if (!g[i][j])
                continue;

            int L = left[i][j + 1];
            int R = -1 + binarysearch([&](int r) { return left[i][j + r] < r; }, 0, m - j + 1);
            ckmin(R, diag[start][i + 1 - max(0, start - m + 1)]);

            st.combine_and_assign(i + L - 1, +1, i);
            auto u = st.accumulate(i, n + m + 1, i + 1);
            auto v = st.accumulate(i, n + m + 1, i - R + 1);
            ans += u - v;
        }
    }

    ps(ans);

#ifdef ANAND_LOCAL
    // pd(ans, slow());
    // assert(ans == slow());
#endif

    return 0;
}