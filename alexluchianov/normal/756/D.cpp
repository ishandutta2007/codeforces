#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int const nmax = 5000;
int const sigma = 26;
int const modulo = 1000000007;
int v[5 + nmax], frec[5 + nmax];
int dp[5 + nmax], sum[5 + nmax];
int dp2[5 + nmax], sum2[5 + nmax];

int getsum(int x, int y){
  if(x == 0)
    return sum[y];
  else
    return (modulo + sum[y] - sum[x - 1]) % modulo;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  dp[0] = sum[0] = 1;
  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + dp[i];

  for(int i = 1;i <= n; i++) {
    char val;
    cin >> val;
    v[i] = val - 'a' + 1;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1;j <= sigma; j++)
      frec[j] = -1;
    for(int j = 1;j <= n; j++) {
      dp2[j] = getsum(frec[v[j]] + 1, j);
      sum2[j] = (sum2[j - 1] + dp2[j]) % modulo;
      frec[v[j]] = j;
    }
    for(int j = 0;j <= n; j++){
      dp[j] = dp2[j];
      sum[j] = sum2[j];
    }
  }
  cout << sum[n];
  return 0;
}