#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300;
int const iplus[4] = {0, 0, 1, -1};
int const jplus[4] = {1, -1, 0, 0};
int v[1 + nmax][1 + nmax];
int n,m;

bool valid(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}

void solve() {
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      std::cin >> v[i][j];
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(0 < v[i][j]) {
        int vec = 0;
        for(int h = 0; h < 4; h++) {
          int newx = i + iplus[h];
          int newy = j + jplus[h];
          if(valid(newx, newy) && 0 < v[newx][newy])
            vec++;
        }
        for(int h = 0; h < 4; h++) {
          int newx = i + iplus[h];
          int newy = j + jplus[h];
          if(valid(newx, newy) && 0 == v[newx][newy] && vec < v[i][j]) {
            v[newx][newy] = 1;
            vec++;
          }
        }
        if(vec < v[i][j]) {
          std::cout << "NO\n";
          return ;
        }
      }
  for(int i = 1;i <= n; i++) 
    for(int j = 1;j <= m; j++)
      if(0 < v[i][j]) {
        v[i][j] = 0;
        for(int h = 0; h < 4; h++) {
          int newx = i + iplus[h];
          int newy = j + jplus[h];
          if(valid(newx, newy) && 0 < v[newx][newy])
            v[i][j]++;
        }
      }
  std::cout << "YES\n";
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= m; j++)
      std::cout << v[i][j] << " ";
    std::cout << '\n';
  }
  return ;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}