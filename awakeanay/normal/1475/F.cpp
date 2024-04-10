#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n][n], b[n][n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        char c;
        std::cin >> c;
        a[i][j] = c-'0';
      }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        char c;
        std::cin >> c;
        b[i][j] = c-'0';
      }    

    for(int i = 0; i < n; i++) {
      if(a[i][0] == 1) {
        for(int j = 0; j < n; j++)
          a[i][j] ^= 1;
      }
    }

    for(int i = 0; i < n; i++) {
      if(a[0][i] == 1) {
        for(int j = 0; j < n; j++)
          a[j][i] ^= 1;
      }
    }

    for(int i = 0; i < n; i++) {
      if(b[i][0] == 1) {
        for(int j = 0; j < n; j++)
          b[i][j] ^= 1;
      }
    }

    for(int i = 0; i < n; i++) {
      if(b[0][i] == 1) {
        for(int j = 0; j < n; j++)
          b[j][i] ^= 1;
      }
    }

    bool poss = true;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        poss &= a[i][j] == b[i][j];

    if(poss)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}