#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int a, b;
    std::cin >> a >> b;
    int lg = std::__lg(b);
    int ans = b - a;
    for (int x = a; x < b; ++x) {
      int s = x - a;
      int p = lg;
      while (p >= 0 && (!(x >> p & 1) || b >> p & 1)) {
        --p;
      }
      for (int i = 0; i <= p; ++i) {
        if ((x ^ b) >> i & 1) {
          if (x >> i & 1) {
            s += 1 << i;
          } else {
            s -= 1 << i;
          }
        }
      }
      ans = std::min(ans, s + 1);
    }
    std::cout << ans << "\n";
  }
}