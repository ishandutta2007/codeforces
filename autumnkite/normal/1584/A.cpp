#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << 1ll * a * a << " " << -1ll * b * b << "\n";
  }
}