#include <bits/stdc++.h>

template<unsigned id>
class dynamic_modint {
  using mint = dynamic_modint<id>;

protected:
  static unsigned P;

  unsigned v;

public:
  dynamic_modint() : v() {}

  template<typename T, 
           typename std::enable_if<
                    std::is_signed<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  dynamic_modint(T _v) {
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
  dynamic_modint(T _v) {
    v = _v % P;
  }

  unsigned val() const {
    return v;
  }

  static unsigned mod() {
    return P;
  }

  static void set_mod(unsigned nP) {
    P = nP;
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

template<unsigned id>
unsigned dynamic_modint<id>::P;

using mint = dynamic_modint<0>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  unsigned mod;
  std::cin >> n >> k >> mod;
  mint::set_mod(mod);

  int m = std::max(n, k);
  std::vector<std::vector<mint>> C(m + 1, std::vector<mint>(m + 1));
  for (int i = 0; i <= m; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }

  std::vector<std::vector<mint>> f(k + 1, std::vector<mint>(n + 1));
  for (int j = 0; j <= n; ++j) {
    f[0][j] = 1;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = mint(2).pow(i * j);
      for (int di = 1; di <= i; ++di) {
        mint c = 1, now = mint(2).pow(di) - 1, pw = mint(2).pow(i - di);
        for (int dj = 0; dj <= j; ++dj) {
          f[i][j] -= f[i - di][j - dj] * C[i][di] * C[j][dj] * c;
          c *= now--;
          c *= pw;
        }
      }
    }
  }
  mint ans = mint(2).pow(n * k);
  for (int di = 1; di <= k; ++di) {
    mint c = 1, now = mint(2).pow(di) - 1, pw = mint(2).pow(k - di);
    for (int dj = 0; dj <= n; ++dj) {
      if (dj > (n & 1)) {
        ans -= f[k - di][n - dj] * C[k][di] * C[n][dj] * c;
      }
      c *= now--;
      c *= pw;
    }
  }
  std::cout << ans << "\n";
}