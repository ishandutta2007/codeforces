#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      std::cout << i;
      for (int j = n; j >= 1; --j) {
        if (j != i) {
          std::cout << " " << j;
        }
      }
      std::cout << "\n";
    }
  }
}