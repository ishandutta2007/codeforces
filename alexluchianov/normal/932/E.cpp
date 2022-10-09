#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 5000;
int const modulo = 1000000007;
int dp[1 + nmax][1 + nmax];
int comb[1 + nmax];

void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int inv(int number){
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}
int fact[1 + nmax];

void precompute(int n, int k){
  fact[0] = 1;
  for(int i = 1;i <= k; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  comb[0] = 1;
  for(int i = 1; i <= k; i++){
    comb[i] = (1LL * comb[i - 1] * (n - i + 1)) % modulo;
    comb[i] = (1LL * comb[i] * inv(i)) % modulo;
  }
}

int lgpow(int a, int b){
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

int main()
{
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1;
  for(int i = 1;i <= k; i++)
    for(int j = 1; j <= i; j++)
      dp[i][j] = (1LL * dp[i - 1][j] * j + dp[i - 1][j - 1]) % modulo;
  int result = 0;
  precompute(n, k);

  for(int i = 1;i <= k; i++) {
    result += 1LL * dp[k][i] * comb[i] % modulo * fact[i] % modulo * lgpow(2, n - i) % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}