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

class disjoint_set {
public:
  typedef std::size_t size_type;

protected:
  std::vector<size_type> fa;

public:
  disjoint_set(size_type n = 0) : fa(n) {
    std::iota(fa.begin(), fa.end(), 0);
  }

  size_type find(size_type x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
  }

  bool merge(size_type x, size_type y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    fa[y] = x;
    return true;
  }
};

using mint = modint<998244353>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    std::string tmp;
    std::cin >> tmp;
    for (int j = 0; j < m; ++j) {
      a[i][j] = tmp[j] == '?' ? -1 : tmp[j] - '0';
    }
  }

  std::vector<mint> pw(n * m + 1);
  pw[0] = 1;
  for (int i = 0; i < n * m; ++i) {
    pw[i + 1] = pw[i] + pw[i];
  }

  if (!(n & 1) && !(m & 1)) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == -1) {
          ++cnt;
        }
      }
    }
    std::cout << pw[cnt] << "\n";
    return 0;
  }

  if (!(n & 1)) {
    mint ans;
    for (int k = 0; k < 2; ++k) {
      mint prod = 1;
      for (int i = 0; i < n; ++i) {
        int cnt = 0, sum = 0;
        for (int j = 0; j < m; ++j) {
          if (a[i][j] == -1) {
            ++cnt;
          } else {
            sum ^= a[i][j];
          }
        }
        if (cnt == 0) {
          if (sum != k) {
            prod = 0;
            break;
          }
        } else {
          prod *= pw[cnt - 1];
        }
      }
      ans += prod;
    }
    std::cout << ans << "\n";
    return 0;
  }

  if (!(m & 1)) {
    mint ans;
    for (int k = 0; k < 2; ++k) {
      mint prod = 1;
      for (int j = 0; j < m; ++j) {
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
          if (a[i][j] == -1) {
            ++cnt;
          } else {
            sum ^= a[i][j];
          }
        }
        if (cnt == 0) {
          if (sum != k) {
            prod = 0;
            break;
          }
        } else {
          prod *= pw[cnt - 1];
        }
      }
      ans += prod;
    }
    std::cout << ans << "\n";
    return 0;
  }

  disjoint_set D(n + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == -1) {
        D.merge(i, j + n);
      }
    }
  }
  mint ans;
  for (int k = 0; k < 2; ++k) {
    std::vector<int> sum(n + m), cnt(n + m, 1);
    for (int i = 0; i < n; ++i) {
      sum[D.find(i)] ^= k;
      --cnt[D.find(i)];
    }
    for (int j = 0; j < m; ++j) {
      sum[D.find(n + j)] ^= k;
      --cnt[D.find(n + j)];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == -1) {
          ++cnt[D.find(i)];
        } else {
          sum[D.find(i)] ^= a[i][j];
          sum[D.find(n + j)] ^= a[i][j];
        }
      }
    }
    mint prod = 1;
    for (int u = 0; u < n + m; ++u) {
      if ((int)D.find(u) == u) {
        if (sum[u]) {
          prod = 0;
          break;
        } else {
          prod *= pw[cnt[u]];
        }
      }
    }
    ans += prod;
  }
  std::cout << ans << "\n";
}