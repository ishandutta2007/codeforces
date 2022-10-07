#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(1, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      std::cin >> a[0][i];
    }
    while (1) {
      std::vector<int> c(n + 1);
      for (int x : a.back()) {
        ++c[x];
      }
      a.emplace_back(a.back());
      bool ok = true;
      for (int &x : a.back()) {
        ok &= x == c[x];
        x = c[x];
      }
      if (ok) {
        break;
      }
    }
    int q;
    std::cin >> q;
    while (q--) {
      int x, k;
      std::cin >> x >> k;
      --x;
      k = std::min(k, (int)a.size() - 1);
      std::cout << a[k][x] << "\n";
    }
  }
}