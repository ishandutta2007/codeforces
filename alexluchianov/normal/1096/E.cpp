#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int const nmax = 100;
int const valmax = 5000;
int const modulo = 998244353;

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

int dp[5 + nmax][5 + valmax][2];
int sum[5 + nmax][5 + valmax][2];

int extract(int x, int y, int d) {
  if(0 <= x && 0 <= y && 0 <= y)
    return sum[x][y][d];
  else
    return 0;
}
int dp2[5 + nmax][5 + valmax];
int sum2[5 + nmax][5 + valmax];

int main() {
  int n, r, m;
  std::cin >> n >> m >> r;
  dp[0][0][0] = 1;
  for(int i = 0; i <= m; i++)
    sum[0][i][0] = 1;
  for(int i = 1;i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      for(int h = 0; h < 2; h++) {
        dp[i][j][h] = (dp[i][j][h] + (1LL * modulo + extract(i - 1, j, h) - extract(i - 1, j - r, h))) % modulo;
        dp[i][j][h | 1] = (dp[i][j][h | 1] + (extract(i - 1, j - r, h))) % modulo;

        if(0 < j)
          sum[i][j][h] = (sum[i][j - 1][h]);
        sum[i][j][h] = (sum[i][j][h] + dp[i][j][h]);
        if(modulo <= sum[i][j][h])
          sum[i][j][h] -= modulo;
      }
    }
  }
  
  for(int i = r; i <= m; i++) {
    dp2[1][i] = 1;
    sum2[1][i] = i - r + 1;
  }

  for(int i = 2;i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      dp2[i][j] = (dp2[i][j] + sum2[i - 1][j]) % modulo;
      if(0 < j)
        sum2[i][j] = (sum2[i][j - 1]);
      sum2[i][j] = (sum2[i][j] + dp2[i][j]);
      if(modulo <= sum2[i][j])
        sum2[i][j] -= modulo;
    }
  }
  std::cout << 1LL * dp[n][m][1] * inverse(1LL * dp2[n][m] * n % modulo) % modulo << '\n';
  return 0;
}