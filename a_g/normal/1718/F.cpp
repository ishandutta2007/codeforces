#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1718/submission/168597010

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

const int M = 2300;
using bs = bitset<M>;

bs op(bs a, bs b) {
  return a|b;
}

bs e() {
  return bs(0);
}

using segtree = atcoder::segtree<bs, op, e>;

const int N = 1e5+2;
int lpf[N], prime_to_index[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(lpf, lpf+N, 0);
  fill(prime_to_index, prime_to_index+N, -1);
  int id = 0;
  for (int i = 2; i < N; i++) {
    if (lpf[i] == i) {
      prime_to_index[i] = id++;
      for (int j = 2*i; j < N; j+= i) {
        lpf[j] = i;
      }
    }
  }

  int n, m, c, q;
  cin >> n >> m >> c >> q;
  vector<bs> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x > 1) {
      a[i][prime_to_index[lpf[x]]]= 1;
      x /= lpf[x];
    }
  }
  segtree tree(a);

  vector<int> nums;
  for (int i = c; i >= 1; i--) {
    nums.push_back(c/i);
  }
  nums.resize(unique(nums.begin(), nums.end())-nums.begin());
  int k = nums.size();
  vector<int> num_to_index(c+1, -1);
  for (int i = 0; i < k; i++) {
    num_to_index[nums[i]] = i;
  }

  vector<int> dp(k);
  dp[k-1] = 1;
  vector<tuple<int, int, int>> transitions;
  for (int p = m; p >= 2; p--) {
    if (lpf[p] == p) {
      for (int i = 0; i < k; i++) {
        if (dp[i] != 0 && nums[i] >= p) {
          int j = num_to_index[nums[i]/p];
          transitions.emplace_back(i, j, p);
          dp[j] = 1;
        }
      }
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    bs mask = tree.prod(l-1, r);
    fill(dp.begin(), dp.begin()+k-1, 0);
    for (auto& [i, j, p]: transitions) {
      if (mask[prime_to_index[p]]) {
        dp[j] -= dp[i];
      }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += nums[i]*dp[i];
    }
    cout << ans << '\n';
  }
}