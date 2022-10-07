#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + a[i];
    }
    std::vector<int> f(n + 1, 1e9 + 1);
    for (int k = 1; k <= n + 1; ++k) {
      std::vector<int> g(n + 1);
      for (int i = n - 1; i >= 0; --i) {
        g[i] = g[i + 1];
        if (i + k <= n && sum[i + k] - sum[i] < f[i + k]) {
          g[i] = std::max<int>(g[i], sum[i + k] - sum[i]);
        }
      }
      f.swap(g);
      if (f[0] == 0) {
        std::cout << k - 1 << "\n";
        break;
      }
    }
  }
}