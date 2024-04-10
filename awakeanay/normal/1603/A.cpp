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

    int a[n];

    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int poss = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 2; j <= i+2; j++) {
        if(a[i] % j != 0) {
          poss++;
          break;
        }
      }
    }

    std::cout << (poss == n ? "YES" : "NO") << std::endl;
  }

  return 0;
}