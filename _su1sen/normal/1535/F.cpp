#include <array>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#include <algorithm>
#include <cassert>
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

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#include <array>
#include <type_traits>
#include <limits>

#include <cstdint>

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

using suisen::WaveletMatrix;

int op(int x, int y) {
    return std::min(x, y);
}
int e() {
    return std::numeric_limits<int>::max();
}

long long solve(std::vector<std::string> s) {
    const int n = s.size();
    const int m = s[0].size();

    std::sort(s.begin(), s.end());

    std::vector<int> lcp(n - 1), scp(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int j = 0;
        while (s[i][j] == s[i + 1][j]) ++j;
        lcp[i] = j;
    }

    std::vector<int> p(n), q(n);
    std::iota(p.begin(), p.end(), 0);
    {
        std::vector<std::string> t;
        for (const auto& e : s) {
            auto ti = e;
            std::reverse(ti.begin(), ti.end());
            t.push_back(std::move(ti));
        }
        std::sort(p.begin(), p.end(), [&](int i, int j) { return t[i] < t[j]; });
        for (int i = 0; i < n - 1; ++i) {
            int j = m;
            while (s[p[i]][j - 1] == s[p[i + 1]][j - 1]) --j;
            scp[i] = m - j;
        }
    }
    for (int i = 0; i < n; ++i) {
        q[p[i]] = i;
    }

    atcoder::segtree<int, op, e> seg_lcp(lcp), seg_scp(scp);

    WaveletMatrix<int, 18> wm(q);

    auto get_index_range = [&](int i, int x) {
        int il = seg_lcp.min_left(i, [&](int l) { return l >= x; });
        int ir = seg_lcp.max_right(i, [&](int l) { return l >= x; }) + 1;
        return std::make_pair(il, ir);
    };

    auto get_value_range = [&](int i, int x) {
        int vl = seg_scp.min_left(q[i], [&](int l) { return l >= m - x; });
        int vr = seg_scp.max_right(q[i], [&](int l) { return l >= m - x; }) + 1;
        return std::make_pair(vl, vr);
    };

    auto count = [&](int i, int x, int y) -> int {
        auto [il, ir] = get_index_range(i, x);
        auto [vl, vr] = get_value_range(i, y);
        return wm.range_freq(il, ir, vl, vr);
    };

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int l = 0; l < m;) {
            int r = l + 1;
            while (r < m and s[i][r - 1] <= s[i][r]) ++r;

            int add = count(i, l, r);
            res += add - 1;
            l = r;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::string, std::vector<std::string>> mp;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        auto t = s;
        std::sort(t.begin(), t.end());
        mp[t].push_back(s);
    }

    long long ans = 0;
    long long sub = 0;
    for (const auto& [sorted, s] : mp) {
        long long m = s.size();
        ans += (n - m) * m * 1337;
        ans += 2 * m * (m - 1);
        sub += solve(s);
    }

    std::cout << ans / 2 - sub << std::endl;
    return 0;
}