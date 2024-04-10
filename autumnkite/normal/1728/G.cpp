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

  int d, n, m;
  std::cin >> d >> n >> m;
  std::vector<bool> lan(d + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    lan[x] = true;
  }
  std::vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> p[i];
  }
  std::sort(p.begin(), p.end());

  std::vector<std::vector<mint>> g(m + 2, std::vector<mint>(m + 2));
  for (int i = 0; i <= m; ++i) {
    for (int j = i + 1; j <= m + 1; ++j) {
      g[i][j] = 1;
      int l = i ? p[i - 1] : -d;
      int r = j <= m ? p[j - 1] : d + d;
      for (int k = std::max(l, 0); k <= std::min(r, d); ++k) {
        if (lan[k]) {
          g[i][j] *= std::min(d + 1, std::min(k - l, r - k));
        }
      }
    }
  }

  std::vector<mint> f(1 << m);
  for (int S = 0; S < (1 << m); ++S) {
    int lst = -1;
    f[S] = 1;
    for (int i = 0; i < m; ++i) {
      if (S >> i & 1) {
        f[S] *= -g[lst + 1][i + 1];
        lst = i;
      }
    }
    f[S] *= g[lst + 1][m + 1];
  }
  for (int i = 0; i < m; ++i) {
    for (int S = 0; S < (1 << m); ++S) {
      if (S >> i & 1) {
        f[S] += f[S ^ (1 << i)];
      }
    }
  }

  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;
    mint ans = 0;
    for (int i = m - 1, j = 0; i >= 0; --i) {
      if (p[i] >= x) {
        continue;
      }
      while (j < m && x - p[i] > p[j] - x) {
        ++j;
      }
      int S = ((1 << (m - j)) - 1) << j | ((1 << i) - 1);
      ans += (f[S | (1 << i)] - f[S]) * (x - p[i]);
    }
    for (int i = 0, j = m - 1; i < m; ++i) {
      if (p[i] <= x) {
        continue;
      }
      while (j >= 0 && p[i] - x >= x - p[j]) {
        --j;
      }
      int S = ((1 << (m - i - 1)) - 1) << (i + 1) | ((1 << (j + 1)) - 1);
      ans += (f[S | (1 << i)] - f[S]) * (p[i] - x);
    }
    ans += f[0] * (d + 1);
    std::cout << ans << "\n";
  }
}