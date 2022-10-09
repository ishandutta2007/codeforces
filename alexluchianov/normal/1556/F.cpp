#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 14;
int const modulo = 1000000007;

int v[1 + nmax];

void gcd(int a, int b, int &x, int &y) {
  if(b == 0) {
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a/ b * y;
  }
}

int inverse(int number) {
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

int dp[1 + nmax][1 << nmax];
int coef[1 + nmax][1 + nmax], smallcoef[1 + nmax];
int fastcoef[1 << nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  
  for(int i = 0; i < n; i++) {
    smallcoef[i] = inverse(v[i]);
    for(int j = 0; j < n; j++)
      coef[i][j] = inverse((v[i] + v[j]) % modulo);
  }

  for(int mask = 1; mask < (1 << n); mask++) {
    int aux = 1;
    for(int i = 0; i < n; i++)
      if(0 < ((1 << i) & mask))
        dp[i][mask] = 1;

    for(int mask2 = mask; 0 < mask2; mask2 = ((mask2 - 1) & mask)) {
      if(mask2 == mask)
        fastcoef[mask2] = 1;
      else {
        /*
        fastcoef[mask2] = 1;
        for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
            if(0 < ((1 << i) & mask) && 0 < ((1 << j) & mask))
              if(0 < ((1 << i) & mask2) && 0 == ((1 << j) & mask2))
                fastcoef[mask2] = 1LL * fastcoef[mask2] * v[j] % modulo * coef[i][j] % modulo;
        */

        for(int i = 0; i < n; i++)
          if(0 < ((1 << i) & mask) && 0 == ((1 << i) & mask2)) {
            fastcoef[mask2] = fastcoef[mask2 ^ (1 << i)];
            for(int j = 0; j < n; j++)
              if(i != j && 0 < ((1 << j) & mask)) {
                if(0 < ((1 << j) & mask2)) 
                  fastcoef[mask2] = 1LL * fastcoef[mask2] * v[i] % modulo * coef[i][j] % modulo;
                else
                  fastcoef[mask2] = 1LL * fastcoef[mask2] * smallcoef[j] % modulo * (v[i] + v[j]) % modulo;
              }
            break;
          }
        

        for(int i = 0; i < n; i++)
          if(0 < ((1 << i) & mask2)) {
            dp[i][mask] -= 1LL * dp[i][mask2] * fastcoef[mask2] % modulo;
            if(dp[i][mask] < 0)
              dp[i][mask] += modulo;
          }
      }
    }
  }
  int result = 0;

  for(int i = 0; i < n; i++) {
    result += dp[i][(1 << n) - 1];
    if(modulo <= result)
      result -= modulo;
  }
  std::cout << result << '\n';
  return 0;
}