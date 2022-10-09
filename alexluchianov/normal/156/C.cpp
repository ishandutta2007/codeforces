#include <iostream>

using namespace std;

#define ll long long

int const sigma = 26;
int const nmax = 100;
int const modulo = 1000000007;
int dp[5 + nmax][5 + nmax * sigma];
int sum[5 + nmax][5 + nmax * sigma];

void computedp(){
  dp[0][0] = 1;
  for(int j = 0 ; j <= nmax * sigma ; j++)
    sum[0][j] = 1;

  for(int i = 1 ; i <= nmax ; i++){
    for(int j = 0 ; j <= nmax * sigma ; j++){
      dp[i][j] = sum[i - 1][j];
      if(26 <= j)
        dp[i][j] -= sum[i - 1][j - 26];
      if(dp[i][j] < 0)
        dp[i][j] += modulo;
      sum[i][j] = dp[i][j];
      if(0 < j)
        sum[i][j] += sum[i][j - 1];
      if(modulo <= sum[i][j])
        sum[i][j] -= modulo;
    }
  }
}

int main()
{
  computedp();

  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1 ; testcase <= t ; testcase++){
    string s;
    cin >> s;
    int result = 0;
    for(int j = 0 ; j < s.size() ; j++){
      result += s[j] - 'a';
    }
    cout << (modulo + dp[s.size()][result] - 1) % modulo << '\n';
  }

  return 0;
}