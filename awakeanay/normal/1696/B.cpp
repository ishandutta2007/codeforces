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

    int nz = 0;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x) {
        if(l == -1)
          l = i;
        r = i;
        nz++;
      }
    }

    if(l == -1)
      std::cout << 0 << std::endl;
    else if(r-l+1 == nz)
      std::cout << 1 << std::endl;
    else
      std::cout << 2 << std::endl;
  }

  return 0;
}