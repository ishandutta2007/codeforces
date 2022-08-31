#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    bool poss = true;
    int type = -1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char c;
        std::cin >> c;
        if(c == '.')
          continue;
        int ctype = (i+j)%2;
        if(c == 'R')
          ctype ^= 1;
        if(type == (!ctype))
          poss = false;
        else
          type = ctype;
      }
    }

    if(poss) {
      if(type == -1)
        type = 0;
      std::cout << "YES" << std::endl;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
          std::cout << ((((i+j)%2)^type) ? 'R' : 'W');
        std::cout << std::endl;
      }

    }
    else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}