#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <tuple>
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

constexpr long long inf = std::numeric_limits<long long>::max() / 2;

long long op(long long x, long long y) {
    return std::max(x, y);
}
long long e() {
    return -inf;
}

struct Data {
    long long a, c, v;
};

Data op2(Data x, Data y) {
    return Data { std::max(x.a, y.a), std::max(x.c, y.c), std::max(std::max(x.v, y.v), x.a + y.c) };
}
Data e2() {
    return Data { -inf, -inf, -inf };
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<long long> a(n), b(n), c(n);
    for (auto &e : a) std::cin >> e;
    for (auto &e : b) std::cin >> e;
    for (auto &e : c) std::cin >> e;

    for (int i = 0; i < n - 1; ++i) a[i + 1] += a[i] - b[i];
    for (int i = n - 1; i > 0; --i) c[i - 1] += c[i] - b[i];

    std::vector<std::vector<std::pair<int, long long>>> bucket(n);
    for (int i = 0; i < q; ++i) {
        int l, r, w;
        std::cin >> l >> r >> w;
        --l, --r;
        bucket[r].emplace_back(l, w);
    }

    atcoder::segtree<long long, op, e> dp(n), seg_a(a);
    for (int r = 0; r < n; ++r) for (const auto &[l, w] : bucket[r]) {
        dp.set(r, std::max(dp.get(r), std::max(seg_a.prod(l, r + 1), dp.prod(std::max(0, l - 1), r)) - w));
    }

    std::vector<Data> init(n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) a[i] = std::max(a[i], dp.get(i - 1));
        init[i] = { a[i], c[i], a[i] + c[i] };
    }
    atcoder::segtree<Data, op2, e2> seg2(init);
    long long ans = e();
    for (int r = 0; r < n; ++r) for (const auto &[l, w] : bucket[r]) {
        ans = std::max(ans, seg2.prod(l, r + 1).v - w);
    }
    std::cout << ans + std::accumulate(b.begin(), b.end(), 0LL) << std::endl;
    return 0;
}