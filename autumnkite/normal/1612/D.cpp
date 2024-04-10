#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long a, b, x;
    std::cin >> a >> b >> x;
    auto solve = [&](auto &self, long long a, long long b) -> bool {
      if (b == 0) {
        return a == x;
      } else {
        if (x <= a && a % b == x % b) {
          return true;
        }
        return self(self, b, a % b);
      }
    };
    std::cout << (solve(solve, a, b) ? "YES" : "NO") << "\n";
  }
}