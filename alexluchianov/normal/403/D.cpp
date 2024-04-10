#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000;
int const kmax = 50;
int const modulo = 1000000007;

int dp[1 + kmax][1 + nmax];
int sol[1 + kmax][1 + nmax];
int fact[1 + 2 * nmax], inv[1 + 2 * nmax];

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

int comb(int n, int k){
  int result2 = 1LL * inv[k] * inv[n - k] % modulo;
  return 1LL * fact[n] * result2 % modulo;
}

int combrep(int n, int k){
  return comb(n + k - 1, k - 1);
}

void precompute(){
  dp[0][0] = 1;
  fact[0] = 1;
  for(int i = 1; i <= nmax * 2; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  int x, y;

  gcd(fact[nmax * 2], modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  inv[nmax * 2] = x;

  for(int i = nmax * 2 - 1;0 <= i; i--)
    inv[i] = 1LL * inv[i + 1] * (i + 1) % modulo;

  for(int lim = 1; lim <= nmax; lim++)
    for(int i = kmax; 1 <= i; i--)
      for(int j = lim;j <= nmax; j++) {
        dp[i][j] += 1LL * dp[i - 1][j - lim] * i % modulo;
        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;
      }


  for(int i = 1;i <= kmax; i++)
    for(int j = 1;j <= nmax; j++)
      for(int j2 = 1; j2 <= j; j2++)
        if(0 < dp[i][j2]) {
          sol[i][j] += 1LL * dp[i][j2] * combrep(j - j2, i + 1) % modulo;
          if(modulo <= sol[i][j])
            sol[i][j] -= modulo;
        }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  precompute();
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++){
    int n, k;
    cin >> n >> k;
    if(kmax <= k)
      cout << 0 << '\n';
    else
      cout << sol[k][n] << '\n';
  }
  return 0;
}