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
} io_setup_{};

// ! code from here

template< typename T, typename Compare = less< T >, typename RCompare = greater< T > >
struct PrioritySumStructure {
    size_t k;
    T sum;

    priority_queue< T, vector< T >, Compare > in;
    priority_queue< T, vector< T >, RCompare > out;

    PrioritySumStructure() : PrioritySumStructure(0) {}
    PrioritySumStructure(int k) : k(k), sum(0) {}

    void modify() {
        while (in.size() < k && !out.empty()) {
            auto p = out.top();
            out.pop();
            sum += p;
            in.emplace(p);
        }
        while (in.size() > k) {
            auto p = in.top();
            in.pop();
            sum -= p;
            out.emplace(p);
        }
    }

    T query() const {
        return sum;
    }

    void insert(T x) {
        in.emplace(x);
        sum += x;
        modify();
    }

    void set_k(size_t kk) {
        k = kk;
        modify();
    }

    size_t get_k() const {
        return k;
    }

    size_t size() const {
        return in.size() + out.size();
    }
};

template< typename T >
using MaximumSum = PrioritySumStructure< T, greater< T >, less< T > >;

template< typename T >
using MinimumSum = PrioritySumStructure< T, less< T >, greater< T > >;

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#include <numeric>

namespace suisen {
    struct Permutation : public std::vector<int> {
        using base_type = std::vector<int>;
        using base_type::base_type;

        Permutation() : Permutation(0) {}
        Permutation(std::size_t n) : Permutation(int(n)) {}
        Permutation(int n) : base_type(n) {
            std::iota(begin(), end(), 0);
        }
        Permutation(const std::vector<int>& a) : std::vector<int>(a) {}
        Permutation(std::vector<int>&& a) : std::vector<int>(std::move(a)) {}

        // returns b s.t. b[i] = a[p[i]]
        template <typename T>
        std::vector<T> permute(const std::vector<T>& a) const {
            const int n = a.size();
            std::vector<T> res(n);
            for (int i = 0; i < n; ++i) res[i] = a[(*this)[i]];
            return res;
        }
        // returns b s.t. b[p[i]] = a[i]
        template <typename T>
        std::vector<T> inv_permute(const std::vector<T>& a) const {
            const int n = a.size();
            std::vector<T> res(n);
            for (int i = 0; i < n; ++i) res[(*this)[i]] = a[i];
            return res;
        }

        // returns p * q s.t. (p * q)[i] = p[q[i]]
        friend Permutation operator*(const Permutation& p, const Permutation& q) {
            return q.permute(p);
        }
        Permutation& operator*=(const Permutation& q) {
            return *this = *this * q;
        }
        Permutation inv() const {
            const int n = size();
            Permutation res(n);
            for (int i = 0; i < n; ++i) res[(*this)[i]] = i;
            return res;
        }
        Permutation pow(long long k) const {
            const int n = size();
            Permutation res(n), p = *this;
            for (; k; k >>= 1) {
                if (k & 1) res *= p;
                p *= p;
            }
            return res;
        }

        template <typename T, typename Comp = std::less<T>>
        static Permutation index_sort(const std::vector<T>& a, Comp comp = Comp{}) {
            Permutation p(a.size());
            std::sort(p.begin(), p.end(), [&](int i, int j) { return comp(a[i], a[j]); });
            return p;
        }
    };

    template <typename hash_t>
    struct PermutationHash {
        hash_t operator()(const Permutation &p) const {
            return hash(p);
        }
        /**
         * minimal perfect hash function for permutations.
         * complexity: O(n) time, O(n) extra space
         * reference: https://twitter.com/noshi91/status/1452081886025555972?s=20
         */
        static hash_t hash(const Permutation &per) {
            hash_t h = 0;
            const int n = per.size();
            Permutation p = per;
            Permutation q = per.inv();
            for (int i = n - 1; i >= 0; --i) {
                h = h * (i + 1) + p[i];
                p[q[i]] = p[i];
                q[p[i]] = q[i];
            }
            return h;
        }
        static Permutation unhash(int n, hash_t h) {
            Permutation p = Permutation(n), q = p;
            for (int i = 0; i < n; ++i) {
                p[i] = h % (i + 1), q[i] = q[p[i]];
                q[p[i]] = p[q[i]] = i;
                h /= i + 1;
            }
            return p;
        }
    };
} // namespace suisen

int main() {
    input(int, n, m, q);
    vector<int> a(n), b(m);
    read(a, b);

    vector<pair<int, int>> c;
    rep(i, n) c.emplace_back(a[i], i);
    rep(i, m) c.emplace_back(b[i], n + i);
    sort(all(c));

    const int l = n + m;

    atcoder::dsu uf(l);
    vector<pair<int, int>> ds(l - 1);
    rep(i, l - 1) {
        ds[i] = { c[i + 1].first - c[i].first, i };
    }
    sort(all(ds));

    long long cur_ans = 0;

    vector<MaximumSum<long long>> sums(l);
    rep(i, l) {
        sums[i].insert(c[i].first);
        if (c[i].second < n) {
            sums[i].set_k(1);
            cur_ans += sums[i].query();
        }
    }

    auto merge = [&](int i, int j) {
        i = uf.leader(i);
        j = uf.leader(j);
        long long old_sum = sums[i].query() + sums[j].query();
        if (sums[i].size() < sums[j].size()) swap(i, j);
        while (sums[j].in.size()) {
            int t = sums[j].in.top();
            sums[j].in.pop();
            sums[i].insert(t);
        }
        while (sums[j].out.size()) {
            int t = sums[j].out.top();
            sums[j].out.pop();
            sums[i].insert(t);
        }
        sums[i].set_k(sums[i].get_k() + sums[j].get_k());
        long long new_sum = sums[i].query();
        int r = uf.merge(i, j);
        if (r == j) sums[r] = move(sums[i]);
        return new_sum - old_sum;
    };

    vector<int> qs(q);
    read(qs);
    auto p = Permutation::index_sort(qs);
    vector<long long> ans(q);

    int idx = 0;
    for (int qi : p) {
        int k = qs[qi];
        while (idx < l - 1 and ds[idx].first <= k) {
            int i = ds[idx++].second;
            long long d = merge(i, i + 1);
            cur_ans += d;
        }
        ans[qi] = cur_ans;
    }
    print_all(ans, "\n");
    return 0;
}