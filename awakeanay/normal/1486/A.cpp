#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n; 
    std::cin >> n;

    int cur = 0;
    bool poss = true;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;

      cur += x;
      poss &= cur >= (i*(i+1))/2;
    }

    if(poss)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}