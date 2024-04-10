#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > type[2][3];
    char mat[n][n];

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        char c;
        std::cin >> c;
        mat[i][j] = c;
        if(c == 'X')
          type[0][(i+j)%3].push_back({i, j});
        else if(c == 'O')
          type[1][(i+j)%3].push_back({i, j});
      }
    }

    int min = 0;
    int val = type[0][0].size() + type[1][1].size();
    for(int i = 1; i < 3; i++) {
      int nval = type[0][i].size() + type[1][(i+1)%3].size();
      if(nval < val) {
        val = nval;
        min = i;
      }
    }

    for(std::pair<int, int> j : type[0][min])
      mat[j.first][j.second] = 'O';
    for(std::pair<int, int> j : type[1][(min+1)%3])
      mat[j.first][j.second] = 'X';

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        std::cout << mat[i][j];
      std::cout << std::endl;
    }

  }

  return 0;
}