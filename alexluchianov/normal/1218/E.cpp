#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 20000;
int const modulo = 998244353;

int v[5 + nmax], init[5 + nmax];

int dp[5 + nmax];

int solve(int n, int k) {
  for(int i = 0; i <= k; i++)
    dp[i] = 0;
  dp[0] = 1;
  for(int i = 1; i <= n; i++)
    v[i] = init[i];
  int op, q;
  std::cin >> op;
  if(op == 1) {
    int x, y;
    std::cin >> q >> x >> y;
    v[x] = y;
  } else {
    int x, y, d;
    std::cin >> q >> x >> y >> d;
    for(int j = x; j <= y; j++)
      v[j] += d;
  }

  for(int i = 1; i <= n; i++) {
    if(modulo <= v[i])
      v[i] -= modulo;
    int val = q - v[i];
    if(val < 0)
      val += modulo;
    for(int j = k; 1 <= j; j--)
      dp[j] = (dp[j] + 1LL * dp[j - 1] * val) % modulo;
  }
  return dp[k];
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k, q;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> init[i];
  std::cin >> q;
  for(int i = 1;i <= q; i++)
    std::cout << solve(n, k) << '\n';
  return 0;
}