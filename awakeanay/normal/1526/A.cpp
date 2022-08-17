#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[2*n];
    for(int i = 0; i < 2*n; i++)
      std::cin >> a[i];

    std::sort(a, a+2*n);

    int x = 0, b = n;
    for(int i = 0; i < 2*n; i++)
      std::cout << (i%2 ? a[x++] : a[b++]) << " ";
    std::cout << std::endl;
  }

  return 0;
}