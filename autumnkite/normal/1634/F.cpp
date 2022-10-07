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

  int n, q;
  unsigned mod;
  std::cin >> n >> q >> mod;
  mint::set_mod(mod);

  std::vector<mint> a(n);
  for (int i = 0; i < n; ++i) {
    mint v;
    std::cin >> v;
    a[i] += v;
    if (i + 1 < n) {
      a[i + 1] -= v;
    }
    if (i + 2 < n) {
      a[i + 2] -= v;
    }
  }
  for (int i = 0; i < n; ++i) {
    mint v;
    std::cin >> v;
    a[i] -= v;
    if (i + 1 < n) {
      a[i + 1] += v;
    }
    if (i + 2 < n) {
      a[i + 2] += v;
    }
  }

  std::vector<mint> fib(n + 1);
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += !a[i].val();
  }
  while (q--) {
    char op;
    int l, r;
    std::cin >> op >> l >> r;
    --l;
    if (op == 'A') {
      cnt -= !a[l].val();
      ++a[l];
      cnt += !a[l].val();
      if (r < n) {
        cnt -= !a[r].val();
        a[r] -= fib[r - l];
        cnt += !a[r].val();
      }
      if (r + 1 < n) {
        cnt -= !a[r + 1].val();
        a[r + 1] -= fib[r - l - 1];
        cnt += !a[r + 1].val();
      }
    } else {
      cnt -= !a[l].val();
      --a[l];
      cnt += !a[l].val();
      if (r < n) {
        cnt -= !a[r].val();
        a[r] += fib[r - l];
        cnt += !a[r].val();
      }
      if (r + 1 < n) {
        cnt -= !a[r + 1].val();
        a[r + 1] += fib[r - l - 1];
        cnt += !a[r + 1].val();
      }
    }
    if (cnt == n) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}