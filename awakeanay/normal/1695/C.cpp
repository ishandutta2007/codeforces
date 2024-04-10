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
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        std::cin >> a[i][j];

    int min[n][m];
    int max[n][m];

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        min[i][j] = a[i][j];
        if(i && j) {
          min[i][j] += std::min(min[i-1][j], min[i][j-1]);
        }
        else if(i) {
          min[i][j] += min[i-1][j];
        }
        else if(j) {
          min[i][j] += min[i][j-1];
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        max[i][j] = a[i][j];
        if(i && j) {
          max[i][j] += std::max(max[i-1][j], max[i][j-1]);
        }
        else if(i) {
          max[i][j] += max[i-1][j];
        }
        else if(j) {
          max[i][j] += max[i][j-1];
        }
      }
    }

    if((n+m-1)&1) {
      std::cout << "NO" << std::endl;
    }
    else {
      if(min[n-1][m-1] <= 0 && max[n-1][m-1] >= 0)
        std::cout << "YES" << std::endl;
      else
        std::cout << "NO" << std::endl;
    }
  }

  return 0;
}