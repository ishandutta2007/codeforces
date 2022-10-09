#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
int const iplus[4] = {0, 0, 1, -1};
int const jplus[4] = {1, -1, 0, 0};
int n, m;

bool valid(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}
char v[1 + nmax][1 + nmax];
int seen[1 + nmax][1 + nmax];

void dfs(int x, int y) {
  seen[x][y] = 1;
  for(int h = 0; h < 4;h++) {
    int newx = x + iplus[h];
    int newy = y + jplus[h];
    if(valid(newx, newy) == 1 && v[newx][newy] == '#' && seen[newx][newy] == 0)
      dfs(newx, newy);
  }
}

int solve(int n, int m) {
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      seen[i][j] = 0;
  int result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(seen[i][j] == 0 && v[i][j] == '#') {
        result++;
        dfs(i, j);
      }
  return result;
}
int main() {
  std::cin >> n >> m;
  int land = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
      std::cin >> v[i][j];
      land += (v[i][j] == '#');
    }
  int result = 2;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(v[i][j] == '#') {
        v[i][j] = '.';
        if(1 < solve(n, m))
          result = 1;
        v[i][j] = '#';
      }

  if(result < land) {
    std::cout << result;
    return 0;
  } else
    std::cout << -1;
  return 0;
}