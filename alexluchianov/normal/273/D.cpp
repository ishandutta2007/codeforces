#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 150;
int const modulo = 1000000007;

ll dp[1 + nmax][1 + nmax][1 + nmax][2][2];
ll sum[1 + nmax][1 + nmax][1 + nmax][2][2];

void refresh_sum(int id, int color, int color2) {
  for(int i = 1;i <= nmax; i++)
    for(int j = 1;j <= nmax; j++)
      sum[id][i][j][color][color2] = (1LL * modulo + dp[id][i][j][color][color2] + sum[id][i - 1][j][color][color2] + 
                             sum[id][i][j - 1][color][color2] - sum[id][i - 1][j - 1][color][color2]);
}

ll extract(int id, int color, int color2,  int x, int x2, int y, int y2) {
  if(x <= x2 && y <= y2) {
    ll result = (modulo * 2LL + sum[id][x2][y2][color][color2] - sum[id][x - 1][y2][color][color2]
                             - sum[id][x2][y - 1][color][color2] + sum[id][x - 1][y - 1][color][color2]) % modulo;
    return result;
  } else
    return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++)
    for(int j = i; j <= m; j++)
      dp[1][i][j][0][0] = 1;
  refresh_sum(1, 0, 0);
  for(int id = 2; id <= n; id++) {
    for(int i = 1;i <= m; i++)
      for(int j = i; j <= m; j++) {
        dp[id][i][j][0][0] = extract(id - 1, 0, 0, i, j, i, j);
        dp[id][i][j][1][0] = (extract(id - 1, 0, 0, 1, i - 1, i, j) + extract(id - 1, 1, 0, 1, i, i, j)) % modulo;
        dp[id][i][j][0][1] = (extract(id - 1, 0, 0, i, j, j + 1, m) + extract(id - 1, 0, 1, i, j, j, m)) % modulo;
        dp[id][i][j][1][1] = (extract(id - 1, 0, 0, 1, i - 1, j + 1, m) + extract(id - 1, 1, 0, 1, i, j + 1, m) +
                              extract(id - 1, 0, 1, 1, i - 1, j, m) + extract(id - 1, 1, 1, 1, i, j, m)) % modulo;
      }
    refresh_sum(id, 0, 0);
    refresh_sum(id, 0, 1);
    refresh_sum(id, 1, 0);
    refresh_sum(id, 1, 1);
  }
  int result = 0;
  for(int id = 1;id <= n; id++) {
    result += (extract(id, 0, 0, 1, m, 1, m) + extract(id, 1, 0, 1, m, 1, m) +
              extract(id, 0, 1, 1, m, 1, m) + extract(id, 1, 1, 1, m, 1, m)) * (n - id + 1) % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  std::cout << result;
}