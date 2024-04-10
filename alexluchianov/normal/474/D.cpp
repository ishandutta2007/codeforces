#include <iostream>

using namespace std;

int const nmax = 100000;
int const modulo = 1000000007;
int dp[5 + nmax][2];
int sum[5 + nmax];

int main()
{
  dp[0][0] = 1;
  int n , k;
  cin >> n >> k;
  for(int i = 1 ; i <= nmax ; i++){
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % modulo;
    if(k <= i)
      dp[i][1] = (dp[i - k][0] + dp[i - k][1]) % modulo;
    //cout << dp[i][0] << " " << dp[i][1] << '\n';

    sum[i] = ((sum[i - 1] + dp[i][0]) % modulo + dp[i][1]) % modulo;
  }
  for(int i = 1 ; i <= n ; i++){
    int a , b;
    cin >> a >> b;
    cout << (sum[b] - sum[a - 1] + modulo ) % modulo << '\n';
  }
  return 0;
}