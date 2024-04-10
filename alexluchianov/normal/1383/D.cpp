#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

using ll = long long;

int const nmax = 250;
int v[5 + nmax][5 + nmax];
int sol[5 + nmax][5 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      std::cin >> v[i][j];
  
  std::set<int> setlin, setcol;

  for(int i = 1;i <= n; i++) {
    int smax = 0;
    for(int j = 1;j <= m; j++)
      smax = std::max(smax, v[i][j]);
    setlin.insert(smax);
  }
  for(int i = 1;i <= m; i++) {
    int smax = 0;
    for(int j = 1;j <= n; j++)
      smax = std::max(smax, v[j][i]);
    setcol.insert(smax);
  }
  int x = 0, y = 0;
  std::vector<std::pair<int,int>> empty;
  int ptr =0;
  for(int i = n * m; 1 <= i; i--) {
    if(setlin.find(i) != setlin.end() && setcol.find(i) != setcol.end()) {
      x++;
      y++;
      sol[x][y] = i;
      for(int j = y - 1;1 <= j; j--)
        empty.push_back({x, j});
      for(int j = x - 1;1 <= j; j--)
        empty.push_back({j, y});
    } else if(setlin.find(i) != setlin.end()) {
      x++;
      sol[x][y] = i;
      for(int j = y - 1;1 <= j; j--)
        empty.push_back({x, j});
    } else if(setcol.find(i) != setcol.end()){
      y++;
      sol[x][y] = i;
      for(int j = x - 1;1 <= j; j--)
        empty.push_back({j, y});
    } else {
      assert(ptr < empty.size());
      sol[empty[ptr].first][empty[ptr].second] = i;
      ptr++;
    }
  }

  
  for(int i = 1; i <= n; i++) {
    for(int j = 1;j <= m; j++)
      std::cout << sol[i][j] << " ";
    std::cout << '\n';
  }

  return 0;
}