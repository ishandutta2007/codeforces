#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int x;
    std::cin >> x;

    int u = x%10;
    int c = 0;
    while(x > 0) {
      c++;
      x /= 10;
    }

    std::cout << (u-1)*10 + ((c)*(c+1))/2 << std::endl;
  }

  return 0;
}