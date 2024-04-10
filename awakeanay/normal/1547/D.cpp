#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int x[n];
    for(int i = 0; i < n; i++) {
      std::cin >> x[i];
    }

    int y[n];
    y[0] = 0;

    for(int i = 1; i < n; i++) {
      int last = x[i-1]^y[i-1];
      y[i] = 0;
      for(int j = 0; j < 30; j++) {
        if((last >> j)&1) {
          if(((x[i] >> j)&1) == 0)
            y[i] ^= (1 << j);
        }
      }
    }

    for(int j: y)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}