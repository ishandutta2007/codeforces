#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long n;
    std::cin >> n;
    if (n & 1 || n <= 2) {
      std::cout << -1 << "\n";
    } else {
      n /= 2;
      long long max = n / 2;
      long long min = max;
      for (int i = 0; i < 3; ++i) {
        if (n >= 2 * i && (n - 2 * i) % 3 == 0) {
          min = std::min(min, (n - 2 * i) / 3 + i);
        }
      }
      std::cout << min << " " << max << "\n";
    }
  }
}