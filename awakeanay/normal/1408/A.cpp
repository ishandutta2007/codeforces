#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = 0; i < n; i++)
      std::cin >> b[i];
    for(int i = 0; i < n; i++)
      std::cin >> c[i];

    int last = -1;
    int one = 0;
    for(int i = 0; i < n-1; i++) {
      if(a[i] != last) {
        std::cout << a[i] << " ";
        if(i == 0)
          one = a[i];
        last = a[i];
      }
      else if(b[i] != last) {
        std::cout << b[i] << " ";
        if(i == 0)
          one = b[i];
        last = b[i];
      }
    }

    if(last != a[n-1] && one != a[n-1])
      std::cout << a[n-1];
    else if(last != b[n-1] && one != b[n-1])
      std::cout << b[n-1];
    else
      std::cout << c[n-1];

    std::cout << std::endl;
  }

  return 0;
}