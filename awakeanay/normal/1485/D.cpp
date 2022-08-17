#include <iostream>

#define int long long

signed main() {
  int n, m;
  std::cin >> n >> m;

  int a[n][m];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> a[i][j];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if((i+j)%2)
        std::cout << 720720;
      else
        std::cout << 720720-a[i][j]*a[i][j]*a[i][j]*a[i][j];
      std::cout << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}