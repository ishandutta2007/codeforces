#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n+2];
    a[0] = 0;
    a[n+1] = 1;

    for(int i = 1; i <= n; i++)
      std::cin >> a[i];

    for(int i = 0; i <= n; i++) {
      if(a[i] == 0 && a[i+1] == 1) {
        for(int j = 1; j <= i; j++)
          std::cout << j << " ";
        std::cout << n+1 << " ";
        for(int k = i+1; k <= n; k++)
          std::cout << k << " ";
        std::cout << std::endl;
        break;
      }
    }
  }

  return 0;
}