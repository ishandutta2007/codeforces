#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int maxA = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      cur += x;
      maxA = std::max(cur, maxA);
    }

    int maxB = 0;
    cur = 0;
    int m;
    std::cin >> m;

    for(int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      cur += x;
      maxB = std::max(cur, maxB);
    }
    
    std::cout << maxA + maxB << std::endl;
  }

  return 0;
}