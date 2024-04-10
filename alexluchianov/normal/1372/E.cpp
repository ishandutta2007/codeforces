#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int const nmax = 100;
int pref[1 + nmax];
int sum[1 + nmax][1 + nmax];

int extract(int x, int x2, int y, int y2) {
  return sum[x2][y2] - sum[x - 1][y2] - sum[x2][y - 1] + sum[x - 1][y - 1];
}

int dp[1 + nmax][1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,int>> v;
  for(int i = 1; i <= n; i++) {
    int k;
    std::cin >> k;
    for(int j = 1;j <= k; j++) {
      int l, r;
      std::cin >> l >> r;
      sum[l][r]++;
    }
  }

  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= m; j++)
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  
  for(int h = 0; h < m; h++)
    for(int i = 1;i <= m - h; i++)
      for(int j = i; j <= i + h; j++) {
        int val = extract(i, j, j, i + h);
        dp[i][i + h] = std::max(dp[i][i + h], dp[i][j - 1] + val * val + dp[j + 1][i + h]);
      }

  std::cout << dp[1][m];
}