#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream in ("input.in");

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;
int const modulo = 1000000007;
int v[1 + nmax];
int pref[1 + nmax];

ll divideetimpera(int from, int to){
  int mid = (from + to) / 2;
  ll result = 0;
  //*
  if(from + 1 < to){
    result += divideetimpera(from, mid);
    result += divideetimpera(mid + 1, to);
    result %= modulo;
  }
  //*/



  int lim = pref[to] - pref[from - 1];

  vector<vector<int>> dp;
  vector<int> sum;
  dp.resize(to - from + 5);
  for(int i = 0; i <= to - mid; i++)
    dp[i].resize(2 * lim + 5);
  sum.resize(2 * lim + 5);


  dp[0][lim] = 1;

  for(int i = mid + 1;i <= to; i++) {
    for(int j = 0; j <= 2 * lim; j++) {
      if(0 <= j - v[i])
        dp[i - mid][j] += dp[i - 1 - mid][j - v[i]];
      if(modulo <= dp[i - mid][j])
        dp[i - mid][j] -= modulo;

      if(j + v[i] <= 2 * lim)
        dp[i - mid][j] += dp[i - 1 - mid][j + v[i]];
      if(modulo <= dp[i - mid][j])
        dp[i - mid][j] -= modulo;

      sum[j] += dp[i - mid][j];
      if(modulo <= sum[j])
        sum[j] -= modulo;
    }
  }

  vector<vector<int>> dp2;
  vector<int> sum2;
  dp2.resize(to - from + 5);
  for(int i = 0; i <= mid + 1 - from; i++)
    dp2[i].resize(2 * lim + 5);
  sum2.resize(2 * lim + 5);


  dp2[mid + 1 - from][lim] = 1;

  for(int i = mid; from <= i; i--) {
    for(int j = 0; j <= 2 * lim; j++) {
      if(0 <= j - v[i])
        dp2[i - from][j] += dp2[i + 1 - from][j - v[i]];
      if(modulo <= dp2[i - from][j])
        dp2[i - from][j] -= modulo;

      if(j + v[i] <= 2 * lim)
        dp2[i - from][j] += dp2[i + 1 - from][j + v[i]];
      if(modulo <= dp2[i - from][j])
        dp2[i - from][j] -= modulo;

      sum2[j] += dp2[i - from][j];
      if(modulo <= sum2[j])
        sum2[j] -= modulo;
    }
  }

  for(int i = 0;i <= 2 * lim; i++) {
    result += 1LL * sum[i] * sum2[2 * lim - i] % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  dp.clear();
  sum.clear();
  dp2.clear();
  sum2.clear();

  return result % modulo;
}
//
int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    //v[i] = 10;
    cin >> v[i];
  }

  for(int i = 1;i <= n; i++)
    pref[i] = pref[i - 1] + v[i];
  cout << divideetimpera(1, n) << '\n';
  return 0;
}