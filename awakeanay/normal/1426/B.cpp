#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    bool sym = false;
    for(int i = 0; i < n; i++) {
      int a[2][2];
      int cur = true;
      for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++)
          std::cin >> a[j][k];
      for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++)
          if(a[j][k] != a[k][j])
            cur = false;
      if(cur)
        sym = true;
    }

    if(m%2 || !sym) {
      std::cout << "NO" << std::endl;
    }
    else {
      std::cout << "YES" << std::endl;
    }
  }

  return 0;
}