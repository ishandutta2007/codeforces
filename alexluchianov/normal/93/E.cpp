#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;

int v[5 + nmax];
ll dp[5 + nmax][5 + nmax * nmax];

int k;
ll backt(ll number, int pos, int coef) {
  if(number <= nmax * nmax)
    return coef * dp[pos][number];

  if(pos == k + 1)
    return number * coef;
  else 
    return backt(number, pos + 1, coef) + backt(number / v[pos], pos + 1, coef * -1);
}

int main() {
  ll n;
  std::cin >> n >> k;
  for(int i = 1;i <= k; i++) {
    std::cin >> v[i];
    if(v[i] == 1) {
      std::cout << 0;
      return 0;
    }
  }
  for(int i = 1; i <= nmax * nmax; i++)
    dp[k + 1][i] = i;

  std::sort(v + 1, v + k + 1);
  std::reverse(v + 1, v + k + 1);
  for(int i = k; 1 <= i; i--)
    for(int j = 1;j <= nmax * nmax; j++)
      dp[i][j] = dp[i + 1][j] - dp[i + 1][j / v[i]];
  
  std::cout << backt(n, 1, 1);
}