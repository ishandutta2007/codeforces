#include <iostream>

using namespace std;

int const nmax = 1000;
int const modulo = 998244353;

int dp[5 + nmax][5 + nmax * 2][2][2];

int main()
{
  int n ,k;
  cin >> n >> k;
  k++;
  dp[1][2][0][0] = 1;
  dp[1][3][0][1] = 1;
  dp[1][2][1][1] = 1;
  dp[1][3][1][0] = 1;

  for(int i = 2 ; i <= n ; i++){
    for(int j = 2 ; j <= k ; j++){
      dp[i][j][0][0] += dp[i - 1][j][0][0];
      if(modulo <= dp[i][j][0][0])
        dp[i][j][0][0] -= modulo;

      dp[i][j][0][0] += dp[i - 1][j][0][1];
      if(modulo <= dp[i][j][0][0])
        dp[i][j][0][0] -= modulo;

      dp[i][j][0][0] += dp[i - 1][j][1][0];
      if(modulo <= dp[i][j][0][0])
        dp[i][j][0][0] -= modulo;

      dp[i][j][0][0] += dp[i - 1][j - 1][1][1];
      if(modulo <= dp[i][j][0][0])
        dp[i][j][0][0] -= modulo;

      /////////////////////////////////////////////////////////////////
      dp[i][j][0][1] += dp[i - 1][j - 1][0][0];
      if(modulo <= dp[i][j][0][1])
        dp[i][j][0][1] -= modulo;

      dp[i][j][0][1] += dp[i - 1][j][0][1];
      if(modulo <= dp[i][j][0][1])
        dp[i][j][0][1] -= modulo;

      dp[i][j][0][1] += dp[i - 1][j - 2][1][0];
      if(modulo <= dp[i][j][0][1])
        dp[i][j][0][1] -= modulo;

      dp[i][j][0][1] += dp[i - 1][j - 1][1][1];
      if(modulo <= dp[i][j][0][1])
        dp[i][j][0][1] -= modulo;
      ////////////////////////////////////////////////////////////////

      dp[i][j][1][0] += dp[i - 1][j - 1][0][0];
      if(modulo <= dp[i][j][1][0])
        dp[i][j][1][0] -= modulo;

      dp[i][j][1][0] += dp[i - 1][j - 2][0][1];
      if(modulo <= dp[i][j][1][0])
        dp[i][j][1][0] -= modulo;

      dp[i][j][1][0] += dp[i - 1][j][1][0];
      if(modulo <= dp[i][j][1][0])
        dp[i][j][1][0] -= modulo;

      dp[i][j][1][0] += dp[i - 1][j - 1][1][1];
      if(modulo <= dp[i][j][1][0])
        dp[i][j][1][0] -= modulo;
      ////////////////////////////////////////////////

      dp[i][j][1][1] += dp[i - 1][j - 1][0][0];
      if(modulo <= dp[i][j][1][1])
        dp[i][j][1][1] -= modulo;

      dp[i][j][1][1] += dp[i - 1][j][0][1];
      if(modulo <= dp[i][j][1][1])
        dp[i][j][1][1] -= modulo;

      dp[i][j][1][1] += dp[i - 1][j][1][0];
      if(modulo <= dp[i][j][1][1])
        dp[i][j][1][1] -= modulo;

      dp[i][j][1][1] += dp[i - 1][j][1][1];
      if(modulo <= dp[i][j][1][1])
        dp[i][j][1][1] -= modulo;
    }
  }
  cout << (0LL + dp[n][k][0][0] + dp[n][k][0][1] + dp[n][k][1][0] + dp[n][k][1][1]) % modulo;
  return 0;
}