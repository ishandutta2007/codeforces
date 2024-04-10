#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    if (m < n) {
      std::cout << "No\n";
      continue;
    }
    if (n & 1) {
      std::cout << "Yes\n";
      std::cout << m - n + 1;
      for (int i = 1; i < n; ++i) {
        std::cout << " 1";
      }
      std::cout << "\n";
      continue;
    }
    if (m % 2 != 0) {
      std::cout << "No\n";
      continue;
    }
    std::cout << "Yes\n";
    std::cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2;
    for (int i = 2; i < n; ++i) {
      std::cout << " 1";
    }
    std::cout << "\n";
  }
}