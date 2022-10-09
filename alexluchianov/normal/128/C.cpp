#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const modulo = 1000000007;
int dp[1 + nmax][1 + nmax];
int sum[1 + nmax][1 + nmax];

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  dp[1][1] = 1;
  sum[1][1] = 1;
  for(int i = 2;i <= nmax; i++) {
    dp[i][1] = 1;
    sum[i][1] = dp[i][1] + sum[i - 1][1];
    if(modulo <= sum[i][1])
      sum[i][1] -= modulo;

    for(int j = 2;j <= nmax; j++){
      dp[i][j] = dp[i - 1][j] + sum[i - 2][j - 1];
      if(modulo <= dp[i][j])
        dp[i][j] -= modulo;

      sum[i][j] = sum[i - 1][j] + dp[i][j];
      if(modulo <= sum[i][j])
        sum[i][j] -= modulo;
    }
  }
  cout << 1LL * dp[n][k + 1] * dp[m][k + 1] % modulo;
  return 0;
}