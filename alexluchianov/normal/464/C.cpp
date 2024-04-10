#include <iostream>

using namespace std;

int const nmax = 100000;
int const modulo = 1000000007;

string v[5 + nmax];

int dp[5 + nmax][10];
int dp2[5 + nmax][10];

int lgpow(int a , int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a , b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
 // cout <<":" <<lgpow(10 , 0) << " "<<   lgpow(10 , modulo - 1) << " "  << lgpow(10 , (modulo - 1) * 2)  << '\n';

  string s;
  cin >> s;

  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  for(int h = 0 ; h <= 9 ; h++) {
    dp[n + 1][h] = h;
    dp2[n + 1][h] = 1;
  }

  for(int i = n ; 1 <= i ; i--){

    for(int h = 0 ; h <= 9 ; h++) {
      dp[i][h] = dp[i + 1][h];
      dp2[i][h] = dp2[i + 1][h];
    }

    int ch = v[i][0] - '0';
    dp[i][ch] = 0;
    dp2[i][ch] = 0;

    //cout << dp[i][ch] << '\n';
    int pow10 = 0;
    for(int j = v[i].size() - 1; 3 <= j ;j--){

      //cout << j << " " << pow10 <<" "<< v[i][j] - '0' << '\n';
      dp[i][ch] += 1LL * dp[i + 1][v[i][j] - '0'] * lgpow(10 , pow10) % modulo;
      if(modulo <= dp[i][ch])
        dp[i][ch] -= modulo;

      pow10 = (pow10 + dp2[i + 1][v[i][j] - '0']) % (modulo - 1);

      dp2[i][ch] += dp2[i + 1][v[i][j] - '0'];
      if((modulo - 1) <= dp2[i][ch])
        dp2[i][ch] -= (modulo - 1);
    }


  }
  int pow10 = 0;

  int result = 0;
  for(int i = s.size() - 1; 0 <= i ; i--){
    result += 1LL * dp[1][s[i] - '0'] * lgpow(10 , pow10) % modulo;
    pow10 = (pow10 + dp2[1][s[i] - '0']) % (modulo - 1);
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}