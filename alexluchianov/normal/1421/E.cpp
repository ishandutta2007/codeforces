#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
ll const inf = 1000000000000000000;
int v[1 + nmax];
ll dp[1 + nmax][3][2][2];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  if(n == 1) {
    std::cout << v[1] << '\n';
    return 0;
  }
  for(int i = 1;i <= n; i++)
    for(int j = 0; j < 3; j++)
      for(int h1 = 0; h1 < 2; h1++)
        for(int h2 = 0; h2 < 2; h2++)
          dp[i][j][h1][h2] = -inf;
  dp[1][1][0][0] = v[1];
  dp[1][2][0][1] = -v[1];
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 3; j++)
      for(int h1 = 0; h1 < 2; h1++)
        for(int h2 = 0; h2 < 2; h2++) {
          dp[i + 1][(j + 1) % 3][h1 | (h2 == 0)][0] = std::max(dp[i + 1][(j + 1) % 3][h1 | (h2 == 0)][0], dp[i][j][h1][h2] + v[i + 1]);
          dp[i + 1][(j + 2) % 3][h1 | (h2 == 1)][1] = std::max(dp[i + 1][(j + 2) % 3][h1 | (h2 == 1)][1], dp[i][j][h1][h2] - v[i + 1]);
        }
  }
  std::cout << std::max(dp[n][1][1][0], dp[n][1][1][1]) << '\n';

  return 0;
}