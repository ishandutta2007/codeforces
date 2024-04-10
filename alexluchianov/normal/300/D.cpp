#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const modulo = 7340033;

int dp[40][5 + nmax];
int dp2[40][5 + nmax];

int main()
{
  dp[0][0] = 1;
  dp[1][1] = 1;
  dp[1][0] = 1;
  for(int i = 2; i <= 32; i++){
    dp[i][0] = 1;
    for(int j = 0; j <= nmax; j++)
      for(int h = 0; h <= nmax - j; h++) {
        dp2[i][j + h] += 1LL * dp[i - 1][j] * dp[i - 1][h] % modulo;
        if(modulo <= dp2[i][j + h])
          dp2[i][j + h] -= modulo;

      }
    for(int j = 0; j <= nmax; j++)
      for(int h = 0; h <= nmax - j; h++) {
        dp[i][1 + j + h] += 1LL * dp2[i][j] * dp2[i][h] % modulo;
        if(modulo <= dp[i][1 + j + h])
          dp[i][1 + j + h] -= modulo;
      }
  }
  int q;
  cin >> q;
  for(int testcase = 1 ;testcase <= q ; testcase++){
    int n, k;
    cin >> n >> k;
    int p = 0;
    while(1 < n && n % 2 == 1){
      p++;
      n /= 2;
    }

    cout << dp[p][k] << '\n';
  }
  return 0;
}