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

    int poss = true;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      poss &= x >= 0;
    }

    if(poss) {
      std::cout << "YES" << std::endl;
      std::cout << 101 << std::endl;
      for(int i = 0; i <= 100; i++)
        std::cout << i << " ";
      std::cout << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}