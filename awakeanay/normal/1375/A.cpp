#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int x = 0, y = 0;
    for(int i = 1; i < n; i++) {
      if(a[i] >= a[i-1])
        x++;
      if(a[i] <= a[i-1])
        y++;
    }

    if(2*x >= n-1 && 2*y >= n-1) {
      for(int i = 0; i < n; i++)
        std::cout << a[i] << " ";
      std::cout << std::endl;
      continue;
    }

    for(int j = 0; j < n; j++) {
      a[j] *= -1;
      int x = 0, y = 0;
      for(int i = 1; i < n; i++) {
        if(a[i] >= a[i-1])
          x++;
        if(a[i] <= a[i-1])
          y++;
      }

      if(2*x >= n-1 && 2*y >= n-1) {
        for(int i = 0; i < n; i++)
          std::cout << a[i] << " ";
        std::cout << std::endl;
        break;
      }
    }
  }

  return 0;
}