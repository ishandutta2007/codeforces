#include <algorithm>
#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      if(i < 2)
        std::cout << 9 - (i%10);
      else
        std::cout << (i+7)%10;
    }

    std::cout << std::endl;
  }

  return 0;
}