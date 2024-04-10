#include <bits/stdc++.h>

const long long INF = std::numeric_limits<long long>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  std::cin >> n;

  const int L = 1000000;
  std::vector<long long> f(L, -INF);
  
  auto insert = [&](auto &f, int w, long long v) {
    for (int i = L - 1; i >= w; --i) {
      f[i] = std::max(f[i], f[i - w] + v);
    }
  };

  f[0] = 0;
  int pw = 1;
  for (int i = 0; i < 6; ++i) {
    int v;
    std::cin >> v;
    int lim = std::min(L / pw / 3, (n - 1) * 3);
    int lg = std::__lg(lim + 1);
    for (int k = 0; k < lg; ++k) {
      insert(f, 3 * pw << k, 1ll * v << k);
    }
    int rem = lim - (1 << lg) + 1;
    insert(f, 3 * pw * rem, 1ll * v * rem);
    auto g = f;
    for (int k = 0; k < 9; ++k) {
      insert(f, pw, 0);
    }
    for (int k = 0; k < 3; ++k) {
      insert(g, 3 * pw, v);
    }
    for (int i = 0; i < L; ++i) {
      f[i] = std::max(f[i], g[i]);
    }
    pw *= 10;
  }

  int q;
  std::cin >> q;
  while (q--) {
    int n;
    std::cin >> n;
    std::cout << f[n] << "\n";
  }
}