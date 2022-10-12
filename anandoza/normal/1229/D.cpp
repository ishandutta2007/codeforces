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
// segment_tree {{{
#include <vector>
#include <cassert>

template<typename T, typename AssociativeOperation>
struct segment_tree {
    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<T> data;

    segment_tree() {}

    segment_tree(int _SZ, T _identity, AssociativeOperation _TT)
            : SZ(_SZ), identity(_identity), TT(_TT) {
        data.resize(2 * SZ, identity);
    }

    // Returns the value at index i
    const T& operator[](int i) const {
        assert(0 <= i && i < SZ);
        return data[SZ + i];
    }

    // Assigns fn(i) at index i for each i in [0, SZ)
    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Assigns v at index i
    void assign(int i, T v) {
        assert(0 <= i && i < SZ);
        data[i += SZ] = v;
        for (i /= 2; i; i /= 2)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Returns the result of a left fold of the elements at indices in [first, last) over TT
    T accumulate(int first, int last) const {
        assert(0 <= first && last <= SZ);
        T left = identity, right = identity;
        for (first += SZ, last += SZ; first < last; first /= 2, last /= 2) {
            if (first & 1) left  = TT(left, data[first++]);
            if (last  & 1) right = TT(data[--last], right);
        }
        return TT(left, right);
    }
};
// }}}
// {{{ data_structures/segment_tree.cpp }}}

#include <cassert>

template<typename T, typename AssociativeOperation>
struct searchable_segment_tree : segment_tree<T, AssociativeOperation> {
    using segment_tree<T, AssociativeOperation>::SZ;
    using segment_tree<T, AssociativeOperation>::identity;
    using segment_tree<T, AssociativeOperation>::TT;
    using segment_tree<T, AssociativeOperation>::data;

    searchable_segment_tree() {}

    /* Rounds up internal size to the next power of 2 to enable binary search.
     */
    searchable_segment_tree(int _SZ, T _identity, AssociativeOperation _TT) :
        segment_tree<T, AssociativeOperation>(1 << (32 - __builtin_clz(_SZ - 1)), _identity, _TT) {}

    /* Returns the smallest index "last" >= first such that p(accumulate(first, last))
     * returns true. Returns SZ + 1 if no such index exists. Requires that
     * p(accumulate(first, last)) is non-decreasing as last increases.
     */
    template<typename Predicate>
    int binary_search(int first, Predicate p) const {
        assert(0 <= first && first <= SZ);

        if (p(identity))
            return first;

        first += SZ;

        T accumulator = identity;

        auto try_extend = [&](int bit) {
            assert(__builtin_ctz(first) >= bit);

            if (first + (1 << bit) > 2 * SZ)
                return false;

            T extended = TT(accumulator, data[first >> bit]);

            if (p(extended))
                return false;

            accumulator = extended;
            first += 1 << bit;
            return true;
        };

        int bit = 0;

        while (!(first & (1 << bit)) || try_extend(bit))
            bit++;

        while (--bit >= 0)
            try_extend(bit);

        return first - SZ + 1;
    }
};

// clang-format on

constexpr int Z = 5;
using P = array<int, Z>;
constexpr int F = 120;
using B = bitset<F>;

int main() {
    setIO();

    vector<P> permutations;
    {
        P p;
        iota(all(p), 0);
        do {
            permutations.push_back(p);
        } while (next_permutation(all(p)));
    }
    assert(sz(permutations) == F);

    auto get_permutation = [&](int i) { return permutations[i]; };
    auto get_id = [&](P p) { return index(permutations, p); };

    auto compose_permutations = [](const P &first, const P &second) {
        P res;
        for (int i = 0; i < Z; i++) {
            res[i] = second[first[i]];
        }
        return res;
    };
    auto compose = [&](int first, int second) {
        return get_id(compose_permutations(get_permutation(first), get_permutation(second)));
    };
    vvi compose_array(F, vi(F));
    for (int i = 0; i < F; i++)
        for (int j = 0; j < F; j++)
            compose_array[i][j] = compose(i, j);

    B IDENTITY;
    IDENTITY[0] = 1;

    auto create = [&](int i) -> B {
        B res = IDENTITY;
        res[i] = 1;
        vi powers;
        powers.push_back(0);
        powers.push_back(i);
        while (powers.back() != powers.front()) {
            powers.push_back(compose_array[powers.back()][i]);
        }
        for (int p : powers)
            res[p] = 1;
        return res;
    };

    auto to_int = [](const B &b) {
        __int128 res = 0;
        for (int i = 0; i < F; i++) {
            res = 2 * res + b[i];
        }
        return res;
    };

    map<pair<__int128, int>, B> cache;
    auto closure = [&](const B &l, const int i) -> B {
        auto key = mp(to_int(l), i);
        if (cache.count(key))
            return cache[key];

        vi powers;
        powers.push_back(0);
        powers.push_back(i);
        while (powers.back() != powers.front()) {
            powers.push_back(compose_array[powers.back()][i]);
        }

        B cur = l;
        for (int p : powers)
            cur[p] = 1;
        B next{};
        do {
            for (int j = 0; j < F; j++) {
                for (int t = 0; t < F; t++) {
                    if (cur[j] && cur[t])
                        next[compose_array[j][t]] = 1;
                }
            }
            swap(next, cur);
        } while (next != cur);

        cache[key] = cur;
        return cur;
    };

    int n, k;
    re(n, k);

    vi a;
    for (int i = 0; i < n; i++) {
        P p;
        for (int j = 0; j < Z; j++) {
            if (j < k) {
                re(p[j]);
                p[j]--;
            } else {
                p[j] = j;
            }
        }
        a.push_back(get_id(p));
    }

    searchable_segment_tree ors(n, B{}, std::bit_or<B>());
    for (int i = 0; i < n; i++)
        ors.assign(i, create(a[i]));

    auto solve = [&](int left, int right) -> ll {
        ll ans = 0;
        for (int l = left; l < right; l++) {
            B res = create(a[l]);
            int r = l + 1;

            auto contains_new = [&](const B &b) -> bool { return (res | b) != res; };

            while (true) {
                int next_r = ors.binary_search(r, contains_new);
                next_r = min(right + 1, next_r);
                ans += ll(next_r - r) * res.count();
                if (next_r == right + 1)
                    break;
                res = closure(res, a[next_r - 1]);
                r = next_r;
            }
        }
        return ans;
    };

    ll ans = solve(0, n);
    ps(ans);

    return 0;
}