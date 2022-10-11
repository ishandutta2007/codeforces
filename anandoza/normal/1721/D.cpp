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

// clang-format on

int solve_memory(vvi &a, vvi &b, int bit) {
    if (bit == -1)
        return 0;

    vvi next_a, next_b;
    for (int i = 0; i < sz(a); i++) {
        next_a.push_back({});
        next_a.push_back({});
        next_b.push_back({});
        next_b.push_back({});
        for (auto x : a[i]) {
            if ((x >> bit) & 1)
                next_a.end()[-2].push_back(x);
            else
                next_a.end()[-1].push_back(x);
        }
        for (auto x : b[i]) {
            if ((x >> bit) & 1)
                next_b.end()[-1].push_back(x);
            else
                next_b.end()[-2].push_back(x);
        }

        if (next_a.back().size() != next_b.back().size()) {
            next_a.clear(), next_b.clear();
            return solve_memory(a, b, bit - 1);
        }
    }

    a.clear(), b.clear();
    return (1 << bit) | solve_memory(next_a, next_b, bit - 1);
}

int solve_wrong(vi a, vi b, int bit) {
    if (bit == -1)
        return 0;

    assert(a.size() == b.size());

    array<vi, 2> a_split{};
    array<vi, 2> b_split{};
    for (auto x : a)
        a_split[(x >> bit) & 1].push_back(x);
    for (auto x : b)
        b_split[(x >> bit) & 1].push_back(x);

    if (a_split[0].size() == b_split[1].size()) {
        return (1 << bit) |
               min(solve_wrong(a_split[0], b_split[1], bit - 1), solve_wrong(a_split[1], b_split[0], bit - 1));
    }

    return solve_wrong(a, b, bit - 1);
}

int solve_recursive(vi &a, vi &b, vector<pair<int, int>> &p, int bit) {
    if (bit == -1)
        return 0;

    vector<pair<int, int>> next_p(2 * sz(p));
    int index = 0;

    for (auto &[l, r] : p) {
        auto a_it = partition(a.begin() + l, a.begin() + r, L1(x, (x >> bit) & 1));
        auto b_it = partition(b.begin() + l, b.begin() + r, L1(x, !((x >> bit) & 1)));

        if (a_it - a.begin() != b_it - b.begin()) {
            next_p.clear();
            return solve_recursive(a, b, p, bit - 1);
        }

        next_p[index++] = {l, a_it - a.begin()};
        next_p[index++] = {a_it - a.begin(), r};
    }

    p.clear();
    return (1 << bit) | solve_recursive(a, b, next_p, bit - 1);
}

int solve(vi &a, vi &b, vector<int> &p, int bit) {
    int ans = 0;
    while (bit-- > 0) {
        vector<int> next_p{0};

        for (int j = 0; j + 1 < sz(p); j++) {
            auto l = p[j], r = p[j + 1];

            auto a_it = partition(a.begin() + l, a.begin() + r, L1(x, (x >> bit) & 1));
            auto b_it = partition(b.begin() + l, b.begin() + r, L1(x, !((x >> bit) & 1)));

            if (a_it - a.begin() != b_it - b.begin()) {
                goto fail;
            }

            next_p.push_back(a_it - a.begin());
            next_p.push_back(r);
        }

        swap(p, next_p);
        ans |= 1 << bit;

    fail:;
    }

    return ans;
}

void solve() {
    int n;
    re(n);
    vi a(n);
    re(a);
    vi b(n);
    re(b);

    vi p{0, n};
    int bit = 30;
    int ans = 0;
    while (bit-- > 0) {
        vector<int> next_p{0};

        for (int j = 0; j + 1 < sz(p); j++) {
            auto l = p[j], r = p[j + 1];

            auto a_it = partition(a.begin() + l, a.begin() + r, L1(x, (x >> bit) & 1));
            auto b_it = partition(b.begin() + l, b.begin() + r, L1(x, !((x >> bit) & 1)));

            if (a_it - a.begin() != b_it - b.begin()) {
                goto fail;
            }

            if (a_it - a.begin() != next_p.back())
                next_p.push_back(a_it - a.begin());
            if (r != next_p.back())
                next_p.push_back(r);
        }

        swap(p, next_p);
        ans |= 1 << bit;

    fail:;
    }

    ps(ans);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}