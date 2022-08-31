#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a[3];
    std::cin >> a[0] >> a[1] >> a[2];

    int x = a[0] + a[2] - 2*a[1];
    if(x < 0)
      x = -x;

    std::cout << (x%3 == 0 ? 0 : 1) << std::endl;
  }

  return 0;
}