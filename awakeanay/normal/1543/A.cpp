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

    int diff = (a > b ? a-b : b-a);
    if(diff == 0) {
      std::cout << 0 << " " << 0 << std::endl;
    }
    else {
      std::cout << diff << " " << std::min(diff-a%diff, a%diff) << std::endl;
    }
  }

  return 0;
}