#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 255;
int pw[N][N*N];
int inv[N];
int fact[N];
int invfact[N];
int dp[N][N]; // (stage, used) -> EGF

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }
  for (int i = 1; i < N; i++) {
    pw[i][0] = 1;
    for (int j = 1; j < N*N; j++) {
      pw[i][j] = 1LL * pw[i][j-1] * i % MOD;
    }
  }
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      for (int x = 0; x+j < n; x++) {
        dp[i+1][j+x] = (dp[i+1][j+x] + (1LL * dp[i][j]*invfact[x] % MOD) * pw[k-i][x*j+x*(x-1)/2]) % MOD;
      }
    }
  }
  cout << (1LL * dp[k][n-1] * fact[n-1]) % MOD << '\n';
}