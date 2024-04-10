#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;

    int h[2*n];
    for(int i = 0; i < 2*n; i++)
      std::cin >> h[i];

    std::sort(h, h+2*n);
    bool poss = true;
    for(int i = n; i < 2*n; i++) {
      poss &= h[i] >= h[i-n] + x;
    }

    std::cout << (poss ? "YES" : "NO") << "\n";
  }

  return 0;
}