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

    for(int i = 0; i < n; i++) {
      int k = i/2;
      if(i%2 == 0)
        std::cout << a[k];
      else
        std::cout << a[n-1-k];
      std::cout << " ";
    }

    std::cout << std::endl;
  }
  
  return 0;
}