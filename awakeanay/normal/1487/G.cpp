#include <iostream>

#define int long long

const int MAXN = 402;
const int MOD = 998244353;

int dp[2][MAXN][MAXN][3][3];
int dp2[MAXN][MAXN][2][2];
int finale;

int find2(int n, int minx, int typea, int typeb) {
  if(dp2[n][minx][typea][typeb])
    return dp2[n][minx][typea][typeb]-1;

  if(minx > n) {
    dp2[n][minx][typea][typeb] = 1;
    return 0;
  }

  if(n == 0) {
    dp2[n][minx][typea][typeb] = 2;
    return 1;
  }

  int ans = 0;
  if(typeb != 0) {
    ans += find2(n-1, std::max(minx-1, 0ll), 0, typea);
    ans %= MOD;
  }

  if(typeb != 1 || n == finale-1 || n == finale) {
    ans += 25*find2(n-1, minx, 1, typea);
    ans %= MOD;
  }
  else {
    ans += 24*find2(n-1, minx, 1, typea);
    ans %= MOD;
  }

  dp2[n][minx][typea][typeb] = ans+1;
  return ans;
}

signed main() {
  int n;
  std::cin >> n;
  finale = n;

  for(int j = 0; j < MAXN; j++) {
    for(int k = 0; k < MAXN; k++) {
      for(int l = 0; l < 3; l++) {
        for(int m = 0; m < 3; m++) {
          dp[0][j][k][l][m] = (j + k == 0);
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    int pq = i%2;
    for(int j = 0; j < MAXN; j++) {
      for(int k = 0; k < MAXN; k++) {
        for(int l = 0; l < 3; l++) {
          for(int m = 0; m < 3; m++) {
            dp[pq][j][k][l][m] = 0;
            if(j + k > i)
              continue;

            if(m != 0) {
              dp[pq][j][k][l][m] += dp[pq^1][std::max(0ll,j-1)][k][0][l];
              dp[pq][j][k][l][m] %= MOD;
            }
            if(m != 1) {
              dp[pq][j][k][l][m] += dp[pq^1][j][std::max(0ll,k-1)][1][l];
              dp[pq][j][k][l][m] %= MOD;
            }
            if(m != 2 || i == finale-1 || i == finale) {
              dp[pq][j][k][l][m] += 24*dp[pq^1][j][k][2][l];
              dp[pq][j][k][l][m] %= MOD;
            }
            else {
              dp[pq][j][k][l][m] += 23*dp[pq^1][j][k][2][l];
              dp[pq][j][k][l][m] %= MOD;
            }
          }
        }
      }
    }
  }

  int c[26];
  for(int i = 0; i < 26; i++) {
    std::cin >> c[i];
    c[i]++;
  }

  int ans = 1;
  for(int i = 0; i < n; i++) {
    ans *= 26-(i>1);
    ans %= MOD;
  }

  for(int j = 0; j < 26; j++) {
    ans -= find2(n, c[j], 1, 1);
    ans += MOD;
    ans %= MOD;
  }

  for(int j = 0; j < 26; j++) {
    for(int k = j+1; k < 26; k++) {
      ans += dp[n%2][c[j]][c[k]][2][2];
      ans %= MOD;
    }
  }

  std::cout << ans << std::endl;
}