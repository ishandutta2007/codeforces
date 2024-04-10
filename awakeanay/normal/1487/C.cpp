#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n%2 == 0) {
      for(int i = 1; i <= n; i++) {
        if(i%2) {
          if(i < n)
            std::cout << 0 << " ";
          for(int j = i+2; j <= n; j++)
            std::cout << ((j%2) ? 1 : -1) << " ";
        }
        else {
          for(int j = i+1; j <= n; j++)
            std::cout << (!(j%2) ? 1 : -1) << " ";
        }
      }
    }
    else {
      for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
          std::cout << (((i%2)^(j%2)) ? 1 : -1) << " ";
        }
      }
    }

    std::cout << std::endl;
  }

  return 0;
}