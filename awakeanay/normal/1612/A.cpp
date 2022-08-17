#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int x, y;
    std::cin >> x >> y;

    if((x%2)^(y%2))
      std::cout << -1 << " " << -1 << std::endl;
    else {
      int tu = (x+y)/2;
      std::cout << std::min(x, tu) << " ";
      tu -= std::min(x, tu);
      std::cout << tu << std::endl;
    }
  }

  return 0;
}