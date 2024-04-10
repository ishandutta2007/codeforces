#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a[8][8];
    for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 8; j++) {
        char c = '7';
        while(c != '#' && c != '.')
          std::cin >> c;
        a[i][j] = c == '#';
      }
    }

    for(int i = 1; i+1 < 8; i++) {
      for(int j = 1; j+1 < 8; j++) {
        if(a[i+1][j-1] && a[i+1][j+1] && a[i-1][j-1] && a[i-1][j+1] && a[i][j])
          std::cout << i+1 << " " << j+1 << std::endl;
      }
    }
  }

  return 0;
}