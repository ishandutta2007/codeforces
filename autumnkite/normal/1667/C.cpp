#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  if (n == 1) {
    std::cout << 1 << "\n";
    std::cout << 1 << " " << 1 << "\n";
    return 0;
  }
  int p = (n + 1) / 3;
  std::cout << n - p << "\n";
  while (n + 1 > 3 * p) {
    std::cout << n << " " << n << "\n";
    --n;
  }
  for (int i = 0; i < p; ++i) {
    std::cout << i + 1 << " " << 2 * i + 1 << "\n";
  }
  for (int i = 1; i < p; ++i) {
    std::cout << i + p << " " << 2 * i << "\n";
  }
}