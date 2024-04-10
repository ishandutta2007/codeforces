#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 2000;
int const modulo = 1000000007;
int v[5 + nmax];
int dp[5 + nmax];

int main() {
  int n, target;
  std::cin >> n >> target;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  dp[0] = 1;
  for(int i = 1;i <= n; i++) {
    for(int j = i; 0 < j; j--) {
      dp[j] += dp[j - 1];
      if(modulo <= dp[j])
        dp[j] -= modulo;
    }
    for(int j = 0; j <= i; j++)
      if(j != target - v[i])
        dp[j] = 0;
    for(int j = 0; j <= i; j++) {
      dp[j] += 1LL * dp[j + 1] * (j + 1) % modulo;
      if(modulo <= dp[j])
        dp[j] -= modulo;
    }
  }
  
  std::cout << dp[0] << '\n';
  return 0;
}