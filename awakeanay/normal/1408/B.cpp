#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;
    
    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int dist = 1;
    for(int i = 1; i < n; i++)
      if(a[i] != a[i-1])
        dist++;

    if(dist > 1 && k == 1) {
      std::cout << -1 << std::endl;
      continue;
    }
    else if(k == 1) {
      std::cout << 1 << std::endl;
      continue;
    }

    std::cout << std::max(1, (dist-1)/(k-1) + ((dist-1)%(k-1) != 0)) << std::endl;
  }

  return 0;
}