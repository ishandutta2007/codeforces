#include <iostream>

using namespace std;

using ll = long long;

int const nmax = 400;
int const modulo = 1000000007;
int dp[5 + nmax][5 + nmax];

int main()
{
  int n;
  cin >> n;
  dp[1][0] = dp[1][1] = 1;

  for(int i = 2;i <= n; i++) {
    int lim = n - i + 2;
    for(int j = 0; j <= lim; j++)
      for(int h = 0; h <= lim - j; h++) {
        dp[i][j + h] += 1LL * dp[i - 1][j] * dp[i - 1][h] % modulo;
        if(modulo <= dp[i][j + h])
          dp[i][j + h] -= modulo;

        dp[i][j + h] += 1LL * dp[i - 1][j] * dp[i - 1][h] % modulo * (j + h) * 2 % modulo;
        if(modulo <= dp[i][j + h])
          dp[i][j + h] -= modulo;
        if(1 < j + h){
          dp[i][j + h - 1] += 1LL * dp[i - 1][j] * dp[i - 1][h] % modulo * (1LL * (j + h) * (j + h - 1)) % modulo;
          if(modulo <= dp[i][j + h - 1])
            dp[i][j + h - 1] -= modulo;
        }

        dp[i][j + h + 1] += 1LL * dp[i - 1][j] * dp[i - 1][h] % modulo;
        if(modulo <= dp[i][j + h + 1])
          dp[i][j + h + 1] -= modulo;
      }

  }
  cout << dp[n][1];
  return 0;
}