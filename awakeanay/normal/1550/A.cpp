#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int s;
    std::cin >> s;

    int n = 1;
    while(n*n < s)
      n++;
    std::cout << n << std::endl;
  }

  return 0;
}