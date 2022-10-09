#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
ofstream out ("text.out");

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000100;
int dp[2][10][10];
int frec[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++){
    int a;
    cin >> a;
    frec[a + 2]++;
  }
  k += 2;

  int result = 0;

  for(int i = 1 ; i <= k ; i++) {
    if(9 <= frec[i]){
      int val = frec[i] / 3;
      result += val - 2;
      frec[i] = frec[i] - val * 3 + 3 * 2;
    }
  }

  for(int i = 0 ; i <= 1 ; i++)
    for(int h = 0 ; h < 9 ; h++)
      for(int h2 = 0 ; h2 < 9; h2++)
        dp[i][h][h2] = -n * 7;

  dp[0][0][0] = 0;


  int smax = 0;
  for(int i = 3 ; i <= k ; i++) {
    for(int h = 0 ; h < 9 ; h++)
      for(int h2 = 0 ; h2 < 9 ; h2++) {

        if(3 <= frec[i]) {
          dp[1][h2][frec[i] - 3] = MAX(dp[1][h2][frec[i] - 3] , dp[0][h][h2] + 1);
          smax = MAX(smax , dp[1][h2][frec[i] - 3]);
        }
        if(6 <= frec[i]) {
          dp[1][h2][frec[i] - 6] = MAX(dp[1][h2][frec[i] - 6] , dp[0][h][h2] + 2);
          smax = MAX(smax , dp[1][h2][frec[i] - 6]);
        }

        for(int j = 0; j <= MIN(MIN(frec[i], h2), h) ; j++) {
          dp[1][h2 - j][frec[i] - j] = MAX(dp[1][h2 - j][frec[i] - j] ,  dp[0][h][h2] + j);
          smax = MAX(smax ,  dp[1][h2 - j][frec[i] - j]);
          if(j <= frec[i] - 3) {
            dp[1][h2 - j][frec[i] - j - 3] = MAX(dp[1][h2 - j][frec[i] - j - 3] ,  dp[0][h][h2] + j + 1);
            smax = MAX(smax ,  dp[1][h2 - j][frec[i] - j - 3]);
          }
          if(j <= frec[i] - 6) {
            dp[1][h2 - j][frec[i] - j - 6] = MAX(dp[1][h2 - j][frec[i] - j - 6] ,  dp[0][h][h2] + j + 2);
            smax = MAX(smax ,  dp[1][h2 - j][frec[i] - j - 6]);
          }

        }
      }
    for(int h = 0 ; h < 9 ; h++)
      for(int h2 = 0 ; h2 < 9; h2++)
        dp[0][h][h2] = dp[1][h][h2];
    for(int h = 0 ; h < 9 ; h++)
      for(int h2 = 0 ; h2 < 9; h2++)
        dp[1][h][h2] = n * -2;
  }

  cout << result + smax;

  return 0;
}