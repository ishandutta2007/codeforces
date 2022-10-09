#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
char v[1 + nmax][1 + nmax];
int sum[1 + nmax][1 + nmax], sum2[1 + nmax][1 + nmax];

int extract(int x, int y, int x2, int y2) {
  return sum[x2][y2] - sum[x - 1][y2] - sum[x2][y - 1] + sum[x - 1][y - 1];
}
int extract2(int x, int y, int x2, int y2) {
  return sum2[x2][y2] - sum2[x - 1][y2] - sum2[x2][y - 1] + sum2[x - 1][y - 1];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      std::cin >> v[i][j];
  for(int i = 2; i <= n; i++)
    for(int j = 1;j <= m; j++) 
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (v[i][j] == '.' && v[i - 1][j] == '.');
  for(int i = 1;i <= n; i++)
    for(int j = 2; j <= m; j++)
      sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + (v[i][j] == '.' && v[i][j - 1] == '.');
  int q;
  std::cin >> q;
  for(int i = 1; i <= q; i++) {
    int x, y, x2, y2;
    std::cin >> x >> y >> x2 >> y2;
    std::cout << extract(x + 1, y, x2, y2) + extract2(x, y + 1, x2, y2) << '\n';
  }
  return 0;
}