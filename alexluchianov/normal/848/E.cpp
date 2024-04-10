#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50000;
int const modulo = 998244353;

int dp[1 + nmax][32];

int main() {
  int n;
  std::cin >> n;
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int mask = 0; mask < 32; mask++) {
      int a[5] = {0}, b[5] = {0};
      for(int j = 0; j < 5; j++)
        a[j] = (0 < (mask & (1 << j)));
      
      if(i + 1 <= n) {
        int mask2 = 0;
        for(int j = 0; j < 5; j++)
          b[j] = a[j];
        b[4] = 1;
        b[2] = b[3] = 0;
        if(!(a[4] == 1 && (a[2] == 0 || a[3] == 0))) {

          for(int j = 0; j < 5; j++)
            mask2 += (b[j]<<j);
          dp[i + 1][mask2] += dp[i][mask];
          if(modulo <= dp[i + 1][mask2])
            dp[i + 1][mask2] -= modulo;
        }
      }

      if(i + 2 <= n) {
        for(int j = 0; j < 5; j++)
          b[j] = a[j];
        for(b[2] = a[2]; b[2] < 2; b[2]++)
          for(b[3] = a[3]; b[3] < 2; b[3]++) {
            if(a[4] == 0) {
              b[0] = b[2];
              b[1] = b[3];
            }
            int mask2 = 0;
            for(int j = 0; j < 5; j++)
              mask2 += (b[j]<<j);
            int coef = 1;
            if(0 == i)
              coef = 2;

            dp[i + 2][mask2] += 1LL * dp[i][mask] * (1 + b[2] - a[2]) * (1 + b[3] - a[3]) * coef % modulo;
            if(modulo <= dp[i + 2][mask2])
              dp[i + 2][mask2] -= modulo;
          }
      }

      if(i + 3 <= n) {
        for(int j = 0; j < 5; j++)
          b[j] = a[j];
        for(int beef1 = 0; beef1 < 2; beef1++)
          for(int beef2 = 0; beef2 < 2; beef2++)
            for(b[2] = 0; b[2] < 2; b[2]++)
              for(b[3] = 0; b[3] < 2; b[3]++) {
                if(a[4] == 0 && (((a[2] + beef1) == 2) || ((a[3] + beef2) == 2))) 
                  continue;
                else  if(a[4] == 1 && (((a[2] + beef1) != 1) || ((a[3] + beef2) != 1))) 
                  continue;
                if(a[4] == 0) {
                  b[0] = a[2] + beef1;
                  b[1] = a[3] + beef2;
                }
                b[4] = 1;

                int mask2 = 0;
                for(int j = 0; j < 5; j++)
                  mask2 += (b[j]<<j);
                int coef = 1;
                if(0 == i)
                  coef = 3;
                dp[i + 3][mask2] += 1LL * dp[i][mask] * coef % modulo;
                if(modulo <= dp[i + 3][mask2])
                  dp[i + 3][mask2] -= modulo;
              }

      }

      if(i + 4 <= n) {
        for(int j = 0; j < 5; j++)
          b[j] = a[j];
        for(b[2] = a[2]; b[2] < 2; b[2]++)
          for(b[3] = a[3]; b[3] < 2; b[3]++) {
            if(a[4] == 0) {
              b[0] = b[2];
              b[1] = b[3];
            }
            int mask2 = 0;
            for(int j = 0; j < 5; j++)
              mask2 += (b[j]<<j);
            int coef = 1;
            if(0 == i)
              coef = 4;
            dp[i + 4][mask2] += 1LL * dp[i][mask] * (1 + 3 * (b[2] - a[2])) * (1 + 3 * (b[3] - a[3])) * coef % modulo;
            if(modulo <= dp[i + 4][mask2])
              dp[i + 4][mask2] -= modulo;
          }

      }
    }
  }

  int result = 0;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++) {
      int mask = (1 << 4) + (i<<3) + ((!i)<<1) + (j<<2) + ((!j)<<0);
      result += dp[n][mask];
      if(modulo <= result)
        result -= modulo;
    }
  std::cout << result;
  return 0;
}