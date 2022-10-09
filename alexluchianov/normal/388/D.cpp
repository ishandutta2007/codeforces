#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 30;
int const modulo = 1000000007;
int dp[5 + nmax][5 + nmax][2];

int main() {
  int n;
  std::cin >> n;
  dp[nmax][0][0] = 1;

  for(int i = nmax; 0 < i; i--) {
    int bit = (0 < ((1 << (i - 1)) & n));
    for(int j = 0; j <= nmax; j++) {
      for(int h = 0; h < 2; h++) {
        if(0 < dp[i][j][h]) {
          if(0 < j) {
            dp[i - 1][j][h | (0 < bit)] += 1LL * dp[i][j][h] * (1 << (j - 1)) % modulo;
            if(modulo <= dp[i - 1][j][h | (0 < bit)])
              dp[i - 1][j][h | (0 < bit)] -= modulo;

            if(1 <= bit || 1 <= h) {
              dp[i - 1][j][h] += 1LL * dp[i][j][h] * (1 << (j - 1)) % modulo;
              if(modulo <= dp[i - 1][j][h])
                dp[i - 1][j][h] -= modulo;
            }
          } else {
            dp[i - 1][j][h | (0 < bit)] += dp[i][j][h];
            if(modulo <= dp[i - 1][j][h | (0 < bit)])
              dp[i - 1][j][h | (0 < bit)] -= modulo;
          }

          if(1 <= bit || 1 <= h) {
            dp[i - 1][j + 1][h] += dp[i][j][h];
            if(modulo <= dp[i - 1][j + 1][h])
              dp[i - 1][j + 1][h] -= modulo;
          }

        }
      }
    }
  }

  int result = 1;
  for(int i = 1; i <= nmax; i++)
    for(int h = 0;h < 2; h++) {
      result += dp[0][i][h];
      if(modulo <= result)
        result -= modulo;
    }

  std::cout << result;
  return 0;
}