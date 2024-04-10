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
    int c = std::count(a.begin(), a.end(), 0);
    if (c) {
      std::cout << n - c << "\n";
    } else {
      std::sort(a.begin(), a.end());
      if (std::unique(a.begin(), a.end()) != a.end()) {
        std::cout << n << "\n";
      } else {
        std::cout << n + 1 << "\n";
      }
    }
  }
}