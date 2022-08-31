#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::cout << n-k+(k/2) << std::endl;
    for(int i = k-1; 2*i >= k; i--)
      std::cout << i << " ";
    for(int i = k+1; i <= n; i++)
      std::cout << i << " ";
    std::cout << std::endl;

  }

  return 0;
}