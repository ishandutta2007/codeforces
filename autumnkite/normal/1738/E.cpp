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

using mint = modint<998244353>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<long long> pre(a), suf(a);
    for (int i = 1; i < n; ++i) {
      pre[i] += pre[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
      suf[i] += suf[i + 1];
    }
    std::vector<mint> fac(n + 2), ifac(n + 2);
    fac[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
      fac[i] = fac[i - 1] * i;
    }
    ifac[n + 1] = fac[n + 1].inv();
    for (int i = n + 1; i >= 1; --i) {
      ifac[i - 1] = ifac[i] * i;
    }
    auto binom = [&](int n, int m) -> mint {
      if (m < 0 || m > n) {
        return mint();
      }
      return fac[n] * ifac[m] * ifac[n - m];
    };
    mint ans = 1;
    for (int i = n - 1, j = n, l = 0, r = 0; i >= 0; --i) {
      if (i > 0 && suf[i] == suf[i - 1]) {
        continue;
      }
      while (l < n && pre[l] < suf[i]) {
        ++l;
      }
      while (r < n && pre[r] <= suf[i]) {
        ++r;
      }
      if (l > i || j < r) {
        continue;
      }
      if (i < r) {
        mint sum = 0;
        int len = std::max(r, j) - std::min(l, i);
        for (int k = 0; 2 * k <= len; ++k) {
          sum += binom(len, 2 * k);
        }
        ans *= sum;
      } else {
        mint sum = 0;
        for (int k = 0; k <= r - l && k <= j - i; ++k) {
          sum += binom(r - l, k) * binom(j - i, k);
        }
        ans *= sum;
      }
      j = i;
    }
    std::cout << ans << "\n";
  }
}