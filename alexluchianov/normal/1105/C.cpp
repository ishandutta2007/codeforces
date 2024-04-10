#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const modulo = 1000000007;
int dp[1 + nmax][3];

int lower_rest(int n, int rest) {
  if(rest == 0)
    return n / 3;
  return n / 3 + (rest <= n % 3);
}

int main() {
  int n, l, r;
  std::cin >> n >> l >> r;
  int c[3] = {0};
  for(int h = 0; h < 3; h++)
    c[h] = lower_rest(r, h) - lower_rest(l - 1, h);
  dp[0][0] = 1;
  for(int i = 0;i < n; i++) 
    for(int h = 0; h < 3; h++) {
      for(int h2 = 0; h2 < 3; h2++) {
        dp[i + 1][(h + h2) % 3] += 1LL * dp[i][h] * c[h2] % modulo;
        if(modulo <= dp[i + 1][(h + h2) % 3])
          dp[i + 1][(h + h2) % 3] -= modulo;
      }
    }
  std::cout << dp[n][0];
}