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

    int x;
    for(int i = 0; i < n; i++)
      std::cin >> x;
    std::cout << x << std::endl;
  }

  return 0;
}