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
#define input_vector(value_type, name, size) std::vector<value_type> name(size); read(name)

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
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) return in;
    return operator>><N + 1>(in >> std::get<N>(a), a);
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

#include <utility>
#include <vector>

// l <= x < r
template <typename T>
constexpr inline bool in_range(const T &x, const T &l, const T &r) {
    return l <= x and x < r;
}
// 0 <= x < r
template <typename T>
constexpr inline bool in_range(const T &x, const T &r) {
    return (std::make_unsigned_t<T>) x < (std::make_unsigned_t<T>) r;
}
// not (l <= x < r)
template <typename T>
constexpr inline bool out_range(const T &x, const T &l, const T &r) {
    return x < l or r <= x;
}
// not (0 <= x < r)
template <typename T>
constexpr inline bool out_range(const T &x, const T &r) {
    return (std::make_unsigned_t<T>) x >= (std::make_unsigned_t<T>) r;
}

constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};
constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr std::pair<int, int> dxy4[4] = {
    { dx4[0], dy4[0] }, { dx4[1], dy4[1] }, { dx4[2], dy4[2] }, { dx4[3], dy4[3] },
};
constexpr std::pair<int, int> dxy8[8] = {
    { dx8[0], dy8[0] }, { dx8[1], dy8[1] }, { dx8[2], dy8[2] }, { dx8[3], dy8[3] },
    { dx8[4], dy8[4] }, { dx8[5], dy8[5] }, { dx8[6], dy8[6] }, { dx8[7], dy8[7] },
};

template <int D, auto dx, auto dy>
struct AdjacentCells {
    struct Iterator {
        const int x, y;
        int d;
        bool operator!=(std::nullptr_t) { return d != D; }
        void operator++() { ++d; }
        std::pair<int, int> operator*() { return { x + dx[d], y + dy[d] }; }
    };
    const int x, y;
    AdjacentCells(int x, int y) : x(x), y(y) {}
    auto begin() { return Iterator { x, y, 0 }; }
    constexpr std::nullptr_t end() { return nullptr; }
    operator std::vector<std::pair<int, int>>() {
        std::vector<std::pair<int, int>> res;
        for (const auto &p : *this) res.push_back(p);
        return res;
    }
};

template <int D, auto dx, auto dy>
struct AdjacentCellsBounded {
    struct Iterator {
        const int x, y, xl, xr, yl, yr;
        int d;
        bool operator!=(std::nullptr_t) {
            for (; d != D; ++d) if (in_range(x + dx[d], xl, xr) and in_range(y + dy[d], yl, yr)) return true;
            return false;
        }
        void operator++() { ++d; }
        std::pair<int, int> operator*() { return { x + dx[d], y + dy[d] }; }
    };
    const int x, y, xl, xr, yl, yr;
    AdjacentCellsBounded(int x, int y, int xl, int xr, int yl, int yr) : x(x), y(y), xl(xl), xr(xr), yl(yl), yr(yr) {}
    AdjacentCellsBounded(int x, int y, int xr, int yr) : AdjacentCellsBounded(x, y, 0, xr, 0, yr) {}
    auto begin() { return Iterator { x, y, xl, xr, yl, yr, 0 }; }
    constexpr std::nullptr_t end() { return nullptr; }
    operator std::vector<std::pair<int, int>>() {
        std::vector<std::pair<int, int>> res;
        for (const auto &p : *this) res.push_back(p);
        return res;
    }
};

// [ {x+dx4[i], y+dy4[i]} for i in range(4) ]
using AdjacentFourCells = AdjacentCells<4, dx4, dy4>;
// [ {nx:=x+dx4[i], ny:=y+dy4[i]} for i in range(4) if xl<=nx<xr and yl<=ny<yr ]
using AdjacentFourCellsBounded = AdjacentCellsBounded<4, dx4, dy4>;

// [ {x+dx8[i], y+dy8[i]} for i in range(8) ]
using AdjacentEightCells = AdjacentCells<8, dx8, dy8>;
// [ {nx:=x+dx8[i], ny:=y+dy8[i]} for i in range(8) if xl<=nx<xr and yl<=ny<yr ]
using AdjacentEightCellsBounded = AdjacentCellsBounded<8, dx8, dy8>;

// [ {x+dx4[i], y+dy4[i]} for i in range(4) ]
auto adjacent_four_cells(int x, int y) { return AdjacentFourCells { x, y }; }
// [ {nx:=x+dx4[i], ny:=y+dy4[i]} for i in range(4) if xl<=nx<xr and yl<=ny<yr ]
auto adjacent_four_cells(int x, int y, int xl, int xr, int yl, int yr) { return AdjacentFourCellsBounded { x, y, xl, xr, yl, yr }; }
// [ {nx:=x+dx4[i], ny:=y+dy4[i]} for i in range(4) if 0 <=nx<xr and 0 <=ny<yr ]
auto adjacent_four_cells(int x, int y,         int xr,         int yr) { return AdjacentFourCellsBounded { x, y, 0 , xr, 0 , yr }; }

// [ {x+dx8[i], y+dy8[i]} for i in range(8) ]
auto adjacent_eight_cells(int x, int y) { return AdjacentEightCells { x, y }; }
// [ {nx:=x+dx8[i], ny:=y+dy8[i]} for i in range(8) if xl<=nx<xr and yl<=ny<yr ]
auto adjacent_eight_cells(int x, int y, int xl, int xr, int yl, int yr) { return AdjacentEightCellsBounded { x, y, xl, xr, yl, yr }; }
// [ {nx:=x+dx8[i], ny:=y+dy8[i]} for i in range(8) if 0 <=nx<xr and 0 <=ny<yr ]
auto adjacent_eight_cells(int x, int y,         int xr,         int yr) { return AdjacentEightCellsBounded { x, y, 0 , xr, 0 , yr }; }

int main() {
    input(int, t);
    loop(t) {
        input(int, n, m, k);
        vector<string> ans(n, string(m, '.'));
        if (n % 2 == 1) {
            rep(j, m / 2) {
                char c = 'a' + (j % 26);
                ans[n - 1][2 * j] = ans[n - 1][2 * j + 1] = c;
            }
            --n;
            k -= m / 2;
        } else if (m % 2 == 1) {
            rep(i, n / 2) {
                char c = 'a' + (i % 26);
                ans[2 * i][m - 1] = ans[2 * i + 1][m - 1] = c;
            }
            --m;
        }
        if (not (0 <= k and k <= n * m / 2 and k % 2 == 0)) {
            print("NO");
            continue;
        }
        auto put = [&](int i1, int j1, int i2, int j2) {
            vector<char> used(26, false);
            for (auto [ni, nj] : adjacent_four_cells(i1, j1, ans.size(), ans[0].size())) {
                if (ans[ni][nj] != '.') {
                    used[ans[ni][nj] - 'a'] = true;
                }
            }
            for (auto [ni, nj] : adjacent_four_cells(i2, j2, ans.size(), ans[0].size())) {
                if (ans[ni][nj] != '.') {
                    used[ans[ni][nj] - 'a'] = true;
                }
            }
            rep(i, 26) {
                if (not used[i]) {
                    ans[i1][j1] = ans[i2][j2] = char('a' + i);
                    return;
                }
            }
        };
        rep(i, n / 2) rep(j, m / 2) {
            if (k) {
                put(i * 2 + 0, j * 2 + 0, i * 2 + 0, j * 2 + 1);
                put(i * 2 + 1, j * 2 + 0, i * 2 + 1, j * 2 + 1);
                k -= 2;
            } else {
                put(i * 2 + 0, j * 2 + 0, i * 2 + 1, j * 2 + 0);
                put(i * 2 + 0, j * 2 + 1, i * 2 + 1, j * 2 + 1);
            }
        }
        print("YES");
        print_all(ans, "\n");
    }
    return 0;
}