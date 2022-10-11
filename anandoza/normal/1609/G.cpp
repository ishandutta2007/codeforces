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
// segment_tree_lazy {{{
#include <vector>
#include <cassert>

template<typename T, typename U,
    typename TAssociativeCombineFunction,
    typename UAssociativeCombineFunction,
    typename UApplicator>
struct segment_tree_lazy {
    int SZ;
    T t_identity;
    U u_identity;
    TAssociativeCombineFunction TT;
    UAssociativeCombineFunction UU;
    UApplicator UT;

    std::vector<T> data;
    std::vector<bool> has_update;
    std::vector<U> updates;

    segment_tree_lazy() {}

    segment_tree_lazy(int _SZ, T _t_identity, U _u_identity,
            TAssociativeCombineFunction _TT, UAssociativeCombineFunction _UU, UApplicator _UT)
            : SZ(_SZ), t_identity(_t_identity), u_identity(_u_identity), TT(_TT), UU(_UU), UT(_UT) {
        data.assign(2 * SZ, t_identity);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

private:
    void apply_update(int i, const U &u) {
        data[i] = UT(u, data[i]);
        if (i < SZ) {
            has_update[i] = true;
            updates[i] = UU(u, updates[i]);
        }
    }

    void propagate_ancestor_updates(int i) {
        for (int ht = 31 - __builtin_clz(i); ht > 0; ht--) {
            int anc = i >> ht;
            if (has_update[anc]) {
                apply_update(2 * anc, updates[anc]);
                apply_update(2 * anc + 1, updates[anc]);
                has_update[anc] = false;
                updates[anc] = u_identity;
            }
        }
    }

    void recompute_ancestors(int i) {
        for (i /= 2; i; i /= 2)
            data[i] = UT(updates[i], TT(data[2 * i], data[2 * i + 1]));
    }

    void modify_leaf(int i, T v, bool overwrite) {
        i += SZ;
        propagate_ancestor_updates(i);
        data[i] = overwrite ? v : TT(data[i], v);
        recompute_ancestors(i);
    }

public:
    // Assigns v at index i
    void assign(int i, T v) {
        modify_leaf(i, v, true);
    }

    // Replaces the current value at index i with TT(current value, v)
    void combine_and_assign(int i, T v) {
        modify_leaf(i, v, false);
    }

    // Applies update u to the elements at indices in [first, last)
    void apply_update(int first, int last, U u) {
        assert(0 <= first && last <= SZ);
        first += SZ, last += SZ;

        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        for (int i = first, j = last; i < j; i /= 2, j /= 2) {
            if (i&1) apply_update(i++, u);
            if (j&1) apply_update(--j, u);
        }

        recompute_ancestors(first);
        recompute_ancestors(last - 1);
    }

    // Accumulates the elements at indices in [first, last)
    T accumulate(int first, int last) {
        assert(0 <= first && last <= SZ);
        first += SZ, last += SZ;

        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        T left = t_identity, right = t_identity;
        for (int i = first, j = last; i < j; i /= 2, j /= 2) {
            if (i&1) left = TT(left, data[i++]);
            if (j&1) right = TT(data[--j], right);
        }
        return TT(left, right);
    }

    // Returns the current value at index i
    T read(int i) {
        i += SZ;
        propagate_ancestor_updates(i);
        return data[i];
    }
};
// }}}
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

// clang-format on

struct T {
    int len = 0;
    ll sum = 0;
    ll sum_times_index = 0;
};

T make(ll x) { return {1, x, x}; }

struct {
    T operator()(const T &l, const T &r) {
        if (r.len == 0)
            return l;
        if (l.len == 0)
            return r;
        return {l.len + r.len, l.sum + r.sum, l.sum_times_index + r.sum_times_index + l.sum * r.len};
    }
} tt;

using U = int;

struct {
    T operator()(const U &u_, const T &t) {
        if (u_ == 0)
            return t;
        ll u = u_;
        return {t.len, t.sum + u * t.len, t.sum_times_index + u * t.len * (t.len + 1) / 2};
    }
} ut;

struct {
    U operator()(const U &l, const U &r) { return l + r; }
} uu;

int main() {
    setIO();

    int n, m;
    re(n, m);
    // n is small!

    int q;
    re(q);

    vll a(n), b(m);
    re(a, b);

    segment_tree_lazy A(n - 1, T{}, U{}, tt, uu, ut);
    A.assign(L1(i, make(a[i + 1] - a[i])));
    segment_tree_lazy B(m - 1, T{}, U{}, tt, uu, ut);
    B.assign(L1(i, make(b[i + 1] - b[i])));

    binary_indexed_tree BIT_A(A.SZ, 0LL, plus<ll>());
    BIT_A.add(0, A.read(0).sum);
    for (int i = 0; i + 1 < A.SZ; i++) {
        BIT_A.add(i + 1, A.read(i + 1).sum - A.read(i).sum);
    }
    binary_indexed_tree BIT_B(B.SZ, 0LL, plus<ll>());
    BIT_B.add(0, B.read(0).sum);
    for (int i = 0; i + 1 < B.SZ; i++) {
        BIT_B.add(i + 1, B.read(i + 1).sum - B.read(i).sum);
    }

    ll start = a[0] + b[0];

    const int S = n + m - 1;

    while (q--) {
        int type, k, d;
        re(type, k, d);

        if (type == 1) {
            if (k == n) {
                k--;
                start += d;
            }
            A.apply_update(A.SZ - k, A.SZ, d);
            BIT_A.add(A.SZ - k, d);
        } else {
            if (k == m) {
                k--;
                start += d;
            }
            B.apply_update(B.SZ - k, B.SZ, d);
            BIT_B.add(B.SZ - k, d);
        }

        ll ans = start * S;
        ll remaining = S - 1;

        int b_consumed = 0;
        for (int i = 0; i < A.SZ; i++) {
            auto x = BIT_A.accumulate_prefix(i + 1);

            int next_b = -1 + BIT_B.binary_search(L1(u, u > x));

            int len = next_b - b_consumed;
            remaining -= len;
            auto b_range = B.accumulate(b_consumed, next_b);
            ans += remaining * b_range.sum + b_range.sum_times_index;
            b_consumed = next_b;

            ans += x * remaining;
            remaining--;
        }

        int next_b = B.SZ;

        int len = next_b - b_consumed;
        remaining -= len;
        auto b_range = B.accumulate(b_consumed, next_b);
        ans += remaining * b_range.sum + b_range.sum_times_index;
        b_consumed = next_b;

        ps(ans);
    }

    return 0;
}