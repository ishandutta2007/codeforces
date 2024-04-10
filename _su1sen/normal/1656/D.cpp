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
} io_setup_{};

// ! code from here

#include <cmath>
#include <iostream>
#include <random>
#include <numeric>

#include <cassert>
#include <cstdint>
#include <iterator>

namespace suisen::miller_rabin {
    namespace internal {
        constexpr uint32_t THRESHOLD_1 = 341531U;
        constexpr uint64_t BASE_1[] { 9345883071009581737ULL };

        constexpr uint32_t THRESHOLD_2 = 1050535501U;
        constexpr uint64_t BASE_2[] { 336781006125ULL, 9639812373923155ULL };

        constexpr uint64_t THRESHOLD_3 = 350269456337ULL;
        constexpr uint64_t BASE_3[] { 4230279247111683200ULL, 14694767155120705706ULL, 16641139526367750375ULL };

        constexpr uint64_t THRESHOLD_4 = 55245642489451ULL;
        constexpr uint64_t BASE_4[] { 2ULL, 141889084524735ULL, 1199124725622454117ULL, 11096072698276303650ULL };

        constexpr uint64_t THRESHOLD_5 = 7999252175582851ULL;
        constexpr uint64_t BASE_5[] { 2ULL, 4130806001517ULL, 149795463772692060ULL, 186635894390467037ULL, 3967304179347715805ULL };

        constexpr uint64_t THRESHOLD_6 = 585226005592931977ULL;
        constexpr uint64_t BASE_6[] { 2ULL, 123635709730000ULL, 9233062284813009ULL, 43835965440333360ULL, 761179012939631437ULL, 1263739024124850375ULL };

        constexpr uint32_t BASE_7[] { 2U, 325U, 9375U, 28178U, 450775U, 9780504U, 1795265022U };

        template <auto BASE, std::size_t SIZE, typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
        bool miller_rabin(T _n) {
            using U = std::make_unsigned_t<T>;
            using M = safely_multipliable_t<U>;

            U n = _n, d = (n - 1) >> __builtin_ctzll(n - 1);

            if (n == 2 or n == 3 or n == 5 or n == 7) return true;
            if (n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0) return false;

            for (std::size_t i = 0; i < SIZE; ++i) {
                M y = 1, p = BASE[i] % n;
                if (p == 0) continue;
                for (U d2 = d; d2; d2 >>= 1) {
                    if (d2 & 1) y = y * p % n;
                    p = p * p % n;
                }
                if (y == 1) continue;
                for (U t = d; y != n - 1; t <<= 1) {
                    y = y * y % n;
                    if (y == 1 or t == n - 1) return false;
                }
            }
            return true;
        }
    }

    template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
    bool is_prime(T n) {
        if (n <= 1) return false;
        using namespace internal;
        if (n < THRESHOLD_1) {
            return miller_rabin<BASE_1, 1>(n);
        } else if (n < THRESHOLD_2) {
            return miller_rabin<BASE_2, 2>(n);
        } else if (n < THRESHOLD_3) {
            return miller_rabin<BASE_3, 3>(n);
        } else if (n < THRESHOLD_4) {
            return miller_rabin<BASE_4, 4>(n);
        } else if (n < THRESHOLD_5) {
            return miller_rabin<BASE_5, 5>(n);
        } else if (n < THRESHOLD_6) {
            return miller_rabin<BASE_6, 6>(n);
        } else {
            return miller_rabin<BASE_7, 7>(n);
        }
    }
} // namespace suisen::miller_rabin

namespace suisen::fast_factorize {
    namespace internal {
        template <typename T>
        int floor_log2(T n) {
            int i = 0;
            while (n) n >>= 1, ++i;
            return i - 1;
        }
        template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
        T pollard_rho(T n) {
            using M = safely_multipliable_t<T>;
            const T m = T(1) << (floor_log2(n) / 5);

            static std::mt19937_64 rng{std::random_device{}()};
            std::uniform_int_distribution<T> dist(0, n - 1);

            while (true) {
                T c = dist(rng);
                auto f = [&](T x) -> T { return (M(x) * x + c) % n; };
                T x, y = 2, ys, q = 1, g = 1;
                for (T r = 1; g == 1; r <<= 1) {
                    x = y;
                    for (T i = 0; i < r; ++i) y = f(y);
                    for (T k = 0; k < r and g == 1; k += m) {
                        ys = y;
                        for (T i = 0; i < std::min(m, r - k); ++i) y = f(y), q = M(q) * (x > y ? x - y : y - x) % n;
                        g = std::gcd(q, n);
                    }
                }
                if (g == n) {
                    g = 1;
                    while (g == 1) ys = f(ys), g = std::gcd(x > ys ? x - ys : ys - x, n);
                }
                if (g < n) {
                    if (miller_rabin::is_prime(g)) return g;
                    if (T d = n / g; miller_rabin::is_prime(d)) return d;
                    return pollard_rho(g);
                }
            }
        }
    }

    template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
    std::vector<std::pair<T, int>> factorize(T n) {
        std::vector<std::pair<T, int>> res;
        if ((n & 1) == 0) {
            int q = 0;
            do ++q, n >>= 1; while ((n & 1) == 0);
            res.emplace_back(2, q);
        }
        for (T p = 3; p * p <= n; p += 2) {
            if (p >= 101 and n >= 1 << 20) {
                while (n > 1) {
                    if (miller_rabin::is_prime(n)) {
                        res.emplace_back(std::exchange(n, 1), 1);
                    } else {
                        p = internal::pollard_rho(n);
                        int q = 0;
                        do ++q, n /= p; while (n % p == 0);
                        res.emplace_back(p, q);
                    }
                }
                break;
            }
            if (n % p == 0) {
                int q = 0;
                do ++q, n /= p; while (n % p == 0);
                res.emplace_back(p, q);
            }
        }
        if (n > 1) res.emplace_back(n, 1);
        return res;
    }
} // namespace suisen::fast_factorize

#include <algorithm>
#include <array>
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
            Container qs;
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

} // namespace suisen

int main() {
    input(int, t);

    loop(t) {
        input(long long, n);

        if (n % 2 == 1) {
            print(2);
            continue;
        }

        if (n == (n & -n)) {
            print(-1);
            continue;
        }

        const long long m = n / (n & -n);

        long long ans = -1;
        for (long long k : { m, 2 * n / m }) {
            if (k + 1 <= 2 * n / k) {
                ans = k;
                break;
            }
        }
        print(ans);
    }
    return 0;
}