#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P);

  using mint = modint<P>;

protected:
  unsigned v;

public:
  constexpr modint() : v() {}

  template<typename T, 
           typename std::enable_if<
                    std::is_signed<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  constexpr modint(T _v) : v() {
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
  constexpr modint(T _v) : v() {
    v = _v % P;
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
    v == 0 ? v = P - 1 : --v;
    return *this;
  }

  constexpr mint operator--(int) {
    mint tmp = *this;
    v == 0 ? v = P - 1 : --v;
    return tmp;
  }

  constexpr mint operator-() const {
    mint res;
    res.v = v == 0 ? 0 : P - v;
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

using mint = modint<998244353>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      int v;
      std::cin >> v;
      ++c[--v];
    }
    std::vector<int> S;
    int g = 0;
    for (int i = 0; i < n; ++i) {
      if (c[i]) {
        S.push_back(c[i]);
        g = std::gcd(g, c[i]);
      }
    }
    if (g == n) {
      std::cout << 1 << "\n";
      continue;
    }
    std::vector<int> mu(n + 1);
    mu[1] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + i; j <= n; j += i) {
        mu[j] -= mu[i];
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

    std::vector<mint> f(g + 1), h(g + 1);

    auto calc = [&](int n, int m) {
      return mint::raw(m) * mint::raw(n - m) * fac[n - 2] * ifac[n - 1];
    };

    for (int i = 1; i <= g; ++i) {
      if (g % i == 0) {
        f[i] = 0;
        h[i] = fac[n / i];
        for (int x : S) {
          f[i] += calc(n / i, x / i);
          h[i] *= ifac[x / i];
        }
        f[i] *= i;
      }
    }
    mint ansA = 0, ansB = 0;
    for (int i = g; i >= 1; --i) {
      if (g % i == 0) {
        f[i] *= h[i];
        for (int j = i + i; j <= g; j += i) {
          f[i] -= f[j];
          h[i] -= h[j];
        }
        ansA += f[i] * i;
        ansB += h[i] * i;
      }
    }
    std::cout << ansA * ansB.inv() << "\n";
  }
}