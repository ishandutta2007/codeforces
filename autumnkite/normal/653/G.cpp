#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P);

  using mint = modint<P>;

protected:
  unsigned v;

public:
  modint() : v() {}

  template<typename T, 
           typename std::enable_if<
                    std::is_signed<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  modint(T _v) {
    long long tmp = _v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T, 
           typename std::enable_if<
                    std::is_unsigned<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  modint(T _v) {
    v = _v % P;
  }

  unsigned val() const {
    return v;
  }

  static constexpr unsigned mod() {
    return P;
  }

  static mint raw(unsigned v) {
    mint res;
    res.v = v;
    return res;
  }

  mint &operator+=(const mint &rhs) {
    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
    return *this;
  }

  mint &operator++() {
    v + 1 < P ? ++v : v = 0;
    return *this;
  }

  mint operator++(int) {
    mint tmp = *this;
    v + 1 < P ? ++v : v = 0;
    return tmp;
  }

  mint &operator-=(const mint &rhs) {
    v < rhs.v ? v += P - rhs.v : v -= rhs.v;
    return *this;
  }

  mint &operator--() {
    v == 0 ? v = P - 1 : --v;
    return *this;
  }

  mint operator--(int) {
    mint tmp = *this;
    v == 0 ? v = P - 1 : --v;
    return tmp;
  }

  mint operator-() const {
    mint res;
    res.v = v == 0 ? 0 : P - v;
    return res;
  }

  mint &operator*=(const mint &rhs) {
    v = static_cast<unsigned long long>(v) * rhs.v % P;
    return *this;
  }

  mint pow(unsigned long long b) const {
    mint a(*this), s(1);
    for (; b; b >>= 1) {
      if (b & 1) {
        s *= a;
      }
      a *= a;
    }
    return s;
  }

  mint inv() const {
    return pow(P - 2);
  }

  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }

  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }

  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }

  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.v == rhs.v;
  }

  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs.v != rhs.v;
  }

  friend std::istream &operator>>(std::istream &in, mint &x) {
    return in >> x.v;
  }

  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.v;
  }
};

using mint = modint<1000000007>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  int m = 1;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    m = std::max(m, a[i]);
  }
  
  std::vector<int> minp(m + 1);
  std::iota(minp.begin(), minp.end(), 0);
  std::vector<int> id(m + 1, -1);
  int idx = 0;
  for (int i = 2; i <= m; ++i) {
    if (minp[i] == i) {
      id[i] = idx++;
      for (int j = i + i; j <= m; j += i) {
        minp[j] = std::min(minp[j], i);
      }
    }
  }

  int lg = std::__lg(m) + 1;
  std::vector<std::vector<int>> cnt(idx, std::vector<int>(lg));
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int lst = -1, c = 0;
    while (x > 1) {
      if (minp[x] == lst) {
        ++c;
      } else {
        if (lst != -1) {
          ++cnt[id[lst]][c];
        }
        lst = minp[x];
        c = 1;
      }
      x /= minp[x];
    }
    if (lst != -1) {
      ++cnt[id[lst]][c];
    }
  }

  std::vector<mint> fac(n + 1), ifac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  ifac[n] = fac[n].inv();
  for (int i = n; i >= 1; --i) {
    ifac[i - 1] = ifac[i] * i;
  }

  std::vector<mint> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = pw[i - 1] * 2;
  }

  auto binom = [&](int n, int m) {
    if (m < 0 || m > n) {
      return mint();
    }
    return fac[n] * ifac[m] * ifac[n - m];
  };

  std::vector<bool> vis(n + 1);
  std::vector<mint> f(n + 1);

  auto calc = [&](int c) {
    c = std::min(c, n - c);
    if (vis[c]) {
      return f[c];
    }
    vis[c] = true;
    mint ans = 0, suf = pw[n - c] - 1, pre = 0;
    for (int i = 1; i <= c; ++i) {
      suf -= binom(n - c, i);
      pre += binom(n - c - 1, i - 1);
      ans += c * binom(c - 1, i - 1) * suf;
      ans += (n - c) * binom(c, i) * pre;
    }
    return f[c] = ans;
  };

  mint ans = 0;
  for (int i = 0; i < idx; ++i) {
    int c = 0;
    for (int j = lg - 1; j > 0; --j) {
      c += cnt[i][j];
      ans += calc(c);
    }
  }
  std::cout << ans << "\n";
}