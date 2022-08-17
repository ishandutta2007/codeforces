#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int max = -10000000000;
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      max = std::max(a[i], max);
    }

    int nmax = -10000000000;
    for(int i = 0; i < n; i++) {
      a[i] = max-a[i];
      nmax = std::max(nmax, a[i]);
    }

    k--;
    if(k%2) {
      for(int i = 0; i < n; i++)
        a[i] = nmax-a[i];
    }

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}