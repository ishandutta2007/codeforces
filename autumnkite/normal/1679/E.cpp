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

  int n;
  std::cin >> n;
  std::string a;
  std::cin >> a;
  
  int all = std::count(a.begin(), a.end(), '?');

  int c = 17;

  std::vector<std::vector<mint>> f(c, std::vector<mint>(1 << c));
  
  for (int i = 0; i < n; ++i) {
    for (int d = 0; d < 2; ++d) {
      int l = i, r = i + d;
      int mask = 0;
      int cnt = 0;
      while (l >= 0 && r < n) {
        if (a[l] != a[r]) {
          if (a[l] == '?') {
            ++cnt;
            mask |= 1 << (a[r] - 'a');
          } else if (a[r] == '?') {
            ++cnt;
            mask |= 1 << (a[l] - 'a');
          } else {
            break;
          }
        } else if (a[l] == '?' && l != r) {
          ++cnt;
        }
        for (int k = 0; k < c; ++k) {
          f[k][mask] += mint(k + 1).inv().pow(cnt);
        }
        --l, ++r;
      }
    }
  }
  
  for (int k = 0; k < c; ++k) {
    for (int i = 0; i < c; ++i) {
      for (int S = 0; S < (1 << c); ++S) {
        if (S >> i & 1) {
          f[k][S] += f[k][S ^ (1 << i)];
        }
      }
    }
  }

  int q;
  std::cin >> q;
  while (q--) {
    std::string t;
    std::cin >> t;
    int k = t.size();
    int mask = 0;
    for (char c : t) {
      mask |= 1 << (c - 'a');
    }
    std::cout << f[k - 1][mask] * mint(k).pow(all) << "\n";
  }
}