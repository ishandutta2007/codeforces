#include <iostream>
#include <vector>

using ll = long long ;

int const nmax = 1000;
int const modulo = 1000000007;
int dp[1 + nmax][1 + nmax][2][2];
int comb[1 + nmax][1 + nmax];

int fact[1 + nmax];
int dptotal[1 + nmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  fact[0] = 1;
  for(int i = 1;i <= n; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  
  for(int i = 0; i <= n; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % modulo;
  }

  dp[0][0][1][0] = 1;
  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= i; j++)
      for(int h1 = 0; h1 <= 1; h1++)
        for(int h2 = 0; h2 <= 1; h2++) {
          if(0 < dp[i - 1][j][h1][h2]) {
            dp[i][j][h2][0] += dp[i - 1][j][h1][h2];
            if(modulo <= dp[i][j][h2][0])
              dp[i][j][h2][0] -= modulo;
            dp[i][j + 1][h2][1] += dp[i - 1][j][h1][h2];
            if(modulo <= dp[i][j + 1][h2][1])
              dp[i][j + 1][h2][1] -= modulo;
            
            if(0 == h1) {
              dp[i][j + 1][h2][0] += dp[i - 1][j][h1][h2];
              if(modulo <= dp[i][j + 1][h2][0])
                dp[i][j + 1][h2][0] -= modulo;
            }
          }
        }
  
  for(int i = 0; i <= n; i++) {
    dptotal[i] = (dp[n][i][0][0] + dp[n][i][1][0]) % modulo;
    dptotal[i] = 1LL * dptotal[i] * fact[n - i] % modulo;
  }
  for(int i = n - 1; 0 <= i; i--)
    for(int j = i + 1; j <= n; j++) {
      dptotal[i] -= 1LL * dptotal[j] * comb[j][i] % modulo;
      if(dptotal[i] < 0)
        dptotal[i] += modulo;
    }
  std::cout << dptotal[k] << '\n';
  return 0;
}