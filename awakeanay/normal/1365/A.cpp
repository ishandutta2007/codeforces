#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int mat[n][m];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        std::cin >> mat[i][j];

    int row = 0, col = 0;
    for(int i = 0; i < n; i++) {
      bool poss = true;
      for(int j = 0; j < m; j++)
        if(mat[i][j])
          poss = false;
      row += poss;
    }

    for(int j = 0; j < m; j++) {
      bool poss = true;
      for(int i = 0; i < n; i++)
        if(mat[i][j])
          poss = false;
      col += poss;
    }

    if(std::min(row, col)%2)
      std::cout << "Ashish";
    else
      std::cout << "Vivek";

    std::cout << std::endl;
  }
  
  return 0;
}