#include <iostream>
#include <cstring>

using namespace std;
int const nmax = 700;
int const modulo = 1000000007;
int limit[5 + nmax];
char line[5 + nmax];
long long dp[5 + nmax][10][5 + nmax][2];
long long unu[5 + nmax];

int main()
{
  cin>>line;
  int n = strlen(line);
  for(int i = 1 ; i <= n ;i++){
    limit[i] = line[n - i] - '0';
  }
  for(int cif = 0; cif <= 9; cif++)
    dp[0][cif][0][true] = 1;

  for(int cif = 0; cif <= 9; cif++) {
    for(int i = 1; i <= n; i++) {

      //vreau sa calculez dp[i][cif][0], vad eu dupa aceea ce mai fac
      for(int j = 0; j < cif; j++) {
        if(j == limit[i]){
          dp[i][cif][0][true] += dp[i - 1][cif][0][true];
          dp[i][cif][0][false] += dp[i - 1][cif][0][false];
        } else{
          dp[i][cif][0][j < limit[i]] +=  dp[i - 1][cif][0][true] + dp[i - 1][cif][0][false];
        }
      }
      dp[i][cif][0][true] %= modulo;
      dp[i][cif][0][false] %= modulo;
      //k = maimari
      for(int k = 1; k <= i ;k++){
        //j = cifra pe care o punem in capat
        for(int j = 0; j < cif; j++){
          if(j == limit[i]){
            dp[i][cif][k][true] += dp[i - 1][cif][k][true];
            dp[i][cif][k][false] += dp[i - 1][cif][k][false];
          } else{
            dp[i][cif][k][j < limit[i]] +=  dp[i - 1][cif][k][true] + dp[i - 1][cif][k][false];
          }
        }
        for(int j = cif ; j <= 9 ;j++){
          if(j == limit[i]){
            dp[i][cif][k][true] += dp[i - 1][cif][k - 1][true];
            dp[i][cif][k][false] += dp[i - 1][cif][k - 1][false];
          } else{
            dp[i][cif][k][j < limit[i]] +=  dp[i - 1][cif][k - 1][true] + dp[i - 1][cif][k - 1][false];
          }
        }
        dp[i][cif][k][true] %= modulo;
        dp[i][cif][k][false] %= modulo;
      }
    }
  }
  for(int i = 1 ; i <= n ;i++){
    unu[i] = (unu[i - 1] * 10 + 1) % modulo;
  }
  long long suma = 0;
  for(int cif = 1; cif <= 9; cif++) {
    for(int maimari = 0; maimari <= n; maimari++) {
      suma += (1LL * unu[maimari] * dp[n][cif][maimari][true] ) % modulo;
      if(modulo <= suma)
        suma -= modulo;
    }
  }
  cout<<suma;
  return 0;
}