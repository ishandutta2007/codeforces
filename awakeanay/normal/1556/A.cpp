#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;

    if((a+b)%2)
      std::cout << -1 << std::endl;
    else if(a == 0 && b == 0)
      std::cout << 0 << std::endl;
    else if(a == b)
      std::cout << 1 << std::endl;
    else
      std::cout << 2 << std::endl;

  }

  return 0;
}