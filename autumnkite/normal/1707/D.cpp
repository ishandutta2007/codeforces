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
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_signed<T>::value,
                                   bool>::type = true>
  dynamic_modint(T t_v) : v() {
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
  dynamic_modint(T t_v) : v() {
    v = t_v % P;
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
    v ? --v : v = P - 1;
    return *this;
  }
  
  mint operator--(int) {
    mint tmp = *this;
    v ? --v : v = P - 1;
    return tmp;
  }

  mint operator-() const {
    mint res;
    res.v = v ? P - v : 0;
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

  int n, mod;
  std::cin >> n >> mod;
  mint::set_mod(mod);
  std::vector<std::vector<int>> E(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  std::vector<std::vector<mint>> f(n, std::vector<mint>(n - 1));
  std::vector<mint> g(n), h(n), pre(n);
  
  auto dfs = [&](auto &self, int u, int fa) -> void {
    for (int v : E[u]) {
      if (v != fa) {
        self(self, v, u);
        g[v] = 0;
        h[v] = 0;
      }
    }
    for (int k = 0; k < n - 1; ++k) {
      f[u][k] = 1;
      for (int v : E[u]) {
        if (v != fa) {
          g[v] += f[v][k];
          pre[v] = f[u][k];
          f[u][k] *= g[v];
        }
      }
      if (fa != -1) {
        for (int v : E[u]) {
          if (v != fa) {
            f[u][k] += f[v][k] * h[v];
          }
        }
        mint now = 1;
        for (int i = (int)E[u].size() - 1; i >= 0; --i) {
          int v = E[u][i];
          if (v != fa) {
            h[v] += pre[v] * now;
            now *= g[v];
          }
        }
      }
    }
  };

  dfs(dfs, 0, -1);
  std::vector<std::vector<mint>> C(n, std::vector<mint>(n));
  for (int i = 0; i < n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  std::vector<mint> ans = f[0];
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 0; j < i; ++j) {
      ans[i] -= ans[j] * C[i + 1][j + 1];
    }
  }
  for (auto x : ans) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}