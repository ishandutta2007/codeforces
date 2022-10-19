#include <bits/stdc++.h>
using namespace std;

using bigint = __int128;

istream& operator >> (istream& is, bigint& x) {
  string s;
  is >> s;
  x = 0;
  for (char c: s) x = 10*x + (c-'0');
  return is;
}

ostream& operator << (ostream& os, bigint x) {
  string s;
  while (x) {
    s.push_back(x%10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return os << s;
}

bigint gcd(bigint x, bigint y) {
  return (y == 0 ? x : gcd(y, x%y));
}

bigint e() {
  return 0;
}

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

using segtree = atcoder::segtree<bigint, gcd, e>;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<bigint> a[2];
    a[0].resize(n);
    a[1].resize(m);
    for (int z = 0; z < 2; z++) {
      for (bigint& x: a[z]) cin >> x;
    }
    vector<segtree> as[2];
    for (int z = 0; z < 2; z++) {
      as[z].resize(a[z].size(), segtree(a[1-z].size()));
      for (int i = 0; i < (int)a[z].size(); i++) {
        for (int j = 0; j < (int)a[1-z].size(); j++) {
          as[z][i].set(j, a[z][i]/gcd(a[z][i], a[1-z][j]));
        }
      }
    }

    vector<bool> use[2];
    use[0].resize(n, 1);
    use[1].resize(m, 1);

    vector<pair<int, int>> que;
    for (int z = 0; z < 2; z++) {
      for (int i = 0; i < (int)a[z].size(); i++) {
        if (as[z][i].all_prod() != 1) {
          que.emplace_back(z, i);
          use[z][i] = 0;
        }
      }
    }

    for (int i = 0; i < (int)que.size(); i++) {
      int z = que[i].first;
      int r = que[i].second;
      for (int j = 0; j < (int)a[1-z].size(); j++) {
        if (use[1-z][j]) {
          as[1-z][j].set(r, a[1-z][j]);
          if (as[1-z][j].all_prod() != 1) {
            que.emplace_back(1-z, j);
            use[1-z][j] = 0;
          }
        }
      }
    }

    int sz[2];
    for (int z = 0; z < 2; z++) {
      sz[z] = accumulate(use[z].begin(), use[z].end(), 0);
    }

    if (sz[0] == 0 || sz[1] == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << sz[0] << " " << sz[1] << '\n';
    for (int z = 0; z < 2; z++) {
      for (int i = 0; i < (int)a[z].size(); i++) {
        if (use[z][i]) {
          cout << a[z][i] << ' ';
        }
      }
      cout << '\n';
    }
  }
}