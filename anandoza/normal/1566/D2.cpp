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
// binary_indexed_tree {{{
#include <iterator>
#include <vector>
#include <cassert>
#include <functional>

template<typename T, typename AssociativeOperation, typename InverseOperation = std::nullptr_t>
struct binary_indexed_tree {
    int SZ;
    T identity;
    AssociativeOperation TT;
    InverseOperation S;
    std::vector<T> data;

    binary_indexed_tree() {}

    binary_indexed_tree(int _SZ, T _identity, AssociativeOperation _TT, InverseOperation _S = nullptr)
            : SZ(_SZ), identity(_identity), TT(_TT), S(_S) {
        data.assign(2 * SZ, identity);
    }

    // Replaces the current value at index i with TT(current value, v)
    void add(int i, T v) {
        for (i++; i <= SZ; i += i & -i)
            data[i] = TT(data[i], v);
    }

    // Replaces the element at index i with v. Requires InverseOperation to be defined.
    void replace(int i, T v) {
        static_assert(!std::is_same<decltype(S), std::nullptr_t>::value, "InverseOperation not defined.");
        add(i, S(v, get(i)));
    }

    // Returns the value at index i. Requires InverseOperation to be defined.
    T get(int i) const {
        static_assert(!std::is_same<decltype(S), std::nullptr_t>::value, "InverseOperation not defined.");
        return accumulate(i, i + 1);
    }

    // Returns the result of accumulating the elements at indices in [0, len)
    T accumulate_prefix(int len) const {
        assert(0 <= len && len <= SZ);
        T res = identity;
        for (; len; len -= len & -len)
            res = TT(res, data[len]);
        return res;
    }

    // Returns the result of accumulating the elements at indices in [l, r). Requires InverseOperation be defined.
    T accumulate(int l, int r) const {
        static_assert(!std::is_same<decltype(S), std::nullptr_t>::value, "InverseOperation not defined.");
        return l > r ? identity : S(accumulate_prefix(r), accumulate_prefix(l));
    }

    /* Returns the smallest len in [0, S] such that p(accumulate_prefix(len)) returns true.
     * Returns S + 1 if no such len exists.
     * Requires that p(accumulate_prefix(len)) is non-decreasing in len.
     */
    template<typename Predicate>
    int binary_search(Predicate p) const {
        if (p(identity)) return 0;

        int len = 0;
        T accumulator = identity;

        for (int bit = 31 - __builtin_clz(SZ); bit >= 0; bit--) {
            int next = len + (1 << bit);
            if (next > SZ) continue;

            T combined = TT(accumulator, data[next]);
            if (!p(combined)) {
                len = next;
                accumulator = combined;
            }
        }

        return len + 1;
    }
};
// }}}

// clang-format on

void solve() {
    int n, m;
    re(n, m);

    const int S = n * m;

    vi a(S);
    re(a);

    map<int, vi> pos;
    {
        vi copy = a;
        sort(all(copy));
        for (int i = 0; i < sz(a); i++) {
            pos[copy[i]].push_back(i);
        }
    }

    auto comp = [&](int l, int r) {
        if (l / m != r / m)
            return l / m < r / m;
        return l % m > r % m;
    };
    for (auto &[k, v] : pos) {
        sort(rall(v), comp);
    }

    using BIT = binary_indexed_tree<int, std::plus<int>, std::minus<int>>;
    vector<BIT> bits(n, BIT(m, 0, plus<int>(), minus<int>()));

    ll ans = 0;
    for (int v : a) {
        int i = pos[v].back();
        pos[v].pop_back();

        int row = i / m, col = i % m;

        ans += bits[row].accumulate(0, col);
        bits[row].add(col, 1);
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