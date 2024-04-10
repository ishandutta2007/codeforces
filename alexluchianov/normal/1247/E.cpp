#include <iostream>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
ll const modulo = 1000000007;
char v[5 + nmax][5 + nmax];
int down[5 + nmax][5 + nmax], right[5 + nmax][5 + nmax];
ll dp[2][5 + nmax][5 + nmax];
ll sum[2][5 + nmax][5 + nmax];

int getsum(int p, int x, int y, int x2, int y2){
  if(x <= x2 && y <= y2)
    return (modulo * 3LL + sum[p][x][y] - sum[p][x2 + 1][y] - sum[p][x][y2 + 1] + sum[p][x2 + 1][y2 + 1]) % modulo;
  else
    return 0;
}

int main()
{
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      std::cin >> v[i][j];
  for(int i = n; 1 <= i; i--)
    for(int j = m; 1 <= j; j--) {
      down[i][j] = down[i + 1][j] + (v[i][j] == 'R');
      right[i][j] = right[i][j + 1] + (v[i][j] == 'R');
    }

  for(int i = n; 1 <= i; i--)
    for(int j = m; 1 <= j; j--){
      if(i == n && j == m)
        dp[0][i][j] = dp[1][i][j] = (v[i][j] == '.');
      else if(v[i][j] == '.'){
        dp[0][i][j] = dp[1][i][j] = (dp[0][i + 1][j] + dp[1][i][j + 1]) % modulo;
      } else {
        dp[0][i][j] = getsum(1, i, j + 1, n - down[i][j], j + 1);
        dp[1][i][j] = getsum(0, i + 1, j, i + 1, m - right[i][j]);
      }
      sum[0][i][j] = (modulo + dp[0][i][j] + sum[0][i + 1][j] + sum[0][i][j + 1] - sum[0][i + 1][j + 1]) % modulo;
      sum[1][i][j] = (modulo + dp[1][i][j] + sum[1][i + 1][j] + sum[1][i][j + 1] - sum[1][i + 1][j + 1]) % modulo;
    }
  std::cout << dp[0][1][1];
  return 0;
}