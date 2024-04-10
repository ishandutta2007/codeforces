#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>

int const nmax = 5000;
int const modulo = 1000000007;
int v[1 + nmax];

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int comb(int n, int k) {
  int result = 1, result2 = 1;
  for(int i = n - k + 1; i <= n; i++)
    result = 1LL * result * i % modulo;
  for(int i = 1;i <= k; i++)
    result2 = 1LL * result2 * i % modulo;
  return 1LL * result * lgpow(result2, modulo - 2) % modulo;
}

int fact(int n) {
  int result = 1;
  for(int i = 1;i <= n;i++)
    result = 1LL * result * i % modulo;
  return result;
}

int dp[1 + nmax][1 + nmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) {
    dp[i][0] = 1LL * dp[i - 1][0] * v[i] % modulo;
    for(int j = 1; j <= i; j++) 
      dp[i][j] = (dp[i - 1][j - 1] + 1LL * dp[i - 1][j] * v[i]) % modulo;
  }
  int result = 0;
  
  for(int i = 0;i <= n; i++) {
    if(i <= k) {
      if(i % 2 == 0)
        result += 1LL * dp[n][i] * comb(k, i) % modulo * fact(i) % modulo * lgpow(lgpow(n, i), modulo - 2) % modulo;
      else
        result -= 1LL * dp[n][i] * comb(k, i) % modulo * fact(i) % modulo * lgpow(lgpow(n, i), modulo - 2) % modulo;
      if(modulo <= result)
        result -= modulo;
      if(result < 0)
        result += modulo;
    }
  }

  int base = 1;
  for(int i = 1;i <= n; i++) 
    base = 1LL * base * v[i] % modulo;

  std::cout << (modulo + base - result) % modulo << '\n';
  return 0;
}