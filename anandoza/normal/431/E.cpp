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

// Returns first i in [l, r] s.t. predicate(i) is true. Never evaluates r.
template <typename I, typename P> I binarysearch(const P &predicate, I l, I r, int iter = 100) {
    l--;
    while (iter--) {
        auto mid = l + (r - l) / 2;
        if (predicate(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

template <typename T> struct compress {
    vector<T> values;

    template <typename I> compress(I begin, I end) {
        values = {begin, end};
        sort(all(values));
        values.erase(unique(all(values)), values.end());
    }

    int get_index(const T &t) const { return lower_bound(all(values), t) - values.begin(); }

    T get_value(const int i) const { return values[i]; };
};

struct operation {
    int t, p, x;
    ll v;
};

int main() {
    setIO();

    int n, q;
    re(n, q);
    vi h(n);
    re(h);

    vector<operation> ops(q);
    vector<int> values(h);
    for (auto &[t, p, x, v] : ops) {
        re(t);
        if (t == 1) {
            re(p, x);
            p--;

            values.push_back(x);
        } else {
            re(v);
        }
    }
    compress<int> c(all(values));
    const int C = c.values.size();

    binary_indexed_tree count(C, 0, plus<int>());
    binary_indexed_tree sum(C, 0LL, plus<ll>());

    vi a;
    for (int x : h)
        a.push_back(c.get_index(x));
    for (int x : a) {
        count.add(x, 1);
        sum.add(x, c.get_value(x));
    }

    auto update = [&](int i, int x) {
        count.add(a[i], -1);
        sum.add(a[i], -c.get_value(a[i]));
        a[i] = x;
        count.add(a[i], 1);
        sum.add(a[i], c.get_value(a[i]));
    };

    for (auto [t, p, x, v] : ops) {
        if (t == 1) {
            update(p, c.get_index(x));
        } else {
            ll v_ = v;
            double ans = binarysearch<double>(
                [&](double threshold) {
                    int t_index = upper_bound(all(c.values), threshold) - c.values.begin();
                    return (threshold * count.accumulate_prefix(t_index) - sum.accumulate_prefix(t_index)) >= v_;
                },
                0, 1e15);
            ps(ans);
        }
    }

    return 0;
}