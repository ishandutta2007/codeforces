#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int> > a(n, std::vector<int>(m, 0)), b;
    b = a;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char c;
        std::cin >> c;
        if(c == '*')
          a[i][j] = 1;
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(int d = k; d <= n; d++) {
          if(i-d >= 0 && j-d >= 0 && j+d < m) {
            int paint = 0;
            for(int l = 0; l <= d; l++) {
              paint += a[i-l][j-l];
              paint += a[i-l][j+l];
            }

            if(paint == 2*d + 2) {
              for(int l = 0; l <= d; l++) {
                b[i-l][j-l] = b[i-l][j+l] = 1;
              }
            }
          }
        }
      }
    }

    std::cout << (a == b ? "YES" : "NO") << std::endl;
  }

  return 0;
}