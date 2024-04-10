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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> A;
  mint zero = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x > 0) {
      A.emplace_back(x, 0);
    } else if (x < 0) {
      A.emplace_back(-x, 1);
    } else {
      zero *= 2;
    }
  }
  n = A.size();
  if (k > n) {
    std::cout << 0 << "\n";
    return 0;
  }
  std::sort(A.begin(), A.end());
  std::vector<int> a(n), sgn(n);
  std::vector<mint> inv(n);
  for (int i = 0; i < n; ++i) {
    a[i] = A[i].first;
    sgn[i] = A[i].second;
    inv[i] = mint(a[i]).inv();
  }
  std::vector<mint> pw(n + 1);
  pw[0] = 1;
  for (int i = 0; i < n; ++i) {
    pw[i + 1] = pw[i] * 2;
  }
  mint inv2 = mint(2).inv();

  std::vector<std::vector<std::array<mint, 2>>> f(
      n + 1, std::vector<std::array<mint, 2>>(n + 1));
  f[n][0][0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= n - i; ++j) {
      for (int p = i + 1; p <= n; ++p) {
        f[i][j][0] += f[p][j - 1][0];
        f[i][j][1] += f[p][j - 1][1];
      }
      f[i][j][0] *= a[i];
      f[i][j][1] *= a[i];
      if (sgn[i]) {
        std::swap(f[i][j][0], f[i][j][1]);
      }
    }
  }

  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f[i][k][0] * pw[i] * zero;
  }
  for (int i = 0; i < n; ++i) {
    std::vector<mint> g(n + 1);
    g[1] = a[i];
    for (int p = i + 1; p < n; ++p) {
      if (sgn[p] != sgn[i]) {
        mint prod = 0;
        for (int j = 1; j < k && j <= n - p; ++j) {
          prod += f[p][j][1 ^ (sgn[i] * ((k - j) & 1))] * g[k - j];
        }
        ans -= prod;
        {
          int x = 0, c = 0;
          mint sum = 1;
          for (int y = 0; y < i; ++y) {
            if (sgn[y] == sgn[i]) {
              while (x < y && 1ll * a[x] * a[p] <= 1ll * a[y] * a[i]) {
                if (sgn[x] != sgn[i]) {
                  sum += pw[x + c];
                } else {
                  --c;
                }
                ++x;
              }
              ans += sum * inv[p] * a[y] * prod * zero;
              ++c;
              sum *= 2;
            } else {
              ans += pw[y] * inv[i] * a[y] * prod * zero;
            }
          }
        }
        {
          int y = i - 1, c = 0;
          mint sum = 0;
          for (int x = i - 1; x >= 0; --x) {
            if (sgn[x] != sgn[i]) {
              while (y > x && 1ll * a[x] * a[p] <= 1ll * a[y] * a[i]) {
                if (sgn[y] == sgn[i]) {
                  --c;
                  sum -= pw[x + c];
                }
                --y;
              }
              ans += sum * inv[i] * a[x] * prod * zero;
              sum *= inv2;
            } else {
              ++c;
              sum += pw[x] * inv2;
            }
          }
        }
      } else {
        for (int j = p - i; j >= 0; --j) {
          g[j + 1] += g[j] * a[p];
        }
      }
    }
  }

  if (k & 1) {
    {
      std::vector<mint> g(k + 1);
      g[0] = 1;
      for (int i = n - 1; i >= 0; --i) {
        if (sgn[i]) {
          mint prod = g[k - 1] * a[i];
          for (int j = k; j >= 1; --j) {
            g[j] += g[j - 1] * a[i];
          }
          int c = 0;
          for (int x = i - 1; x >= 0; --x) {
            if (sgn[x]) {
              ++c;
            } else {
              ans += prod * inv[i] * a[x] * pw[x + c] * zero;
            }
          }
        }
      }
    }
    {
      int suf = 0;
      for (int i = 0; i < n; ++i) {
        suf += sgn[i];
      }
      std::vector<mint> g(k + 1);
      g[0] = 1;
      for (int i = 0; i < n; ++i) {
        if (sgn[i]) {
          --suf;
          ans -= g[k - 1] * a[i] * pw[suf];
          for (int j = k; j >= 1; --j) {
            g[j] += g[j - 1] * a[i];
          }
        }
      }
    }
  }
  std::cout << ans << "\n";
}