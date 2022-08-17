#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b, c;
    std::cin >> a >> b >> c;

    if(a >= c)
      std::cout << -1 << " ";
    else
      std::cout << 1 << " ";
    
    if(c >= b*a)
      std::cout << -1 << std::endl;
    else
      std::cout << b << std::endl;

  }

  return 0;
}