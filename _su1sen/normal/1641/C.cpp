// #pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

#include <limits>
#include <type_traits>

namespace suisen {
// ! utility
template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}

// ! function
template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;

// ! integral
template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool is_nbit_v = is_nbit<T, n>::value;

// ?
template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} // namespace suisen

// ! type aliases
using i128 = __int128_t;
using u128 = __uint128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec <T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;

// ! macros (capital: internal macro)
#define OVERLOAD2(_1,_2,name,...) name
#define OVERLOAD3(_1,_2,_3,name,...) name
#define OVERLOAD4(_1,_2,_3,_4,name,...) name

#define REP4(i,l,r,s)  for(std::remove_reference_t<std::remove_const_t<decltype(r)>>i=(l);i<(r);i+=(s))
#define REP3(i,l,r)    REP4(i,l,r,1)
#define REP2(i,n)      REP3(i,0,n)
#define REPINF3(i,l,s) for(std::remove_reference_t<std::remove_const_t<decltype(l)>>i=(l);;i+=(s))
#define REPINF2(i,l)   REPINF3(i,l,1)
#define REPINF1(i)     REPINF2(i,0)
#define RREP4(i,l,r,s) for(std::remove_reference_t<std::remove_const_t<decltype(r)>>i=(l)+fld((r)-(l)-1,s)*(s);i>=(l);i-=(s))
#define RREP3(i,l,r)   RREP4(i,l,r,1)
#define RREP2(i,n)     RREP3(i,0,n)

#define rep(...)    OVERLOAD4(__VA_ARGS__, REP4   , REP3   , REP2   )(__VA_ARGS__)
#define rrep(...)   OVERLOAD4(__VA_ARGS__, RREP4  , RREP3  , RREP2  )(__VA_ARGS__)
#define repinf(...) OVERLOAD3(__VA_ARGS__, REPINF3, REPINF2, REPINF1)(__VA_ARGS__)

#define CAT_I(a, b) a##b
#define CAT(a, b) CAT_I(a, b)
#define UNIQVAR(tag) CAT(tag, __LINE__)
#define loop(n) for (std::remove_reference_t<std::remove_const_t<decltype(n)>> UNIQVAR(loop_variable) = n; UNIQVAR(loop_variable) --> 0;)

#define all(iterable) (iterable).begin(), (iterable).end()
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

// ! I/O utilities

// pair
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U> &a) {
    return out << a.first << ' ' << a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return out;
    } else {
        out << std::get<N>(a);
        if constexpr (N + 1 < std::tuple_size_v<std::tuple<Args...>>) {
            out << ' ';
        }
        return operator<<<N + 1>(out, a);
    }
}
// vector
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
// array
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head &head, const Tail &...tails) {
    std::cout << head;
    if (sizeof...(tails)) std::cout << ' ';
    print(tails...);
}
template <typename Iterable>
auto print_all(const Iterable& v, std::string sep = " ", std::string end = "\n") -> decltype(std::cout << *v.begin(), void()) {
    for (auto it = v.begin(); it != v.end();) {
        std::cout << *it;
        if (++it != v.end()) std::cout << sep;
    }
    std::cout << end;
}

// pair
template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U> &a) {
    return in >> a.first >> a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}
// vector
template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
// array
template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    ( std::cin >> ... >> args );
}

// ! integral utilities

// Returns pow(-1, n)
template <typename T>
constexpr inline int pow_m1(T n) {
    return -(n & 1) | 1;
}
// Returns pow(-1, n)
template <>
constexpr inline int pow_m1<bool>(bool n) {
    return -int(n) | 1;
}

// Returns floor(x / y)
template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + pow_m1(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + pow_m1(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int floor_log2(const T x) { return suisen::bit_num<T> - 1 - count_lz(x); }
template <typename T>
constexpr inline int ceil_log2(const T x)  { return floor_log2(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int kth_bit(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct all_subset_iter {
        const int s; int t;
        constexpr all_subset_iter(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return all_subset_iter(s); }
    constexpr auto end()   { return nullptr; }
};

// ! container

template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto priqueue_comp(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable &iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto generate_range_vector(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto generate_range_vector(T n) {
    return generate_range_vector(0, n);
}

template <typename T>
void sort_unique_erase(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto foreach_adjacent_values(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto foreach_adjacent_values(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()){
    foreach_adjacent_values(c.begin(), c.end(), f);
}

// ! other utilities

// x <- min(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (y >= x) return false;
    x = y;
    return true;
}
// x <- max(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmax(T &x, const T &y) {
    if (y <= x) return false;
    x = y;
    return true;
}

namespace suisen {}
using namespace suisen;
using namespace std;

struct io_setup {
    io_setup(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} io_setup_ {};

// ! code from here

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

bool op(bool x, bool y) {
    return x & y;
}
bool e() {
    return true;
}
bool mapping(bool f, bool x) {
    return f ? true : x;
}
bool composition(bool f, bool g) {
    return f | g;
}
bool id() {
    return false;
}

#include <tuple>

namespace suisen {

template <typename T, typename UpdateFunc, constraints_t<std::is_invocable<UpdateFunc>> = nullptr>
struct UpdateProxyObject {
    public:
        UpdateProxyObject(T &v, UpdateFunc update) : v(v), update(update) {}
        operator T() const { return v; }
        auto& operator++() && { ++v, update(); return *this; }
        auto& operator--() && { --v, update(); return *this; }
        auto& operator+=(const T &val) && { v += val, update(); return *this; }
        auto& operator-=(const T &val) && { v -= val, update(); return *this; }
        auto& operator*=(const T &val) && { v *= val, update(); return *this; }
        auto& operator/=(const T &val) && { v /= val, update(); return *this; }
        auto& operator%=(const T &val) && { v %= val, update(); return *this; }
        auto& operator =(const T &val) && { v  = val, update(); return *this; }
        auto& operator<<=(const T &val) && { v <<= val, update(); return *this; }
        auto& operator>>=(const T &val) && { v >>= val, update(); return *this; }
        template <typename F, constraints_t<is_uni_op<F, T>> = nullptr>
        auto& apply(F f) && { v = f(v), update(); return *this; }
    private:
        T &v;
        UpdateFunc update;
};

} // namespace suisen

namespace suisen {
template <typename T, T(*op)(T, T), T(*e)()>
class SegmentTree {
    public:
        SegmentTree() : SegmentTree(0) {}
        explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n, e())) {}
        SegmentTree(const std::vector<T> &a) : n(a.size()), m(ceil_pow2(n)), data(2 * m, e()) {
            build(a);
        }

        void build(const std::vector<T> &a) {
            assert(int(a.size()) <= m);
            std::copy(a.begin(), a.end(), data.begin() + m);
            for (int k = m - 1; k > 0; --k) update(k);
        }
        const T& get(int i) const {
            assert(0 <= i and i < n);
            return data[i + m];
        }
        T operator()(int l, int r) const {
            T res_l = e(), res_r = e();
            for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res_l = op(res_l, data[l++]);
                if (r & 1) res_r = op(data[--r], res_r);
            }
            return op(res_l, res_r);
        }
        T prod(int l, int r) const { return (*this)(l, r); }
        T prefix_prod(int r) const { return (*this)(0, r); }
        T suffix_prod(int l) const { return (*this)(l, m); }
        T all_prod() const { return data[1]; }

        void set(int i, const T &val) {
            (*this)[i] = val;
        }
        auto operator[](int i) {
            assert(0 <= i and i < n);
            int k = i + m;
            return UpdateProxyObject { data[k], [this, k]{ update_from(k); } };
        }

        template <typename Pred, constraints_t<is_same_as_invoke_result<bool, Pred, T>> = nullptr>
        int max_right(int l, const Pred &f) const {
            assert(0 <= l and l <= n);
            assert(f(e));
            if (l == n) return n;
            l += m;
            T sum_l = e;
            do {
                while (l % 2 == 0) l >>= 1;
                if (not f(op(sum_l, data[l]))) {
                    while (l < m) {
                        l = 2 * l;
                        if (f(op(sum_l, data[l]))) sum_l = op(sum_l, data[l++]);
                    }
                    return l - m;
                }
                sum_l = op(sum_l, data[l]);
                l++;
            } while ((l & -l) != l);
            return n;
        }
        template <bool(*f)(T)>
        int max_right(int l) { return max_right(l, f); }

        template <typename Pred, constraints_t<is_same_as_invoke_result<bool, Pred, T>> = nullptr>
        int min_left(int r, const Pred &f) const {
            assert(0 <= r && r <= n);
            assert(f(e));
            if (r == 0) return 0;
            r += m;
            T sum_r = e;
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (not f(op(data[r], sum_r))) {
                    while (r < m) {
                        r = 2 * r + 1;
                        if (f(op(data[r], sum_r))) sum_r = op(data[r--], sum_r);
                    }
                    return r + 1 - m;
                }
                sum_r = op(data[r], sum_r);
            } while ((r & -r) != r);
            return 0;
        }
        template <bool(*f)(T)>
        int min_left(int l) { return min_left(l, f); }

    private:
        int n, m;
        std::vector<T> data;

        static constexpr int ceil_pow2(int n) {
            int m = 1;
            while (m < n) m <<= 1;
            return m;
        }
        void update_from(int k) {
            for (k >>= 1; k; k >>= 1) update(k);
        }
        void update(int k) {
            data[k] = op(data[k * 2], data[k * 2 + 1]);
        }
};
} // namespace suisen

namespace suisen {

template <typename T, T(*op)(T, T), T(*e)()>
class SegmentTree2DSparse {
    public:
        SegmentTree2DSparse() {}
        explicit SegmentTree2DSparse(int x_num) : n(x_num + 1), m(ceil_pow2(n)), data(m * 2), points(), pos_x(), pos_y(m * 2) {}

        void add_point(int x, int y) {
            built = false;
            pos_x.push_back(x);
            points.emplace_back(x, y);
        }

        void build() {
            static constexpr int inf = std::numeric_limits<int>::max();
            built = true;
            pos_x.push_back(inf);
            std::sort(pos_x.begin(), pos_x.end());
            pos_x.erase(std::unique(pos_x.begin(), pos_x.end()), pos_x.end());
            assert(int(pos_x.size()) <= n);
            for (const auto &[x, y] : points) {
                for (int k = comp_x(x) + m; k; k >>= 1) pos_y[k].push_back(y);
            }
            for (int k = 1; k < 2 * m; ++k) {
                pos_y[k].push_back(inf);
                std::sort(pos_y[k].begin(), pos_y[k].end());
                pos_y[k].erase(std::unique(pos_y[k].begin(), pos_y[k].end()), pos_y[k].end());
                data[k] = SegmentTree<T, op, e>(pos_y[k].size());
            }
        }

        T prod(int l, int r, int d, int u) const {
            return (*this)(l, r, d, u);
        }
        T operator()(int l, int r, int d, int u) const {
            assert(built);
            T res_l = e(), res_r = e();
            for (l = comp_x(l) + m, r = comp_x(r) + m; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res_l = op(res_l, prod(l++, d, u));
                if (r & 1) res_r = op(prod(--r, d, u), res_r);
            }
            return op(res_l, res_r);
        }
        T all_prod() const {
            assert(built);
            return data[1].all_prod();
        }

        const T& get(int x, int y) const {
            assert(built);
            int i = comp_x(x), j = comp_y(i + m, y);
            assert(pos_x[i] == x and pos_y[i + m][j] == y);
            return data[i + m].get(j);
        }
        void set(int x, int y, const T &val) {
            (*this)[{x, y}] = val;
        }
        auto operator[](const std::pair<int, int> &p) {
            int x, y;
            std::tie(x, y) = p;
            return UpdateProxyObject { const_cast<T&>(get(x, y)), [this, k = comp_x(x) + m, y]{ update_from(k, y); } };
        }

        template <typename Pred, constraints_t<is_same_as_invoke_result<bool, Pred, T>> = nullptr>
        int max_up(int l, int r, int d, const Pred &f) const {
            assert(built);
            int res = std::numeric_limits<int>::max();
            for (l = comp_x(l) + m, r = comp_x(r) + m; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = std::min(res, max_up(l++, d, f));
                if (r & 1) res = std::min(res, max_up(--r, d, f));
            }
            return res;
        }
        template <typename Pred, constraints_t<is_same_as_invoke_result<bool, Pred, T>> = nullptr>
        int min_down(int l, int r, int u, const Pred &f) const {
            assert(built);
            int res = std::numeric_limits<int>::min();
            for (l = comp_x(l) + m, r = comp_x(r) + m; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = std::max(res, min_down(l++, u, f));
                if (r & 1) res = std::max(res, min_down(--r, u, f));
            }
            return res;
        }

    private:
        int n, m;
        std::vector<SegmentTree<T, op, e>> data;
        std::vector<std::pair<int, int>> points;
        std::vector<int> pos_x;
        std::vector<std::vector<int>> pos_y;
        bool built = true;

        static constexpr int ceil_pow2(int n) {
            int m = 1;
            while (m < n) m <<= 1;
            return m;
        }

        int comp_x(int x) const {
            return std::lower_bound(pos_x.begin(), pos_x.end(), x) - pos_x.begin();
        }
        int comp_y(int k, int y) const {
            return std::lower_bound(pos_y[k].begin(), pos_y[k].end(), y) - pos_y[k].begin();
        }

        T prod(int k, int d, int u) const {
            return data[k](comp_y(k, d), comp_y(k, u));
        }

        template <typename Pred, constraints_t<is_same_as_invoke_result<bool, Pred, T>> = nullptr>
        int max_up(int k, int d, const Pred &f) const {
            const int u = data[k].max_right(comp_y(k, d), f);
            return u == int(pos_y[k].size()) ? std::numeric_limits<int>::max() : pos_y[k][u];
        }
        template <typename Pred, constraints_t<is_same_as_invoke_result<bool, Pred, T>> = nullptr>
        int min_down(int k, int u, const Pred &f) const {
            const int d = data[k].min_left(comp_y(k, u), f);
            return d == 0 ? std::numeric_limits<int>::min() : pos_y[k][d - 1] + 1;
        }

        void update(int k, int y) {
            int p = comp_y(k, y);
            assert(pos_y[k][p] == y);
            if (k < m) {
                int l = comp_y(k * 2, y), r = comp_y(k * 2 + 1, y);
                T lv = pos_y[k * 2 + 0][l] == y ? data[k * 2 + 0].get(l) : e();
                T rv = pos_y[k * 2 + 1][r] == y ? data[k * 2 + 1].get(r) : e();
                data[k][p] = op(lv, rv);
            } else {
                data[k][p] = T(data[k][p]);
            }
        }
        void update_from(int k, int y) {
            for (; k; k >>= 1) update(k, y);
        }
};

} // namespace suisen

int8_t op2(int8_t x, int8_t y) {
    return x | y;
}
int8_t e2() {
    return 0;
}

int main() {
    input(int, n, q);

    SegmentTree2DSparse<int8_t, op2, e2> seg1(2 * q);
    vector<tuple<int, int, int, int>> qs(q);
    rep(i, q) {
        input(int, t);
        if (t == 0) {
            input(int, l, r, x);
            --l;
            qs[i] = { t, l, r, x };
            if (x == 1) {
                seg1.add_point(l, r);
            }
        } else {
            input(int, j);
            --j;
            qs[i] = { t, j, -1, -1 };
        }
    }
    seg1.build();

    atcoder::lazy_segtree<bool, op, e, bool, mapping, composition, id> seg(vector<bool>(n, false));

    for (auto &[t, l, r, x] : qs) {
        if (t == 0) {
            if (x == 0) {
                seg.apply(l, r, true);
            } else {
                seg1.set(l, r, true);
            }
        } else {
            int j = l;

            int r = seg.max_right(j + 1, [&](bool e) { return e; });
            int l = seg.min_left(j, [&](bool e) { return e; });

            if (seg.get(j)) {
                print("NO");
            } else if (seg1.prod(l, j + 1, j + 1, r + 1)) {
                print("YES");
            } else {
                print("N/A");
            }
        }
    }
    return 0;
}