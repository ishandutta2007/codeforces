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
    int count = a[0] != 1;

    for(int i = 1; i < n; i++) {
      if(a[i] != i+1 && a[i-1] == i)
        count++;
    }

    std::cout << std::min(count, 2) << std::endl;
  }

  return 0;
}