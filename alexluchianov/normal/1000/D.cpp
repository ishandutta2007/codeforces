#include <iostream>

using namespace std;

int const nmax = 1000;
int const modulo = 998244353;

int v[5 + nmax];
int comb[5 + nmax][5 + nmax];

void computecomb(){
  for(int i = 0 ; i <= nmax ; i++)
    comb[i][0] = 1;

  for(int i = 1 ; i <= nmax ; i++){
    for(int j = 1 ; j <= i ; j++){
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if(modulo <= comb[i][j])
        comb[i][j] -= modulo;
    }
  }
}

int n;
int dp[5 + nmax];

int main()
{
  computecomb();
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  int result = 0;
  dp[n + 1] = 1;
  for(int i = n ; 1 <= i ; i--){
    if(0 < v[i]){
      for(int j = i + v[i] + 1 ;j <= n + 1; j++) {
        dp[i] += 1LL * dp[j] * comb[j - i - 1][v[i]] % modulo;
        if(modulo <= dp[i])
          dp[i] -= modulo;
      }
    }
    result += dp[i];
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}