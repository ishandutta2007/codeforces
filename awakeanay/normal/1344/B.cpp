#include <iostream>
#include <queue>
#include <vector>
 
signed main() {
  int n, m;
  std::cin >> n >> m;
 
  bool poss = true;
  char a[n][m];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> a[i][j];
 
  bool row = false, col = false;
  for(int i = 0; i < n; i++) {
    int min = 10001;
    int max = -1;
    int c = 0;
 
    for(int j = 0; j < m; j++) {
      if(a[i][j] == '#') {
        max = std::max(j, max);
        min = std::min(j, min);
        c++;
      }
    }
 
    if(max != -1 && max-min+1 != c)
      poss = false;
 
    if(max == -1)
      row = true;
  }
 
  for(int i = 0; i < m; i++) {
    int min = 10001;
    int max = -1;
    int c = 0;
 
    for(int j = 0; j < n; j++) {
      if(a[j][i] == '#') {
        max = std::max(j, max);
        min = std::min(j, min);
        c++;
      }
    }
 
    if(max != -1 && max-min+1 != c)
      poss = false;
 
    if(max == -1)
      col = true;
  }
 
  if(row^col) poss = false;
  if(!poss) {
    std::cout << -1 << std::endl;
    return 0;
  }
 
  int ans = 0;
  std::vector<std::vector<int> > mark(n, std::vector<int>(m, false));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] == '#') {
        if(!mark[i][j]) {
          ans++;
          
          std::queue<std::pair<int, int> > q;
          q.push({i, j});
 
          while(!q.empty()) {
            std::pair<int, int> x = q.front(); q.pop();
            if(x.second < m-1 && a[x.first][x.second+1] == '#' && mark[x.first][x.second+1] == false) { mark[x.first][x.second+1] = true; q.push({x.first, x.second+1}); }
            if(x.second > 0 && a[x.first][x.second-1] == '#' && mark[x.first][x.second-1] == false) { mark[x.first][x.second-1] = true; q.push({x.first, x.second-1}); }
            if(x.first < n-1 && a[x.first+1][x.second] == '#' && mark[x.first+1][x.second] == false) { mark[x.first+1][x.second] = true; q.push({x.first+1, x.second}); }
            if(x.first > 0 && a[x.first-1][x.second] == '#' && mark[x.first-1][x.second] == false) { mark[x.first-1][x.second] = true; q.push({x.first-1, x.second}); }
          }
        }
      }
    }
  }
 
  std::cout << ans << std::endl;
}