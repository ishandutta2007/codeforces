#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, x;
    long long y;
    std::cin >> n >> x >> y;
    x &= 1, y &= 1;
    for (int i = 0; i < n; ++i) {
      int v;
      std::cin >> v;
      x ^= v & 1;
    }
    std::cout << (x == y ? "Alice" : "Bob") << "\n";
  }
}