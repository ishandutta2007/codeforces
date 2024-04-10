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

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
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
void sort_unique_erase(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
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
#include <numeric>
#include <string>
#include <vector>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

}  // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}

// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

}  // namespace atcoder

#include <iostream>

namespace suisen {
    struct BigInt {
        BigInt() : BigInt(0) {}
        template <typename T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
        BigInt(T v) {
            for (; v; v /= 10) d.push_back(v % 10);
            ensure_size(1);
        }
        BigInt(const std::string &s) {
            for (auto it = s.rbegin(); it != s.rend(); ++it) {
                int v = *it - '0';
                assert(0 <= v and v <= 9);
                d.push_back(v);
            }
            ensure_size(1);
        }

        friend int compare(const BigInt &lhs, const BigInt &rhs) {
            if (lhs.d.size() != rhs.d.size()) return lhs.d.size() < rhs.d.size() ? -1 : +1;
            for (size_t i = lhs.d.size(); i --> 0;) {
                if (lhs.d[i] != rhs.d[i]) return lhs.d[i] < rhs.d[i] ? -1 : +1;
            }
            return 0;
        }
        friend bool operator< (const BigInt &lhs, const BigInt &rhs) { return compare(lhs, rhs) <  0; }
        friend bool operator<=(const BigInt &lhs, const BigInt &rhs) { return compare(lhs, rhs) <= 0; }
        friend bool operator> (const BigInt &lhs, const BigInt &rhs) { return compare(lhs, rhs) >  0; }
        friend bool operator>=(const BigInt &lhs, const BigInt &rhs) { return compare(lhs, rhs) >= 0; }
        friend bool operator==(const BigInt &lhs, const BigInt &rhs) { return compare(lhs, rhs) == 0; }
        friend bool operator!=(const BigInt &lhs, const BigInt &rhs) { return compare(lhs, rhs) != 0; }

        BigInt& operator+=(const BigInt &rhs) {
            ensure_size(rhs.d.size());
            for (size_t i = 0; i < rhs.d.size(); ++i) d[i] += rhs.d[i];
            fix();
            return *this;
        }
        BigInt& operator-=(const BigInt &rhs) {
            ensure_size(rhs.d.size());
            for (size_t i = 0; i < rhs.d.size(); ++i) d[i] -= rhs.d[i];
            fix();
            return *this;
        }
        BigInt& operator*=(const BigInt &rhs) {
            size_t n = d.size(), m = rhs.d.size();
            ensure_size(d.size() + rhs.d.size());
            for (size_t i = n; i --> 0;) {
                int32_t v = std::exchange(d[i], 0);
                for (size_t j = m; j --> 0;) d[i + j] += v * rhs.d[j];
            }
            fix();
            return *this;
        }

        friend BigInt operator+(const BigInt &lhs, const BigInt &rhs) { return BigInt(lhs) += rhs; }
        friend BigInt operator-(const BigInt &lhs, const BigInt &rhs) { return BigInt(lhs) -= rhs; }
        friend BigInt operator*(const BigInt &lhs, const BigInt &rhs) { return BigInt(lhs) *= rhs; }

        BigInt& operator++() { return *this += BigInt(1); }
        BigInt& operator--() { return *this -= BigInt(1); }
        BigInt operator++(int) { return std::exchange(*this, *this + 1); }
        BigInt operator--(int) { return std::exchange(*this, *this - 1); }

    private:
        std::vector<int32_t> d;

        void ensure_size(size_t n) {
            if (d.size() < n) d.resize(n, 0);
        }

        void fix() {
            int32_t carry = 0;
            for (size_t i = 0; i < d.size(); ++i) {
                d[i] += carry;
                int32_t q = d[i] / 10, r = d[i] % 10;
                if (r < 0) --q, r += 10;
                carry = q, d[i] = r;
            }
            for (; carry; carry /= 10) d.push_back(carry % 10);
            while (d.size() > 1 and d.back() == 0) d.pop_back();
        }
    };
} // namespace suisen

#include <array>
#include <cstdint>
#include <random>

namespace suisen {
    template <int base_as_int, typename mint>
    struct static_pow_mods {
        static_pow_mods() {}
        static_pow_mods(int n) { ensure(n); }
        const mint& operator[](int i) const {
            ensure(i);
            return pows[i];
        }
        static void ensure(int n) {
            int sz = pows.size();
            if (sz > n) return;
            pows.resize(n + 1);
            for (int i = sz; i <= n; ++i) pows[i] = base * pows[i - 1];
        }
    private:
        static inline std::vector<mint> pows { 1 };
        static inline mint base = base_as_int;
        static constexpr int mod = mint::mod();
    };

    template <typename mint>
    struct pow_mods {
        pow_mods() {}
        pow_mods(mint base, int n) : base(base) { ensure(n); }
        const mint& operator[](int i) const {
            ensure(i);
            return pows[i];
        }
        void ensure(int n) const {
            int sz = pows.size();
            if (sz > n) return;
            pows.resize(n + 1);
            for (int i = sz; i <= n; ++i) pows[i] = base * pows[i - 1];
        }
    private:
        mutable std::vector<mint> pows { 1 };
        mint base;
        static constexpr int mod = mint::mod();
    };
}

namespace suisen {
    namespace internal::rolling_hash {
        // reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
        struct Modint2305843009213693951 {
            using self = Modint2305843009213693951;

            Modint2305843009213693951() {}
            Modint2305843009213693951(uint64_t v) : v(fast_mod(v)) {}

            static constexpr uint64_t mod() {
                return _mod;
            }

            static constexpr uint64_t fast_mod(uint64_t v) {
                constexpr uint32_t mid = 61;
                constexpr uint64_t mask = (uint64_t(1) << mid) - 1;
                uint64_t u = v >> mid;
                uint64_t d = v & mask;
                uint64_t res = u + d;
                if (res >= _mod) res -= _mod;
                return res;
            }

            uint64_t val() const {
                return v;
            }

            self& operator+=(const self &rhs) {
                v += rhs.v;
                if (v >= _mod) v -= _mod;
                return *this;
            }
            self& operator-=(const self &rhs) {
                if (v < rhs.v) v += _mod;
                v -= rhs.v;
                return *this;
            }
            self& operator*=(const self &rhs) {
                static constexpr uint32_t mid31 = 31;
                static constexpr uint64_t mask31 = (uint64_t(1) << mid31) - 1;

                uint64_t au = v >> mid31;     // < 2^30
                uint64_t ad = v & mask31;     // < 2^31
                uint64_t bu = rhs.v >> mid31; // < 2^30
                uint64_t bd = rhs.v & mask31; // < 2^31
                
                //   a * b
                // = (au * 2^31 + ad) * (bu * 2^31 + bd)
                // = au * bu * 2^62             # au * bu * 2^62  au * bu * 2 < 2^61
                // + (au * bd + ad * bu) * 2^31 # m := au * bd + ad * bu
                //                              # m <= 2 * (2^31 - 1) * (2^30 - 1) = 2^62 - 6 * 2^30 + 2
                //                              # m = mu * 2^30 + md (0 <= mu < 2^32, 0 <= md < 2^30)
                //                              # m * 2^31  mu + md * 2^31 < 2^61 + 2^31
                // + ad * bd                    # ad * bd <= (2^31 - 1) ** 2 = 2^62 - 2^32 + 1 < 2^62 - 2^31
                //  au * bu * 2 + mu + md * 2^31 + ad * bd < 2^63

                static constexpr uint32_t mid30 = 30;
                static constexpr uint64_t mask30 = (uint64_t(1) << mid30) - 1;

                uint64_t m = au * bd + ad * bu;
                uint64_t mu = m >> mid30;
                uint64_t md = m & mask30;

                v = fast_mod((au * bu << 1) + mu + (md << 31) + ad * bd);
                return *this;
            }

            friend self operator+(const self &l, const self &r) { return self(l) += r; }
            friend self operator-(const self &l, const self &r) { return self(l) -= r; }
            friend self operator*(const self &l, const self &r) { return self(l) *= r; }
            friend bool operator==(const self &l, const self &r) { return l.v == r.v; }
        private:
            static constexpr uint64_t _mod = (uint64_t(1) << 61) - 1; // 2305843009213693951UL : prime
            uint64_t v;
        };

        template <int base_num, typename mint>
        std::array<mint, base_num> gen_bases() {
            static std::mt19937_64 rng(std::random_device{}());
            std::array<mint, base_num> res;
            for (int i = 0; i < base_num; ++i) {
                res[i] = rng();
                while (res[i].val() < 128) res[i] = rng();
            }
            return res;
        }
        template <int base_num, typename mint>
        std::array<pow_mods<mint>, base_num> init_pows(const std::array<mint, base_num>& bases) {
            std::array<pow_mods<mint>, base_num> res;
            for (int i = 0; i < base_num; ++i) {
                res[i] = pow_mods<mint>(bases[i], 0);
            }
            return res;
        }
    }

    template <int base_num = 1, typename mint = internal::rolling_hash::Modint2305843009213693951>
    struct RollingHash {
    private:
        using default_mint = internal::rolling_hash::Modint2305843009213693951;
    public:
        using modint_type = mint;
        using hash_type = decltype(mint::mod());

        RollingHash() {}
        RollingHash(const std::vector<int> &a) : n(a.size()) {
            for (int base_id = 0; base_id < base_num; ++base_id) {
                hash[base_id].resize(n + 1);
                hash[base_id][0] = 0;
                for (int i = 0; i < n; ++i) hash[base_id][i + 1] = hash[base_id][i] * bases[base_id] + a[i];
            }
        }

        auto operator()(int l, int r) {
            std::array<mint, base_num> res;
            for (int base_id = 0; base_id < base_num; ++base_id) res[base_id] = hash[base_id][r] - hash[base_id][l] * pows[base_id][r - l];
            return res;
        }

        static auto mod() {
            return mint::mod();
        }

        static void set_bases(const std::array<mint, base_num> &new_bases) {
            bases = new_bases;
            pows = internal::rolling_hash::init_pows<base_num, mint>(bases);
        }

        template <typename Iterable, typename ToIntFunction>
        static RollingHash from(const Iterable &s, ToIntFunction f) {
            std::vector<int> a;
            for (auto &&e : s) a.push_back(f(e));
            return RollingHash(a);
        }
        static RollingHash from_lowercase_alphabet(const std::string &s) {
            return from(s, [](const auto &e) { return e - 'a' + 1; });
        }
        static RollingHash from_uppercase_alphabet(const std::string &s) {
            return from(s, [](const auto &e) { return e - 'A' + 1; });
        }
        static RollingHash from_alphabet(const std::string &s) {
            return from(s, [](const auto &e) { return std::islower(e) ? e - 'a' + 27 : e - 'A' + 1; });
        }
        static RollingHash from_digit(const std::string &s) {
            return from(s, [](const auto &e) { return e - '0' + 1; });
        }

    private:
        static inline std::array<mint, base_num> bases = internal::rolling_hash::gen_bases<base_num, mint>();
        static inline std::array<pow_mods<mint>, base_num> pows = internal::rolling_hash::init_pows<base_num, mint>(bases);

        int n;
        std::array<std::vector<mint>, base_num> hash;
    };
} // namespace suisen

int main() {
    input(string, s);
    input(string, x);
    const int n = s.size(), m = x.size();

    RollingHash<1>::set_bases({ 10 });

    auto hash_s = RollingHash<1>::from(s, [&](char c) { return c - '0'; });
    auto hash_x = RollingHash<1>::from(x, [&](char c) { return c - '0'; });

    auto hx = hash_x(0, m);

    auto check = [&](int l, int m, int r) -> bool {
        return BigInt(s.substr(l, m - l)) + BigInt(s.substr(m, r - m)) == BigInt(x);
    };
    
    auto z = atcoder::z_algorithm(x + s);
    z.erase(z.begin(), z.begin() + m);
    rep(i, n) {
        int l = z[i];
        int w = m - l;

        // [i - m + 1, i) + [i, i + m - 1)
        // [i - w + 1, i) + [i, i + m)
        // [i - w,     i) + [i, i + m)
        //                  [i, i + m) + [i + m, i + m + w - 1)
        //                  [i, i + m) + [i + m, i + m + w)

        vector<tuple<int, int, int>> candidates {
            { i - m + 1, i, i + m - 1                },
            { i - w + 1, i, i + m                    },
            { i - w    , i, i + m                    },
            {            i, i + m    , i + m + w - 1 },
            {            i, i + m    , i + m + w     }
        };

        for (auto [l, m, r] : candidates) {
            if (l < 0 or r > n or l >= m or m >= r) continue;
            auto lm = hash_s(l, m);
            auto mr = hash_s(m, r);

            rep(i, lm.size()) {
                lm[i] += mr[i];
            }
            if (lm == hx and check(l, m, r)) {
                print(l + 1, m);
                print(m + 1, r);
                return 0;
            }
        }
    }
    return 0;
}