#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }

  int b[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      b[i][j] = (j)%2;
    }
  }

  for(int i = 0; i+1 < n; i++) {
    for(int j = 0; j+1 < n; j++) {
      if(b[i+1][j])
        a[i+1][j] |= (1ll << (i+j));
      else
        a[i][j+1] |= (1ll << (i+j));
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      std::cout << a[i][j] << " ";
    std::cout << std::endl;
  }

  int q;
  std::cin >> q;

  while(q--) {
    int k;
    std::cin >> k;

    int x = 0, y = 0;
    std::cout << x+1 << " " << y+1 << std::endl;
    for(int i = 0; i < 2*n-2; i++) {
      if(x == n-1)
        y++;
      else if(y == n-1)
        x++;
      else {
        if(b[x+1][y]) {
          if((k >> i)&(1ll))
            x++;
          else
            y++;
        }
        else {
          if((k >> i)&(1ll))
            y++;
          else
            x++;
        }
      }
      std::cout << x+1 << " " << y+1 << std::endl;
    }
  }

  return 0;
}