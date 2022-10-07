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

  int n;
  unsigned P;
  std::cin >> n >> P;
  mint::set_mod(P);

  std::vector C(n + 1, std::vector(n + 1, mint()));
  for (int i = 0; i <= n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  int bound = ceil(n - 2 * sqrt(n) - 1e-9);
  mint ans = 1;
  for (int min = n; min >= 1 && min >= bound; --min) {
    int m = n + 1 - min;
    std::vector f(n, std::vector(min + 1, mint()));
    f[0][0] = 1;
    for (int k = m; k >= 2; --k) {
      std::vector g(n, std::vector(min + 1, mint()));
      for (int i = m - k + 1; i < n; ++i) {
        for (int j = (m + k) * (m - k + 1) / 2; j <= min; ++j) {
          for (int t = 0; t <= i - m + k && k * t <= j; ++t) {
            g[i][j] += f[i - t][j - k * t] * C[i][t];
          }
        }
      }
      f = std::move(g);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= min; ++j) {
        mint s;
        for (int t = 0; t <= i && t <= j; ++t) {
          s += f[i - t][j - t] * C[i][t];
        }
        ans += s * C[n][i];
      }
    }
  }
  std::cout << ans << "\n";
}