#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
int const modulo = 998244353;

int dp[5 + nmax][5 + nmax];
int sum[5 + nmax][5 + nmax];
int sum3[5 + nmax][5 + nmax];

void precompute(int n){
  dp[0][0] = 2;
  for(int i = 0 ; i <= n ; i++)
    sum[0][i] = 2;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= i ; j++){
      dp[i][j] = sum[i - j][j];
      dp[i][j] += sum3[i - 1][j] - sum3[i - j][j];
      dp[i][j] %= modulo;
      if(dp[i][j] < 0)
        dp[i][j] += modulo;

    }

    for(int j = 1 ; j <= n ; j++) {
      sum[i][j] = sum[i][j - 1] + dp[i][j];
      if(modulo <= sum[i][j])
        sum[i][j] -= modulo;
    }
    for(int j = 1 ; j <= n ; j++){
      sum3[i][j] = sum3[i - 1][j] + dp[i][j];
      if(modulo <= sum3[i][j])
        sum3[i][j] -= modulo;
    }
  }

}

int result = 0;
int dp2[5 + nmax];
int sum2[5 + nmax];

void adddp2(int n , int l , int repeat){
  dp2[0] = dp[n][l];
  sum2[0] = dp[n][l];
  //cout << dp[n][l] << " " << n << " " << l << '\n';

  for(int i = 1 ; i <= n ; i++){
    dp2[i] = sum2[i - 1];
    if(repeat <= i - 1){
      dp2[i] -= sum2[i - repeat - 1];
      if(dp2[i] < 0)
        dp2[i] += modulo;
    }
    sum2[i] = sum2[i - 1] + dp2[i];
    if(modulo <= sum2[i])
      sum2[i] -= modulo;
  }
  result += dp2[n];
  //cout << l << " " << repeat << " " << dp2[n] << '\n';

  if(modulo <= result)
    result -= modulo;
}
int main()
{
  int n , k;
  cin >> n >> k;
  k--;
  precompute(n);
  for(int i = 1 ; i <= n ; i++){
    adddp2(n , i , k / i);
  }
  cout << result % modulo;
  return 0;
}