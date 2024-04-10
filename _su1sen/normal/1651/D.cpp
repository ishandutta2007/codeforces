#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
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

#include <map>

namespace suisen {

template <typename T, bool merge_adjacent_segment = true>
struct RangeSet : public std::map<T, T> {
    public:
        RangeSet() : _size(0) {}

        // returns the number of intergers in this set (not the number of ranges). O(1)
        T size() const { return number_of_elements(); }
        // returns the number of intergers in this set (not the number of ranges). O(1)
        T number_of_elements() const { return _size; }
        // returns the number of ranges in this set (not the number of integers). O(1)
        int number_of_ranges() const { return std::map<T, T>::size(); }

        // returns whether the given integer is in this set or not. O(log N)
        bool contains(T x) const {
            auto it = this->upper_bound(x);
            return it != this->begin() and x <= std::prev(it)->second;
        }

        /**
         * returns the iterator pointing to the range [l, r] in this set s.t. l <= x <= r.
         * if such a range does not exist, returns `end()`.
         * O(log N)
         */
        auto find_range(T x) const {
            auto it = this->upper_bound(x);
            return it != this->begin() and x <= (--it)->second ? it : this->end();
        }

        // returns whether `x` and `y` is in this set and in the same range. O(log N)
        bool in_the_same_range(T x, T y) const {
            auto it = get_containing_range(x);
            return it != this->end() and it->first <= y and y <= it->second;
        }

        // inserts the range [x, x] and returns the number of integers inserted to this set. O(log N)
        T insert(T x) {
            return insert(x, x);
        }
        
        // inserts the range [l, r] and returns the number of integers inserted to this set. amortized O(log N)
        T insert(T l, T r) {
            if (l > r) return 0;
            auto it = this->upper_bound(l);
            if (it != this->begin() and is_mergeable(std::prev(it)->second, l)) {
                it = std::prev(it);
                l = std::min(l, it->first);
            }
            T inserted = 0;
            for (; it != this->end() and is_mergeable(r, it->first); it = std::map<T, T>::erase(it)) {
                auto [cl, cr] = *it; 
                r = std::max(r, cr);
                inserted -= cr - cl + 1;
            }
            inserted += r - l + 1;
            (*this)[l] = r;
            _size += inserted;
            return inserted;
        }

        // erases the range [x, x] and returns the number of intergers erased from this set. O(log N)
        T erase(T x) {
            return erase(x, x);
        }

        // erases the range [l, r] and returns the number of intergers erased from this set. amortized O(log N)
        T erase(T l, T r) {
            if (l > r) return 0;
            T tl = l, tr = r;
            auto it = this->upper_bound(l);
            if (it != this->begin() and l <= std::prev(it)->second) {
                it = std::prev(it);
                tl = it->first;
            }
            T erased = 0;
            for (; it != this->end() and it->first <= r; it = std::map<T, T>::erase(it)) {
                auto [cl, cr] = *it;
                tr = cr;
                erased += cr - cl + 1;
            }
            if (tl < l) {
                (*this)[tl] = l - 1;
                erased -= l - tl;
            }
            if (r < tr) {
                (*this)[r + 1] = tr;
                erased -= tr - r;
            }
            _size -= erased;
            return erased;
        }

        // returns minimum integer x s.t. x >= lower and x is NOT in this set
        T minimum_excluded(T lower = 0) const {
            static_assert(merge_adjacent_segment);
            auto it = find_range(lower);
            return it == this->end() ? lower : it->second + 1;
        }

        // returns maximum integer x s.t. x <= upper and x is NOT in this set
        T maximum_excluded(T upper) const {
            static_assert(merge_adjacent_segment);
            auto it = find_range(upper);
            return it == this->end() ? upper : it->first - 1;
        }

    private:
        T _size;

        bool is_mergeable(T cur_r, T next_l) {
            return next_l <= cur_r + merge_adjacent_segment;
        }
};

} // namespace suisen

constexpr int B = 200000;
constexpr int M = 10000000;

#include <cassert>
#include <array>

#include <cstdint>
#include <vector>

namespace suisen {
    class BitVector {
        using u8 = std::uint8_t;
    public:
        explicit BitVector(int n) : n(n), nl((n >> LOG_BLOCK_L) + 1), ns((n >> LOG_BLOCK_S) + 1), cum_l(nl, 0), cum_s(ns, 0), bits(ns, 0) {}
        BitVector() : BitVector(0) {}
        template <typename Gen, constraints_t<is_same_as_invoke_result<bool, Gen, int>> = nullptr>
        BitVector(int n, Gen gen) : BitVector(n) {
            build(gen);
        }
        BitVector& operator=(const BitVector& bv) {
            n = bv.n, nl = bv.nl, ns = bv.ns, cum_l = bv.cum_l, cum_s = bv.cum_s, bits = bv.bits;
            return *this;
        }
        BitVector& operator=(BitVector&& bv) {
            n = bv.n, nl = bv.nl, ns = bv.ns, cum_l = std::move(bv.cum_l), cum_s = std::move(bv.cum_s), bits = std::move(bv.bits);
            return *this;
        }
        template <typename Gen, constraints_t<is_same_as_invoke_result<bool, Gen, int>> = nullptr>
        void build(Gen gen) {
            int i = 0;
            for (int index_s = 1; index_s < ns; ++index_s) {
                int count = cum_s[index_s - 1];
                for (; i < index_s << LOG_BLOCK_S; ++i) {
                    bool b = gen(i);
                    bits[index_s - 1] |= b << (i & MASK_S);
                    count += b;
                }
                if (index_s & ((1 << (LOG_BLOCK_L - LOG_BLOCK_S)) - 1)) {
                    cum_s[index_s] = count;
                } else {
                    int index_l = i >> LOG_BLOCK_L;
                    cum_l[index_l] = cum_l[index_l - 1] + count;
                }
            }
            for (; i < n; ++i) bits[ns - 1] |= gen(i) << (i & MASK_S);
        }
        inline bool operator[](int i) const {
            return (bits[i >> LOG_BLOCK_S] >> (i & MASK_S)) & 1;
        }
        // returns the i'th val (i: 0-indexed)
        inline bool access(int i) const {
            return (*this)[i];
        }
        // returns the number of val in [0, i)
        inline int rank(bool val, int i) const {
            int res_1 = cum_l[i >> LOG_BLOCK_L] + cum_s[i >> LOG_BLOCK_S] + popcount8(bits[i >> LOG_BLOCK_S] & ((1 << (i & MASK_S)) - 1));
            return val ? res_1 : i - res_1;
        }
        // returns the number of val in [l, r)
        inline int rank(bool val, int l, int r) const {
            return rank(val, r) - rank(val, l);
        }
        // find the index of num'th val. (num: 1-indexed). if not exists, returns default_value.
        int select(bool val, int num, int default_value = -1) const {
            int l = -1, r = n + 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                (rank(val, m) >= num ? r : l) = m;
            }
            return r == n + 1 ? default_value : r;
        }
    private:
        static constexpr int LOG_BLOCK_L = 8;
        static constexpr int LOG_BLOCK_S = 3;
        static constexpr int MASK_S = (1 << LOG_BLOCK_S) - 1;

        int n, nl, ns;
        std::vector<int> cum_l;
        std::vector<u8> cum_s, bits;

        static constexpr u8 popcount8(u8 x) {
            x = (x & 0b01010101) + ((x >> 1) & 0b01010101);
            x = (x & 0b00110011) + ((x >> 2) & 0b00110011);
            return (x & 0b00001111) + (x >> 4);
        }
    };
} // namespace suisen

namespace suisen {
    template <typename T, int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits>
    struct WaveletMatrix {
        // default constructor
        WaveletMatrix() noexcept : n(0) {}
        // builds WaveletMatrix from generating function typed as (int) -> T
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        WaveletMatrix(int n, Gen generator) : n(n) {
            build(generator);
        }
        // builds WaveletMatrix from vector
        template <typename U, constraints_t<std::is_constructible<T, U>> = nullptr>
        WaveletMatrix(const std::vector<U>& a) : WaveletMatrix(a.size(), [&a](int i) { return T(a[i]); }) {}

        // builds WaveletMatrix from generating function typed as (int) -> T
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        void build(Gen generator) {
            std::vector<T> a(n), l(n), r(n);
            for (int i = 0; i < n; ++i) a[i] = generator(i);
            for (int log = bit_num - 1; log >= 0; --log) {
                bv[log] = BitVector(n, [&a, log](int i) -> bool { return (a[i] >> log) & 1; });
                int li = 0, ri = 0;
                for (int i = 0; i < n; ++i) {
                    ((a[i] >> log) & 1 ? r[ri++] : l[li++]) = a[i];
                }
                a.swap(l);
                std::copy(r.begin(), r.begin() + ri, a.begin() + li);
                mid[log] = li;
            }
        }
        // returns WaveletMatrix[i]
        T operator[](int i) const {
            T res = 0;
            for (int log = bit_num - 1; log >= 0; --log) {
                bool b = bv[log][i];
                res |= T(b) << log;
                i = b * mid[log] + bv[log].rank(b, i);
            }
            return res;
        }
        // returns WaveletMatrix[i]
        inline T access(int i) const {
            return (*this)[i];
        }
        // returns the number of `val` in WaveletMatrix[0, i).
        int rank(T val, int i) const {
            check_value_bounds(val);
            int l = 0, r = i;
            for (int log = bit_num - 1; log >= 0; --log) succ(l, r, (val >> log) & 1, log);
            return r - l;
        }
        // returns the k'th smallest value in WaveletMatrix[l, r) (k : 0-indexed)
        T range_kth_smallest(int l, int r, int k, T default_value = T(-1)) const {
            if (k < 0 or k >= r - l) return default_value;
            T res = 0;
            for (int log = bit_num - 1; log >= 0; --log) {
                int cnt_0 = bv[log].rank(false, l, r);
                bool bit = k >= cnt_0;
                succ(l, r, bit, log);
                res |= T(bit) << log;
                k -= bit * cnt_0;
            }
            return res;
        }
        // returns the k'th largest value in WaveletMatrix[l, r) (k : 0-indexed)
        inline T range_kth_largest(int l, int r, int k, T default_value = T(-1)) const {
            return range_kth_smallest(l, r, r - l - 1 - k, default_value);
        }
        // returns the minimum value in WaveletMatrix[l, r)
        inline T range_min(int l, int r) const {
            assert(l < r);
            return range_kth_smallest(l, r, 0);
        }
        // returns the maximum value in WaveletMatrix[l, r)
        inline T range_max(int l, int r) const {
            assert(l < r);
            return range_kth_largest(l, r, 0);
        }
        // returns the number of v in WaveletMatrix[l, r) s.t. v < upper
        int range_freq(int l, int r, T upper) const {
            if (r <= l) return 0;
            check_value_bounds(upper);
            int res = 0;
            for (int log = bit_num - 1; log >= 0; --log) {
                bool b = (upper >> log) & 1;
                if (b) res += bv[log].rank(false, l, r);
                succ(l, r, b, log);
            }
            return res;
        }
        // returns the number of v in WaveletMatrix[l, r) s.t. lower <= v < upper
        inline int range_freq(int l, int r, T lower, T upper) const {
            if (lower >= upper) return 0;
            return range_freq(l, r, upper) - range_freq(l, r, lower);
        }
        // returns the minimum value v in WaveletMatrix[l, r) s.t. lower <= v
        inline T range_min_geq(int l, int r, T lower, T default_value = T(-1)) const {
            int cnt = range_freq(l, r, lower);
            return cnt >= r - l ? default_value : range_kth_smallest(l, r, cnt);
        }
        // returns the minimum value v in WaveletMatrix[l, r) s.t. lower < v
        inline T range_min_gt(int l, int r, T lower, T default_value = T(-1)) const {
            return lower == MAX ? default_value : range_min_geq(l, r, lower + 1);
        }
        // returns the maximum value v in WaveletMatrix[l, r) s.t. v < upper
        inline T range_max_lt(int l, int r, T upper, T default_value = T(-1)) const {
            int cnt = range_freq(l, r, upper);
            return cnt == 0 ? default_value : range_kth_smallest(l, r, cnt - 1);
        }
        // returns the maximum value v in WaveletMatrix[l, r) s.t. v <= upper
        inline T range_max_leq(int l, int r, T upper, T default_value = T(-1)) const {
            if (r >= l) return default_value;
            return upper == MAX ? range_max(l, r) : range_max_lt(l, r, upper + 1);
        }
    protected:
        WaveletMatrix(int n) noexcept : n(n) {}
    private:
        static_assert(bit_num > 0);
        static constexpr T MAX = bit_num == std::numeric_limits<T>::digits ? std::numeric_limits<T>::max() : (T(1) << bit_num) - 1;

        int n;
        std::array<BitVector, bit_num> bv;
        std::array<int, bit_num> mid;

        inline void succ(int& l, int& r, const bool b, const int log) const {
            l = b * mid[log] + bv[log].rank(b, l);
            r = b * mid[log] + bv[log].rank(b, r);
        }

        static constexpr void check_value_bounds(T val) {
            assert((val >> bit_num) == 0);
        }
    };
} // namespace suisen

#include <algorithm>

namespace suisen {
template <typename T>
class CoordinateCompressorBuilder {
    public:
        struct Compressor {
            public:
                static constexpr int absent = -1;

                // default constructor
                Compressor() : _xs(std::vector<T>{}) {}
                // Construct from strictly sorted vector
                Compressor(const std::vector<T> &xs) : _xs(xs) {
                    assert(is_strictly_sorted(xs));
                }

                // Return the number of distinct keys.
                int size() const {
                    return _xs.size();
                }
                // Check if the element is registered.
                bool has_key(const T &e) const {
                    return std::binary_search(_xs.begin(), _xs.end(), e);
                }
                // Compress the element. if not registered, returns `default_value`. (default: Compressor::absent)
                int comp(const T &e, int default_value = absent) const {
                    const int res = min_geq_index(e);
                    return res != size() and _xs[res] == e ? res : default_value;
                }
                // Restore the element from the index.
                T decomp(const int compressed_index) const {
                    return _xs[compressed_index];
                }
                // Compress the element. Equivalent to call `comp(e)`
                int operator[](const T &e) const {
                    return comp(e);
                }
                // Return the minimum registered value greater than `e`. if not exists, return `default_value`.
                T min_gt(const T &e, const T &default_value) const {
                    auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
                    return it == _xs.end() ? default_value : *it;
                }
                // Return the minimum registered value greater than or equal to `e`. if not exists, return `default_value`.
                T min_geq(const T &e, const T &default_value) const {
                    auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
                    return it == _xs.end() ? default_value : *it;
                }
                // Return the maximum registered value less than `e`. if not exists, return `default_value`
                T max_lt(const T &e, const T &default_value) const {
                    auto it = std::upper_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>());
                    return it == _xs.rend() ? default_value : *it;
                }
                // Return the maximum registered value less than or equal to `e`. if not exists, return `default_value`
                T max_leq(const T &e, const T &default_value) const {
                    auto it = std::lower_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>());
                    return it == _xs.rend() ? default_value : *it;
                }
                // Return the compressed index of the minimum registered value greater than `e`. if not exists, return `compressor.size()`.
                int min_gt_index(const T &e) const {
                    return std::upper_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
                }
                // Return the compressed index of the minimum registered value greater than or equal to `e`. if not exists, return `compressor.size()`.
                int min_geq_index(const T &e) const {
                    return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
                }
                // Return the compressed index of the maximum registered value less than `e`. if not exists, return -1.
                int max_lt_index(const T &e) const {
                    return int(_xs.rend() - std::upper_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>())) - 1;
                }
                // Return the compressed index of the maximum registered value less than or equal to `e`. if not exists, return -1.
                int max_leq_index(const T &e) const {
                    return int(_xs.rend() - std::lower_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>())) - 1;
                }
            private:
                std::vector<T> _xs;
                static bool is_strictly_sorted(const std::vector<T> &v) {
                    return std::adjacent_find(v.begin(), v.end(), std::greater_equal<T>()) == v.end();
                }
        };
        CoordinateCompressorBuilder() : _xs(std::vector<T>{}) {}
        explicit CoordinateCompressorBuilder(const std::vector<T> &xs) : _xs(xs) {}
        explicit CoordinateCompressorBuilder(std::vector<T> &&xs) : _xs(std::move(xs)) {}
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        CoordinateCompressorBuilder(const int n, Gen generator) {
            reserve(n);
            for (int i = 0; i < n; ++i) push(generator(i));
        }
        // Attempt to preallocate enough memory for specified number of elements.
        void reserve(int n) {
            _xs.reserve(n);
        }
        // Add data.
        void push(const T &first) {
            _xs.push_back(first);
        }
        // Add data.
        void push(T &&first) {
            _xs.push_back(std::move(first));
        }
        // Add data in the range of [first, last). 
        template <typename Iterator>
        auto push(const Iterator &first, const Iterator &last) -> decltype(std::vector<T>{}.push_back(*first), void()) {
            for (auto it = first; it != last; ++it) _xs.push_back(*it);
        }
        // Add all data in the container. Equivalent to `push(iterable.begin(), iterable.end())`.
        template <typename Iterable>
        auto push(const Iterable &iterable) -> decltype(std::vector<T>{}.push_back(*iterable.begin()), void()) {
            push(iterable.begin(), iterable.end());
        }
        // Add data.
        template <typename ...Args>
        void emplace(Args &&...args) {
            _xs.emplace_back(std::forward<Args>(args)...);
        }
        // Build compressor.
        auto build() {
            std::sort(_xs.begin(), _xs.end()), _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());
            return Compressor {_xs};
        }
        // Build compressor from vector.
        static auto build(const std::vector<T> &xs) {
            return CoordinateCompressorBuilder(xs).build();
        }
        // Build compressor from vector.
        static auto build(std::vector<T> &&xs) {
            return CoordinateCompressorBuilder(std::move(xs)).build();
        }
        // Build compressor from generator.
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        static auto build(const int n, Gen generator) {
            return CoordinateCompressorBuilder<T>(n, generator).build();
        }
    private:
        std::vector<T> _xs;
};

} // namespace suisen

namespace suisen {
    template <typename T, int log_max_len = std::numeric_limits<std::make_unsigned_t<T>>::digits>
    struct CompressedWaveletMatrix : public WaveletMatrix<int, log_max_len> {
        // default constructor
        CompressedWaveletMatrix() noexcept : WaveletMatrix<int, log_max_len>(0) {}
        // builds WaveletMatrix from generating function typed as (int) -> T
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        CompressedWaveletMatrix(int n, Gen generator) : WaveletMatrix<int, log_max_len>(n), comp(CoordinateCompressorBuilder<T>::build(n, generator)) {
            this->build([this, &generator](int i) { return comp[generator(i)]; });
        }
        // builds WaveletMatrix from vector
        template <typename U, constraints_t<std::is_constructible<T, U>> = nullptr>
        CompressedWaveletMatrix(const std::vector<U>& a) : CompressedWaveletMatrix(a.size(), [&a](int i) { return T(a[i]); }) {}

        // returns WaveletMatrix[i]
        inline T operator[](int i) const {
            return comp.decomp(WaveletMatrix<int, log_max_len>::operator[](i));
        }
        // returns WaveletMatrix[i]
        inline T access(int i) const {
            return (*this)[i];
        }
        // returns the number of `val` in WaveletMatrix[0, i).
        inline int rank(T val, int i) const {
            int x = comp.comp(val, -1);
            if (x == -1) return 0;
            return WaveletMatrix<int, log_max_len>::rank(x, i);
        }
        // returns the k'th smallest value in WaveletMatrix[l, r) (k : 0-indexed)
        inline T range_kth_smallest(int l, int r, int k, T default_value = T(-1)) const {
            int x = WaveletMatrix<int, log_max_len>::range_kth_smallest(l, r, k, -1);
            return x == -1 ? default_value : comp.decomp(x);
        }
        // returns the k'th largest value in WaveletMatrix[l, r) (k : 0-indexed)
        inline T range_kth_largest(int l, int r, int k, T default_value = T(-1)) const {
            int x = WaveletMatrix<int, log_max_len>::range_kth_largest(l, r, k, -1);
            return x == -1 ? default_value : comp.decomp(x);
        }
        // returns the minimum value in WaveletMatrix[l, r)
        inline T range_min(int l, int r) const {
            return comp.decomp(WaveletMatrix<int, log_max_len>::range_min(l, r));
        }
        // returns the maximum value in WaveletMatrix[l, r)
        inline T range_max(int l, int r) const {
            return comp.decomp(WaveletMatrix<int, log_max_len>::range_max(l, r));
        }
        // returns the number of v in WaveletMatrix[l, r) s.t. v < upper
        inline int range_freq(int l, int r, T upper) const {
            return WaveletMatrix<int, log_max_len>::range_freq(l, r, comp.min_geq_index(upper));
        }
        // returns the number of v in WaveletMatrix[l, r) s.t. lower <= v < upper
        inline int range_freq(int l, int r, T lower, T upper) const {
            if (lower >= upper) return 0;
            return range_freq(l, r, upper) - range_freq(l, r, lower);
        }
        // returns the minimum value v in WaveletMatrix[l, r) s.t. lower <= v
        inline T range_min_geq(int l, int r, T lower, T default_value = T(-1)) const {
            int x = WaveletMatrix<int, log_max_len>::range_min_geq(l, r, comp.min_geq_index(lower), -1);
            return x == -1 ? default_value : comp.decomp(x);
        }
        // returns the minimum value v in WaveletMatrix[l, r) s.t. lower < v
        inline T range_min_gt(int l, int r, T lower, T default_value = T(-1)) const {
            return lower == std::numeric_limits<T>::max() ? default_value : range_min_geq(l, r, lower + 1, default_value);
        }
        // returns the maximum value v in WaveletMatrix[l, r) s.t. v < upper
        inline T range_max_lt(int l, int r, T upper, T default_value = T(-1)) const {
            int x = WaveletMatrix<int, log_max_len>::range_max_lt(l, r, comp.min_geq_index(upper), -1);
            return x == -1 ? default_value : comp.decomp(x);
        }
        // returns the maximum value v in WaveletMatrix[l, r) s.t. v <= upper
        inline T range_max_leq(int l, int r, T upper, T default_value = T(-1)) const {
            if (r >= l) return default_value;
            return upper == std::numeric_limits<T>::max() ? range_max(l, r) : range_max_lt(l, r, upper + 1, default_value);
        }
    private:
        typename CoordinateCompressorBuilder<T>::Compressor comp;
    };
} // namespace suisen

int main() {
    input(int, n);
    vector<pair<int, int>> ps(n);

    vector<vector<int>> mp_u(3 * B + 1), mp_v(3 * B + 1);

    rep(i, n) {
        input(int, x, y);
        int u = x + y + B;
        int v = x - y + B;
        ps[i] = { u, v };
        mp_u[u].push_back((v - (u & 1)) / 2);
        mp_v[v].push_back((u - (v & 1)) / 2);
    }

    auto sorted = ps;
    sort(all(sorted));

    vector<int> vs;
    for (const auto &[u, v] : sorted) vs.push_back(v);
    CompressedWaveletMatrix<int, 18> wm(vs);

    auto rect_count = [&](int lu, int ru, int lv, int rv) {
        ++ru, ++rv;
        chmax(lv, 0);
        int il = lower_bound(all(sorted), make_pair(lu, -M)) - sorted.begin();
        int ir = lower_bound(all(sorted), make_pair(ru, -M)) - sorted.begin();
        return wm.range_freq(il, ir, lv, rv);
    };

    for (auto &v : mp_u) sort(all(v));
    for (auto &v : mp_v) sort(all(v));

    rep(i, n) {
        auto [u, v] = ps[i];

        int dl = 0, dr = 320;
        while (dr - dl > 1) {
            int d = (dl + dr) >> 1;

            int c = rect_count(u - d, u + d, v - d, v + d);
            if (c == 2 * d * d + 2 * d + 1) {
                dl = d;
            } else {
                dr = d;
            }
        }

        int d = dr;

        int ans_u = M, ans_v = M;
        for (int u2 : { u - d, u + d }) {
            int min_v = v - d, max_v = v + d;
            int min_idx = (min_v - (u2 & 1)) / 2;
            int max_idx = (max_v - (u2 & 1)) / 2;

            int empty_idx;
            if (u2 < 0 or u2 > 3 * B) {
                empty_idx = min_idx;
            } else {
                auto itl = lower_bound(all(mp_u[u2]), min_idx);
                auto itr = itl + min(int(mp_u[u2].end() - itl), d + 1);
                int c = itr - itl;
                if (c == d + 1 and *(itr - 1) == max_idx) continue;
                rep(i, d + 1) {
                    if (itl == itr or *itl != min_idx + i) {
                        empty_idx = min_idx + i;
                        break;
                    }
                    ++itl;
                }
            }

            int v2 = empty_idx * 2 + (u2 & 1);
            ans_u = u2;
            ans_v = v2;
            break;
        }
        for (int v2 : { v - d, v + d }) {
            int min_u = u - d, max_u = u + d;
            int min_idx = (min_u - (v2 & 1)) / 2;
            int max_idx = (max_u - (v2 & 1)) / 2;

            int empty_idx;
            if (v2 < 0 or v2 > 3 * B) {
                empty_idx = min_idx;
            } else {
                auto itl = lower_bound(all(mp_v[v2]), min_idx);
                auto itr = itl + min(int(mp_v[v2].end() - itl), d + 1);
                int c = itr - itl;
                if (c == d + 1 and *(itr - 1) == max_idx) continue;
                rep(i, d + 1) {
                    if (itl == itr or *itl != min_idx + i) {
                        empty_idx = min_idx + i;
                        break;
                    }
                    ++itl;
                }
            }

            int u2 = empty_idx * 2 + (v2 & 1);
            ans_v = v2;
            ans_u = u2;
            break;
        }
        print((ans_u + ans_v) / 2 - B, (ans_u - ans_v) / 2);
    }

    return 0;
}