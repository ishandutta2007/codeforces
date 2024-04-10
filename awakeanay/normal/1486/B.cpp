#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int x[n], y[n];
    for(int i = 0; i < n; i++)
      std::cin >> x[i] >> y[i];
    std::sort(x, x+n);
    std::sort(y, y+n);

    if(n%2)
      std::cout << 1 << std::endl;
    else {
      int a = x[n/2] - x[n/2-1] + 1;
      int b = y[n/2] - y[n/2-1] + 1;
      std::cout << a*b << std::endl;
    }
  }

  return 0;
}