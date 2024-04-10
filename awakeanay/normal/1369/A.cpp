#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if((n*90)%360 == 0)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }

  return 0;
}