#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 250;
int const modulo = 1000000007;
int comb[1 + nmax][1 + nmax];

void computecomb(){
  for(int i = 0;i <= nmax; i++)
    comb[i][0] = 1;
  for(int i = 1; i <= nmax; i++)
    for(int j = 1; j <= i; j++) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % modulo;
    }
}

int lgpow[1 + nmax];
int lgpow2[1 + nmax];

int dp[1 + nmax][1 + nmax];

int main()
{
  computecomb();

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  dp[0][0] = 1;

  lgpow[0] = 1;
  for(int i = 1;i <= n; i++)
    lgpow[i] = 1LL * lgpow[i - 1] * k % modulo;

  lgpow2[0] = 1;
  for(int i = 1;i <= n; i++)
    lgpow2[i] = 1LL * lgpow2[i - 1] * (k - 1) % modulo;

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++) {
      for(int j2 = 0; j2 < j; j2++){
        dp[i][j] += 1LL * dp[i - 1][j2] * comb[n - j2][(j - j2)] % modulo * lgpow[j2] % modulo * lgpow2[ n - j] % modulo;

        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;

      }
      dp[i][j] += 1LL * dp[i - 1][j] * (modulo + lgpow[j] - lgpow2[j]) % modulo * lgpow2[n - j] % modulo;
      if(modulo <= dp[i][j])
        dp[i][j] -= modulo;
    }
  cout << dp[n][n];
  return 0;
}