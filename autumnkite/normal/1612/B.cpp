#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    n /= 2;
    if (a == n + 1 && b == n) {
      for (int i = 2 * n; i >= 1; --i) {
        std::cout << i << " ";
      }
      std::cout << "\n";
      continue;
    }
    if (a > n || b <= n) {
      std::cout << -1 << "\n";
      continue;
    }
    std::cout << a << " ";
    for (int i = n + 1; i < b; ++i) {
      std::cout << i << " ";
    }
    for (int i = b + 1; i <= 2 * n; ++i) {
      std::cout << i << " ";
    }
    std::cout << b << " ";
    for (int i = 1; i < a; ++i) {
      std::cout << i << " ";
    }
    for (int i = a + 1; i <= n; ++i) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}