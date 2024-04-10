#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    if (m == 1) {
      std::cout << "YES\n";
      for (int i = 1; i <= n; ++i) {
        std::cout << i << "\n";
      }
      continue;
    }
    if (n & 1) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; i += 2) {
      for (int j = 1; j <= 2 * m; j += 2) {
        std::cout << i * m + j << " ";
      }
      std::cout << "\n";
      for (int j = 2; j <= 2 * m; j += 2) {
        std::cout << i * m + j << " ";
      }
      std::cout << "\n";
    }
  }
}