#include <iostream>
#include <queue>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int good = 0;
    std::vector<std::vector<char> > mat(n, std::vector<char>(m, '.')), nmat(n, std::vector<char>(m, '.'));

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        std::cin >> mat[i][j];
        if(mat[i][j] == 'G')
          good++;
      }
    }

    nmat = mat;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i > 0 && mat[i-1][j] == 'B')
          nmat[i][j] = '#';
        if(j > 0 && mat[i][j-1] == 'B')
          nmat[i][j] = '#';
        if(i < n-1 && mat[i+1][j] == 'B')
          nmat[i][j] = '#';
        if(j < m-1 && mat[i][j+1] == 'B')
          nmat[i][j] = '#';
      }
    }

    std::vector<std::vector<int> > vis(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int> > bfs;

    if(nmat[n-1][m-1] != '#' && nmat[n-1][m-1] != 'B') {
      bfs.push({n-1, m-1});
      vis[n-1][m-1] = true;
      if(nmat[n-1][m-1] == 'G')
        good--;
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    while(!bfs.empty()) {
      std::pair<int, int> next = bfs.front();
      bfs.pop();

      for(int j = 0; j < 4; j++) {
        int x = next.first+dx[j];
        int y = next.second+dy[j];

        if(x < 0 || x >= n)
          continue;

        if(y < 0 || y >= m)
          continue;

        if(vis[x][y])
          continue;

        if(nmat[x][y] == '#' || nmat[x][y] == 'B')
          continue;

        if(nmat[x][y] == 'G')
          good--;

        vis[x][y] = true;
        bfs.push({x, y});
      }
    }
    
    if(good > 0)
      std::cout << "No";
    else
      std::cout << "Yes";

    std::cout << std::endl;
  }

  return 0;
}