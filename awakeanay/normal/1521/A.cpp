#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;

    if(b == 1)
      std::cout << "NO" << std::endl;
    else {
      std::cout << "YES" << std::endl;
      std::cout << a << " " << a*b << " " << a*(b+1) << std::endl;
    }
  }

  return 0;
}