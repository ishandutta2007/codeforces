#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define ld long double
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;
int const inf = 1000000000;
int const modulo = 1000000007;
int const modulo2 = 1000000009;

int frec[5 + nmax];
int v[5 + nmax];
int dp[5 + 100][5 + nmax];
int dp2[5 + 100][5 + nmax];


int main()
{
  int n;
  cin >> n;
  int smax = 0;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i];
    frec[v[i]]++;
  }
  dp2[0][0] = dp[0][0] = 1;

  int sum1 = 0;
  int sum2 = 0;
  int distinct = 0;

  for(int i = 1 ; i <= n ; i++)
    if(0 < frec[i])
      distinct++;

  for(int i = 1 ; i <= 100 ; i++)
    if(0 < frec[i]) {
      sum1 += frec[i];
      sum2 += frec[i] * i;


      for(int j = sum1 ; 1 <= j ; j--)
        for(int h2 = 1 ; h2 <= sum2; h2++)
          for(int h3 = 1 ; h3 <= frec[i] ; h3++) {

            if(h3 <= j && h3 * i <= h2) {

              dp[j][h2] += dp[j - h3][h2 - i * h3];
              if(modulo <= dp[j][h2])
                dp[j][h2] -= modulo;

              dp2[j][h2] += dp2[j - h3][h2 - i * h3];
              if(modulo2 <= dp2[j][h2])
                dp2[j][h2] -= modulo2;

            } else
              break;
          }

    }

  sum1 = 0;
  sum2 = 0;
  for(int i = 1 ; i <= 100 ; i++){
    if(0 < frec[i]) {
      sum1 += frec[i];
      sum2 += frec[i] * i;


      for(int j = 1 ; j <= sum1 ; j++)
        for(int h2 = 1 ; h2 <= sum2; h2++)
          for(int h3 = 1 ; h3 <= frec[i] ; h3++) {
            if(h3 <= j && h3 * i <= h2) {
              dp[j][h2] -= dp[j - h3][h2 - i * h3];
              if(dp[j][h2] < 0)
                dp[j][h2] += modulo;

              dp2[j][h2] -= dp2[j - h3][h2 - i * h3];
              if(dp2[j][h2] < 0)
                dp2[j][h2] += modulo2;

            } else
              break;
          }

     // cout << dp[2][6] << '\n';

      for(int j = 1 ; j <= frec[i] ; j++)
        if(dp[j][j * i] == 0 && dp2[j][j * i] == 0) {
          smax = MAX(smax , j);
          if(j == frec[i] && distinct == 2) {
            cout << n;
            return 0;
          }
          //cout << i << " " << j * i << " " << j << '\n';
        } else
          break;


      for(int j = sum1 ; 1 <= j ; j--)
        for(int h2 = 1 ; h2 <= sum2; h2++)
          for(int h3 = 1 ; h3 <= frec[i] ; h3++) {
            if(h3 <= j && h3 * i <= h2) {
              dp[j][h2] += dp[j - h3][h2 - i * h3];
              if(modulo <= dp[j][h2])
                dp[j][h2] -= modulo;

              dp2[j][h2] += dp2[j - h3][h2 - i * h3];
              if(modulo2 <= dp2[j][h2])
                dp2[j][h2] -= modulo2;

            } else
              break;
          }
    }
  }
  cout << smax;

  return 0;
}