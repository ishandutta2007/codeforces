#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;

    int max = -1;
    int last = 0;
    for(int i = 0; i < n; i++) {
      int u;
      std::cin >> u;
      last = (last + u)%x;
      if(last) max = std::max(max, std::max(i+1, n-i-1));
    }

    std::cout << max << std::endl;
  }

  return 0;
}