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

int main() {
    input(int, n, q);
    input(string, s);
    vector<int> a(n);
    map<int, RangeSet<int>> sets;
    int ans = 0;

    auto erase = [&](int v, int i) {
        auto [l, r] = *sets[v].find_range(i);
        int l1 = i - l;
        int l2 = r - i;
        ans += l1 / 3;
        ans += l2 / 3;
        ans -= (r - l + 1) / 3;
        sets[v].erase(i);
    };

    auto insert = [&](int v, int i) {
        sets[v].insert(i);
        auto [l, r] = *sets[v].find_range(i);
        int l1 = i - l;
        int l2 = r - i;
        ans -= l1 / 3;
        ans -= l2 / 3;
        ans += (r - l + 1) / 3;
    };

    rep(i, n) {
        a[i] = (s[i] - 'a') - i;
        insert(a[i], i);
    }

    loop(q) {
        input(int, i);
        --i;
        input(char, c);
        int v = (c - 'a') - i;
        erase(a[i], i);
        a[i] = v;
        insert(a[i], i);
        print(ans);
    }
    return 0;
}