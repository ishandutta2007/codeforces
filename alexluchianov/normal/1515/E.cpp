#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 400;

int modulo; 

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

int fact[1 + nmax], inv[1 + nmax], pow2[1 + nmax];
int dp[1 + nmax][1 + nmax];

int main() {
  int n;
  std::cin >> n >> modulo;
  fact[0] = 1;
  for(int i = 1; i <= n; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  for(int i = 0;i <= n; i++)
    inv[i] = lgpow(fact[i], modulo - 2);
  for(int i = 0;i <= n; i++)
    pow2[i] = lgpow(2, i);

  dp[1][1] = 1;
  for(int i = 1;i <= n; i++) {
    dp[i][i] = 1LL * inv[i] * pow2[i - 1] % modulo;

    for(int j = 1; j <= i; j++) {
      for(int h = 1; h <= j; h++) {
        int coef = 1LL * inv[h] * pow2[h - 1] % modulo;
        if(0 < i - h - 1) 
          dp[i][j] += 1LL * dp[i - h - 1][j - h] % modulo * coef % modulo;
        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;

      }
    }
  }
  
  int result = 0;

  for(int i = 1; i <= n; i++) {
    result += 1LL * dp[n][i] * fact[i] % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  std::cout << result << '\n';
  return 0;
}