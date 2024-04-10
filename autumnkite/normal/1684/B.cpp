#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << a + (c / b + 1) * b << " " << b << " " << c << "\n";
  }
}