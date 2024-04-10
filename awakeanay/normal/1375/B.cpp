#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int> > a(n, std::vector<int>(m, 4));
    for(int i = 0; i < n; i++)
      a[i][0] = a[i][m-1] = 3;
    for(int i = 0; i < m; i++)
      a[0][i] = a[n-1][i] = 3;
    a[0][0] = a[n-1][0] = a[0][m-1] = a[n-1][m-1] = 2;

    bool poss = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int x;
        std::cin >> x;
        if(x > a[i][j])
          poss = false;
      }
    }

    if(poss) {
      std::cout << "YES" << std::endl;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
          std::cout << a[i][j] << " ";
        std::cout << std::endl;
      }
    }
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}