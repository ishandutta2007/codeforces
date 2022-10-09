#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 30;

ll dp[1 + sigma][1 + sigma];
ll funct(int lim, int bit){
  lim = min(1LL * lim, (1LL << (bit + 1)) - 1);
  return max(0LL, lim - ((1LL << bit) - 1));
}

int solve(){
  ll lim, modulo;
  cin >> lim >> modulo;
  for(int i = 0; i <= sigma; i++)
    for(int j = 0; j <= sigma; j++)
      dp[i][j] = 0;

  for(int j = 0; j <= sigma; j++) {
    if(0 < j)
      dp[1][j] = (dp[1][j - 1] + funct(lim, j)) % modulo;
    else
      dp[1][j] = 1;
  }

  for(int i = 2;i <= sigma; i++){
    for(int j = 1; j <= sigma; j++) {
      dp[i][j] = (dp[i][j - 1] + 1LL * dp[i - 1][j - 1] * funct(lim, j)) % modulo;
    }
  }

  int result = 0;
  for(int i = 1; i <= sigma; i++) {
    result += dp[i][sigma - 1];
    if(modulo <= result)
      result -= modulo;
  }
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    cout << solve() << '\n';
  return 0;
}
/*
1
1000000000
1000000000
*/