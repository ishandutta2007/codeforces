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

    bool poss = true;
    for(int i = 0; i < n; i++)
      if(a[i] != a[0])
        poss = false;

    if(poss)
      std::cout << n << std::endl;
    else
      std::cout << 1 << std::endl;
  }
  return 0;
}