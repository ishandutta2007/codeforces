#include <iostream>
#include <queue>
#include <vector>

#define int long long

int dx[] = {0, 0, 1, -1};//, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0};//, -1, 1, 1, -1};

signed main() {
  int n, m, q, p;
  std::cin >> n >> m;

  std::cin >> q >> p;

  std::vector<std::pair<int, int> > retm;
  int vis[n][m];
  int lim[n][m];

  char a[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      vis[i][j] = false;
    }
  }

  std::vector<std::vector<int> > noise(n, std::vector<int>(m, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] == '.' || a[i][j] == '*')
        continue;

      int charge = a[i][j] - 'A' + 1;
      charge *= q;
      std::queue<std::pair<int, int> > bfsq;

      bfsq.push({i, j});
      lim[i][j] = charge;
      vis[i][j] = true;
      retm.push_back({i, j});

      while(!bfsq.empty()) {
        std::pair<int, int> u = bfsq.front(); bfsq.pop();
        int x = u.first; int y = u.second;
        noise[x][y] += lim[x][y];

        if(lim[x][y] == 0)
          continue;

        for(int j = 0; j < 4; j++) {
          std::pair<int, int> v = {x+dx[j], y+dy[j]};

          if(v.first < 0 || v.second < 0 || v.first >= n || v.second >= m || a[v.first][v.second] == '*' || vis[v.first][v.second])
            continue;

          vis[v.first][v.second] = true;
          lim[v.first][v.second] = lim[x][y]/2;
          retm.push_back({v.first, v.second});
          bfsq.push(v);
        }
      }

      for(std::pair<int, int> b : retm) {
        vis[b.first][b.second] = lim[b.first][b.second] = 0;
      }

      retm.clear();
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans += noise[i][j] > p;
      //std::cout << noise[i][j] << " ";
    }
    //std::cout << std::endl;
  }

  std::cout << ans << std::endl;

  return 0;
}