#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int r, b, d;
    std::cin >> r >> b >> d;

    if(r < b)
      r ^= b ^= r ^= b;

    if((d+1)*b < r)
      std::cout << "NO" << std::endl;
    else
      std::cout << "YES" << std::endl;
  }

  return 0;
}