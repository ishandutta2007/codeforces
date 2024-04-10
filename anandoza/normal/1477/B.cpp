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

// clang-format on

struct T {
    int sum, len;
};

using U = int;
const U ONE = 1, ZERO = 0, NA = -1;

const string NO = "NO", YES = "YES";

void solve() {
    auto tt = L2(l, r, T{l.sum + r.sum, l.len + r.len});
    auto ut = L2(u, t, u == NA ? t : T{u * t.len, t.len});
    auto uu = L2(l, r, l == NA ? r : r == NA ? l : l);

    int n, q;
    re(n, q);
    string start, end;
    re(start, end);
    vpii ranges(q);
    re(ranges);
    trav (i, ranges) { i.f--; }

    segment_tree_lazy st(n, T{0, 0}, NA, tt, uu, ut);
    for (int i = 0; i < n; i++) {
        st.assign(i, T{end[i] - '0', 1});
    }

    for (auto [l, r] : reversed(ranges)) {
        auto [sum, len] = st.accumulate(l, r);
        if (len == sum * 2) {
            ps(NO);
            return;
        }

        int u = 2 * sum > len ? 1 : 0;
        st.apply_update(l, r, u);
    }

    for (int i = 0; i < n; i++) {
        if (st.read(i).sum != start[i] - '0') {
            ps(NO);
            return;
        }
    }

    ps(YES);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}