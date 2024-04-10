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

    int c[2*n][2*n];
    int cur = 0;
    for(int i = 0; i < 2*n; i++)
      for(int j = 0; j < 2*n; j++)
        std::cin >> c[i][j];
    for(int i = n; i < 2*n; i++) {
      for(int j = n; j < 2*n; j++) {
        cur += c[i][j];
        c[i][j] = 0;
      }
    }

    int min = c[0][2*n-1];
    min = std::min(min, c[0][n]);
    min = std::min(min, c[n-1][n]);
    min = std::min(min, c[n-1][2*n-1]);

    min = std::min(min, c[n][0]);
    min = std::min(min, c[n][n-1]);
    min = std::min(min, c[2*n-1][0]);
    min = std::min(min, c[2*n-1][n-1]);

    std::cout << cur+min << std::endl;
  }

  return 0;
}