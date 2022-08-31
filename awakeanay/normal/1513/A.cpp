#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int lim = (n-1)/2;
    int a[n];
    for(int i = 0; i < n; i++)
      a[i] = i+1;
    
    if(k > lim) {
      std::cout << -1 << std::endl;
      continue;
    }

    for(int j = 1; j <= 2*k; j+=2) {
      a[j] ^= a[j+1] ^= a[j] ^= a[j+1];
    }

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}