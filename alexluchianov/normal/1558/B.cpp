#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 4000000;
int dp[1 + nmax], sum[1 + nmax];

int main() {
  int n, modulo;
  std::cin >> n >> modulo;
  dp[1] = 1;
  for(int i = 1; i <= n; i++) {
    sum[i] += sum[i - 1];
    if(modulo <= sum[i])
      sum[i] -= modulo;
    dp[i] += sum[i];
    sum[i + 1] += dp[i];
    if(modulo <= sum[i + 1])
      sum[i + 1] -= modulo;
    for(int j = 2;i * j <= n; j++) {
      sum[i * j] += dp[i];
      if(modulo <= sum[i * j])
        sum[i * j] -= modulo;
      if((i + 1) * j <= n) {
        sum[(i + 1) * j] -= dp[i];
        if(sum[(i + 1) * j] < 0)
          sum[(i + 1) * j] += modulo;
      }
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}