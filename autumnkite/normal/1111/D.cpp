#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P, "P must be a positive integer");

  using mint = modint<P>;

protected:
  unsigned v;

public:
  constexpr modint() : v() {}

  template<typename T,
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_signed<T>::value,
                                   bool>::type = true>
  constexpr modint(T t_v) : v() {
    long long tmp = t_v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T,
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_unsigned<T>::value,
                                   bool>::type = true>
  constexpr modint(T t_v) : v() {
    v = t_v % P;
  }

  constexpr unsigned val() const {
    return v;
  }

  static constexpr unsigned mod() {
    return P;
  }

  static constexpr mint raw(unsigned v) {
    mint res;
    res.v = v;
    return res;
  }

  constexpr mint &operator+=(const mint &rhs) {
    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
    return *this;
  }

  constexpr mint &operator++() {
    v + 1 < P ? ++v : v = 0;
    return *this;
  }

  constexpr mint operator++(int) {
    mint tmp = *this;
    v + 1 < P ? ++v : v = 0;
    return tmp;
  }

  constexpr mint &operator-=(const mint &rhs) {
    v < rhs.v ? v += P - rhs.v : v -= rhs.v;
    return *this;
  }

  constexpr mint &operator--() {
    v ? --v : v = P - 1;
    return *this;
  }
  
  constexpr mint operator--(int) {
    mint tmp = *this;
    v ? --v : v = P - 1;
    return tmp;
  }

  constexpr mint operator-() const {
    mint res;
    res.v = v ? P - v : 0;
    return res;
  }

  constexpr mint &operator*=(const mint &rhs) {
    v = static_cast<unsigned long long>(v) * rhs.v % P;
    return *this;
  }

  constexpr mint pow(unsigned long long b) const {
    mint a(*this), s(1);
    for (; b; b >>= 1) {
      if (b & 1) {
        s *= a;
      }
      a *= a;
    }
    return s;
  }

  constexpr mint inv() const {
    return pow(P - 2);
  }

  constexpr friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }

  constexpr friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }

  constexpr friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }

  constexpr friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.v == rhs.v;
  }

  constexpr friend bool operator!=(const mint &lhs, const mint &rhs) {
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

class binom {
  std::vector<mint> fac, ifac;

public:
  binom(int n) : fac(n + 1), ifac(n + 1) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fac[i] = fac[i - 1] * i;
    }
    ifac[n] = fac[n].inv();
    for (int i = n; i >= 1; --i) {
      ifac[i - 1] = ifac[i] * i;
    }
  }

  mint fact(int n) const {
    return fac[n];
  }

  mint ifact(int n) const {
    return ifac[n];
  }

  mint operator()(int n, int m) const {
    if (m < 0 || m > n) {
      return mint();
    }
    return fac[n] * ifac[m] * ifac[n - m];
  }
};

int get(char x) {
  return isupper(x) ? x - 'A' : x - 'a' + 26;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;
  int n = 52, m = s.size() / 2;
  std::vector<int> cnt(n);
  for (char c : s) {
    ++cnt[get(c)];
  }
  std::vector<std::vector<mint>> f(n + 1, std::vector<mint>(m + 1));
  f[n][0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    f[i] = f[i + 1];
    if (cnt[i]) {
      for (int j = m; j >= cnt[i]; --j) {
        f[i][j] += f[i + 1][j - cnt[i]];
      }
    }
  }
  std::vector<mint> g(m + 1);
  std::vector<std::vector<mint>> ans(n, std::vector<mint>(n));
  g[0] = 1;
  for (int i = 0; i < n; ++i) {
    if (cnt[i]) {
      auto tmp = g;
      for (int j = i + 1; j < n; ++j) {
        if (cnt[j]) {
          for (int k = 0; k <= m - cnt[i] - cnt[j]; ++k) {
            ans[i][j] += g[k] * f[j + 1][m - cnt[i] - cnt[j] - k];
          }
          ans[j][i] = ans[i][j];
          for (int k = m; k >= cnt[j]; --k) {
            g[k] += g[k - cnt[j]];
          }
        }
      }
      g.swap(tmp);
      for (int j = m; j >= cnt[i]; --j) {
        g[j] += g[j - cnt[i]];
      }
    }
  }
  
  binom C(s.size());
  mint prod = C.fact(m) * C.fact(m);
  for (int i = 0; i < n; ++i) {
    prod *= C.ifact(cnt[i]);
  }

  int q;
  std::cin >> q;
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    --x, --y;
    x = get(s[x]), y = get(s[y]);
    if (x == y) {
      std::cout << g[m] * prod << "\n";
    } else {
      std::cout << ans[x][y] * prod * 2 << "\n";
    }
  }
}