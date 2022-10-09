#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
int const modulo = 1000000007;
int _pow[1 + nmax];
int dp[1 + nmax][1 + nmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  _pow[0] = 1;
  for(int i = 1;i <= n; i++)
    _pow[i] = _pow[i - 1] * 2LL % modulo;
  dp[0][0] = 1;
  for(int i = 1;i <= n; i++) {
    for(int j = 1; j <= n; j++) 
      for(int x = 1; x <= i; x++)
        dp[j][x] = 1LL * dp[j][x] * _pow[x] % modulo;
    for(int j = 1;j <= n; j++)  
      for(int x = 1; x <= i; x++) {
        dp[j][i] += 1LL * dp[j - 1][x - 1] * (_pow[i - x + 1] - 1) % modulo;
        if(modulo <= dp[j][i])
          dp[j][i] -= modulo;
       }
  }
  int result = 0;
  for(int i = 0;i <= n; i++) {
    result += dp[k][i];
    if(modulo <= result)
      result -= modulo;
  }
  std::cout << result;
  return 0;
}