#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int t = n/3;
    if(n-3*t == 2)
      t++;
    std::cout << n-2*t << " " << t << std::endl;
  }

  return 0;
}