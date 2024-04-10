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

const int N = 30, L = 11;

mint f[N + 1][L + 1][L + 1][L + 1];
mint g[L + 1][L + 1][N + 1];

void init() {
  f[1][0][0][0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= L; ++j) {
      for (int k = 0; k <= L; ++k) {
        for (int l = 0; l <= L; ++l) {
          if (f[i][j][k][l].val()) {
            for (int t = 0; t <= i; ++t) {
              int nj = j + t, nk = k + (l < t);
              if (nj <= L && nk <= L) {
                f[i + 1][nj][nk][t] += f[i][j][k][l];
              } else {
                break;
              }
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= L; ++j) {
      for (int k = 0; k <= L; ++k) {
        mint sum = 0;
        for (int l = 0; l <= L; ++l) {
          sum += f[i][j][k][l];
        }
        g[j][k][i] = sum;
      }
    }
  }
}

mint calc(std::vector<mint> y, mint x) {
  int n = y.size();
  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    mint prod = 1;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        prod *= (x - j) * mint(i - j).inv();
      }
    }
    ans += prod * y[i];
  }
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  init();

  int T;
  std::cin >> T;
  while (T--) {
    int n, k, x;
    std::cin >> n >> k >> x;
    if (n <= L) {
      std::cout << g[k][x][n] << "\n";
    } else {
      std::vector<mint> tmp(g[k][x] + L + 1, g[k][x] + N + 1);
      std::cout << calc(tmp, n - L - 1) << "\n";
    }
  }
}