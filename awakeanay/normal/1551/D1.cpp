#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int min = 0;
    if(n%2)
      min = m/2;
    int max = (n*m)/2;
    if(m%2)
      max = (n*m)/2 - n/2;
    if(k >= min && k <= max && k%2 == min%2)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}