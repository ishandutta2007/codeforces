#include <bits/stdc++.h>

#ifdef _MSC_VER
#  include <intrin.h>
#else
#  include <x86intrin.h>
#endif

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
struct safely_multipliable<unsigned long int> { using type = __uint128_t; };
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

template <typename T, typename = void>
struct rec_value_type {
    using type = T;
};
template <typename T>
struct rec_value_type<T, std::void_t<typename T::value_type>> {
    using type = typename rec_value_type<typename T::value_type>::type;
};
template <typename T>
using rec_value_type_t = typename rec_value_type<T>::type;

} // namespace suisen

// ! type aliases
using i128 = __int128_t;
using u128 = __uint128_t;

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

#define all(iterable) std::begin(iterable), std::end(iterable)
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

#ifdef LOCAL
#  define debug(...) debug_internal(#__VA_ARGS__, __VA_ARGS__)

template <class T, class... Args>
void debug_internal(const char* s, T&& first, Args&&... args) {
    constexpr const char* prefix = "[\033[32mDEBUG\033[m] ";
    constexpr const char* open_brakets = sizeof...(args) == 0 ? "" : "(";
    constexpr const char* close_brakets = sizeof...(args) == 0 ? "" : ")";
    std::cerr << prefix << open_brakets << s << close_brakets << ": " << open_brakets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brakets << "\n";
}

#else
#  define debug(...) void(0)
#endif

// ! I/O utilities

// __int128_t
std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
// __uint128_t
std::ostream& operator<<(std::ostream& dest, __uint128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[value % 10];
            value /= 10;
        } while (value != 0);
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

// pair
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& a) {
    return out << a.first << ' ' << a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& a) {
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
std::ostream& operator<<(std::ostream& out, const std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
// array
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail &...tails) {
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

__int128_t parse_i128(std::string& s) {
    __int128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    if (s[0] == '-') ret = -ret;
    return ret;
}
__uint128_t parse_u128(std::string& s) {
    __uint128_t ret = 0;
    for (int i = 0; i < int(s.size()); i++) if ('0' <= s[i] and s[i] <= '9') ret = 10 * ret + s[i] - '0';
    return ret;
}
// __int128_t
std::istream& operator>>(std::istream& in, __int128_t& v) {
    std::string s;
    in >> s;
    v = parse_i128(s);
    return in;
}
// __uint128_t
std::istream& operator>>(std::istream& in, __uint128_t& v) {
    std::string s;
    in >> s;
    v = parse_u128(s);
    return in;
}
// pair
template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& a) {
    return in >> a.first >> a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...>& a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}
// vector
template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
// array
template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    (std::cin >> ... >> args);
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
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u32(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
__attribute__((target("popcnt"))) constexpr inline int popcount(const T x) { return _mm_popcnt_u64(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int floor_log2(const T x) { return suisen::bit_num<T> -1 - count_lz(x); }
template <typename T>
constexpr inline int ceil_log2(const T x) { return floor_log2(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int kth_bit(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

// ! container

template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto priqueue_comp(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable& iterable) -> decltype(int(iterable.size())) {
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
void sort_unique_erase(std::vector<T>& a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto foreach_adjacent_values(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto foreach_adjacent_values(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()) {
    foreach_adjacent_values(c.begin(), c.end(), f);
}

// ! other utilities

// x <- min(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmin(T& x, const T& y) {
    if (y >= x) return false;
    x = y;
    return true;
}
// x <- max(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmax(T& x, const T& y) {
    if (y <= x) return false;
    x = y;
    return true;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::string bin(T val, int bit_num = -1) {
    std::string res;
    if (bit_num >= 0) {
        for (int bit = bit_num; bit-- > 0;) res += '0' + ((val >> bit) & 1);
    } else {
        for (; val; val >>= 1) res += '0' + (val & 1);
        std::reverse(res.begin(), res.end());
    }
    return res;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> digits_low_to_high(T val, T base = 10) {
    std::vector<T> res;
    for (; val; val /= base) res.push_back(val % base);
    if (res.empty()) res.push_back(T{ 0 });
    return res;
}
template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::vector<T> digits_high_to_low(T val, T base = 10) {
    auto res = digits_low_to_high(val, base);
    std::reverse(res.begin(), res.end());
    return res;
}

template <typename T>
std::string join(const std::vector<T>& v, const std::string& sep, const std::string& end) {
    std::ostringstream ss;
    for (auto it = v.begin(); it != v.end();) {
        ss << *it;
        if (++it != v.end()) ss << sep;
    }
    ss << end;
    return ss.str();
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
#include <array>
#include <cassert>
#include <cmath>
#include <optional>
#include <tuple>
#include <vector>

namespace suisen {

    // // Returns pow(-1, n)
    // template <typename T>
    // constexpr inline int pow_m1(T n) {
    //     return -(n & 1) | 1;
    // }
    // // Returns pow(-1, n)
    // template <>
    // constexpr inline int pow_m1<bool>(bool n) {
    //     return -int(n) | 1;
    // }

    // // Returns floor(x / y)
    // template <typename T>
    // constexpr inline T fld(const T x, const T y) {
    //     return (x ^ y) >= 0 ? x / y : (x - (y + pow_m1(y >= 0))) / y;
    // }
    // // Returns ceil(x / y)
    // template <typename T>
    // constexpr inline T cld(const T x, const T y) {
    //     return (x ^ y) <= 0 ? x / y : (x + (y + pow_m1(y >= 0))) / y;
    // }

    /**
     * O(sqrt(n))
     * Returns a vector of { prime, index }.
     * It is guaranteed that `prime` is ascending.
     */
    template <typename T>
    std::vector<std::pair<T, int>> factorize(T n) {
        static constexpr std::array primes{ 2, 3, 5, 7, 11, 13 };
        static constexpr int next_prime = 17;
        static constexpr int siz = std::array{ 1, 2, 8, 48, 480, 5760, 92160 } [primes.size() - 1] ;
        static constexpr int period = [] {
            int res = 1;
            for (auto e : primes) res *= e;
            return res;
        }();
        static constexpr struct S : public std::array<int, siz> {
            constexpr S() {
                for (int i = next_prime, j = 0; i < period + next_prime; i += 2) {
                    bool ok = true;
                    for (int p : primes) ok &= i % p > 0;
                    if (ok) (*this)[j++] = i - next_prime;
                }
            }
        } s{};

        assert(n > 0);
        std::vector<std::pair<T, int>> res;
        auto f = [&res, &n](int p) {
            if (n % p) return;
            int cnt = 0;
            do n /= p, ++cnt; while (n % p == 0);
            res.emplace_back(p, cnt);
        };
        for (int p : primes) f(p);
        for (T b = next_prime; b * b <= n; b += period) {
            for (int offset : s) f(b + offset);
        }
        if (n != 1) res.emplace_back(n, 1);
        return res;
    }

    /**
     * O(sigma(n))
     * Returns a vector that contains all divisors of `n`.
     * It is NOT guaranteed that the vector is sorted.
     */
    template <typename T>
    std::vector<T> divisors(const std::vector<std::pair<T, int>>& factorized) {
        std::vector<T> res{ 1 };
        for (auto [p, c] : factorized) {
            for (int i = 0, sz = res.size(); i < sz; ++i) {
                T d = res[i];
                for (int j = 0; j < c; ++j) res.push_back(d *= p);
            }
        }
        return res;
    }

    /**
     * O(sqrt(n))
     * Returns a vector that contains all divisors of `n`.
     * It is NOT guaranteed that the vector is sorted.
     */
    template <typename T, constraints_t<std::is_integral<T>> = nullptr>
    std::vector<T> divisors(T n) {
        return divisors(factorize(n));
    }

    template <typename T>
    T totient(T n) {
        for (const auto& [p, _] : factorize(n)) n /= p, n *= p - 1;
        return n;
    }
    std::vector<int> totient_table(int n) {
        std::vector<int> res(n + 1);
        for (int i = 0; i <= n; ++i) res[i] = (i & 1) == 0 ? i >> 1 : i;
        for (int p = 3; p * p <= n; p += 2) {
            if (res[p] != p) continue;
            for (int q = p; q <= n; q += p) res[q] /= p, res[q] *= p - 1;
        }
        return res;
    }

    // Returns { l, r } := min_max { x>0 | fld(n,x)=q }.
    template <typename T, constraints_t<std::is_integral<T>> = nullptr>
    std::optional<std::pair<T, T>> same_fld_denominators_positive(T n, T q, T max_val = std::numeric_limits<T>::max()) {
        T l, r;
        if (q >= 0) {
            if (n < 0) return std::nullopt;
            // cld(n + 1, q + 1) <= x <= fld(n, q)
            l = (n + 1 + q) / (q + 1), r = q == 0 ? max_val : std::min(max_val, n / q);
        } else {
            if (n >= 0) return std::nullopt;
            // cld(n, q) <= x <= fld(n + 1, q + 1)
            l = (n + q + 1) / q, r = q == -1 ? max_val : std::min(max_val, (n + 1) / (q + 1));
        }
        if (l <= r) return std::make_pair(l, r);
        else        return std::nullopt;
    }
    // Returns { l, r } := min_max { x<0 | fld(n,x)=q }.
    template <typename T, constraints_t<std::is_integral<T>> = nullptr>
    std::optional<std::pair<T, T>> same_fld_denominators_negative(T n, T q, T min_val = std::numeric_limits<T>::min()) {
        T l, r;
        if (q >= 0) {
            if (n > 0) return std::nullopt;
            // cld(n, q) <= x <= fld(n - 1, q + 1)
            l = q == 0 ? min_val : std::max(min_val, n / q), r = (n - 1 - q) / (q + 1);
        } else {
            if (n <= 0) return std::nullopt;
            // cld(n - 1, q + 1) <= x <= fld(n, q)
            l = q == -1 ? min_val : std::max(min_val, (n - 1) / (q + 1)), r = (n - q - 1) / q;
        }
        if (l <= r) return std::make_pair(l, r);
        else        return std::nullopt;
    }
    // Returns { l, r } := min_max { x>0 | cld(n,x)=q }.
    template <typename T, constraints_t<std::is_integral<T>> = nullptr>
    std::optional<std::pair<T, T>> same_cld_denominators_positive(T n, T q, T max_val = std::numeric_limits<T>::max()) {
        T l, r;
        if (q > 0) {
            if (n <= 0) return std::nullopt;
            l = (n + q - 1) / q, r = q == 1 ? max_val : std::min(max_val, (n - 1) / (q - 1));
        } else {
            if (n > 0) return std::nullopt;
            l = (n - 1 + q) / (q - 1), r = q == 0 ? max_val : std::min(max_val, n / q);
        }
        if (l <= r) return std::make_pair(l, r);
        else        return std::nullopt;
    }
    // Returns { l, r } := min_max { x<0 | cld(n,x)=q }.
    template <typename T, constraints_t<std::is_integral<T>> = nullptr>
    std::optional<std::pair<T, T>> same_cld_denominators_negative(T n, T q, T min_val = std::numeric_limits<T>::min()) {
        T l, r;
        if (q > 0) {
            if (n >= 0) return std::nullopt;
            l = q == 1 ? min_val : std::max(min_val, (n + 1) / (q - 1)), r = (n - q + 1) / q;
        } else {
            if (n < 0) return std::nullopt;
            l = q == 0 ? min_val : std::max(min_val, n / q), r = (n + 1 - q) / (q - 1);
        }
        if (l <= r) return std::make_pair(l, r);
        else        return std::nullopt;
    }

    /**
     * O(sqrt(n)).
     * Returns vector of { l : T, r : T, q : T } s.t. let S be { d | n / d = q }, l = min S and r = max S.
     * It is guaranteed that `l`, `r` is ascending (i.e. `q` is descending).
     */
    template <typename T, constraints_t<std::is_integral<T>> = nullptr>
    auto enumerate_quotients(T n) {
        assert(0 <= n);
        std::vector<std::tuple<T, T, T>> res;
        for (T l = 1, r = 1; l <= n; l = r + 1) {
            T q = n / l;
            res.emplace_back(l, r = n / q, q);
        }
        return res;
    }

    /**
     * Template Parameter:
     *  - vector<T> or array<T, N>
     *
     * Time Complexity: O(|vs| * Sum_{v in vs} sqrt(v))
     *
     * Returns vector of { l : T, r : T, qs : Container } s.t. let S be { d | vs[i] / d = qs[i] (for all i) }, l = min S and r = max S
     * It is guaranteed that `l`, `r` is ascending (i.e. for all `i`, `q[i]` is descending).
     */
    template <typename Container>
    std::vector<std::tuple<typename Container::value_type, typename Container::value_type, Container>>
        enumerate_multiple_quotients(const Container& vs) {
        using T = typename Container::value_type;
        static_assert(std::is_integral_v<T>);
        int n = vs.size();
        T max_val = *std::max_element(vs.begin(), vs.end());
        assert(*std::min_element(vs.begin(), vs.end()) >= 0);
        std::vector<std::tuple<T, T, Container>> res;
        for (T l = 1, r = 1; l <= max_val; l = r + 1) {
            Container qs{};
            if constexpr (std::is_same_v<Container, std::vector<T>>) qs.resize(n);
            r = std::numeric_limits<T>::max();
            for (int i = 0; i < n; ++i) {
                qs[i] = vs[i] / l;
                r = std::min(r, qs[i] == 0 ? std::numeric_limits<T>::max() : vs[i] / qs[i]);
            }
            res.emplace_back(l, r, std::move(qs));
        }
        return res;
    }

    template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
    T floor_kth_root(T x, int k) {
        if (k == 1 or x == 0 or x == 1) return x;
        if (k >= 64) return 1;
        if (k == 2) return sqrtl(x);
        // if (k == 3) return cbrtl(x);
        T res = powl(x, nextafterl(1 / (long double) k, 0));
        while (powl(res + 1, k) <= x) ++res;
        return res;
    }
} // namespace suisen

#include <utility>

namespace suisen {
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    return x < 0 ? x + m : x;
}

// returns {x,y,g} s.t. ax+by=g=gcd(a,b)>=0. 
std::tuple<long long, long long, long long> ext_gcd(long long a, long long b) {
    long long x = 1, y = 0;
    long long z = 0, w = 1;
    long long tmp;
    while (b) {
        long long p = a / b, q = a % b;
        tmp = x - y * p; x = y; y = tmp;
        tmp = z - w * p; z = w; w = tmp;
        a = b; b = q;
    }
    if (a >= 0) return {x, z, a};
    else return {-x, -z, -a};
}

// returns {x,g} s.t. a*x=g (mod m)
std::pair<long long, long long> gcd_inv(long long a, long long m) {
    auto [x, y, g] = ext_gcd(a, m);
    return {safe_mod(x, m), g};
}

// returns x s.t. a*x=1 (mod m) if exists, otherwise throws runtime error.
long long inv_mod(long long a, long long mod) {
    auto [inv, y, g] = ext_gcd(a, mod);
    assert(g == 1);
    return safe_mod(inv, mod);
}
} // namespace suisen

vector<pair<int, int>> solve(long long p, long long q, int n) {
    vector<pair<int, int>> ans;

    auto [a0, b0, _] = ext_gcd(p, q);
    a0 *= n - 1;
    b0 *= n - 1;

    long long kmin = cld(-a0, q);
    long long kmax = fld(b0, p);
    assert(kmin <= kmax);
    long long k = kmin;

    long long a = a0 + k * q;
    long long b = b0 - k * p;
    assert(a >= 0 and b >= 0);

    assert(a * p + b * q == n - 1);
    ans.emplace_back(p, a);
    ans.emplace_back(q, b);
    return ans;
}

int main() {
    input(int, n);

    auto fac = factorize(n);

    if (fac.size() == 1) {
        print("NO");
        return 0;
    }

    vector<pair<int, int>> ans;
    for (auto [v, c] : solve(fac[0].first, fac[1].first, n)) {
        ans.emplace_back(c, n / v);
    }
    print("YES");
    print(ans.size());
    print_all(ans, "\n");

    return 0;
}