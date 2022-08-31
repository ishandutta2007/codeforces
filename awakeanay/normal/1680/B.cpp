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

    int a[n][m];
    int x = n, y = m;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char c;
        std::cin >> c;
        a[i][j] = c == 'R';
        if(a[i][j]) {
          x = std::min(x, i);
          y = std::min(y, j);
        }
      }
    }

    bool poss = false;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(a[i][j])
          poss |= i <= x && j <= y;
      }
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}