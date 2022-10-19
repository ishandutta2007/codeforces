#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1005;
int fact[N];
int invfact[N];
int dp[N][2], ndp[N][2];
// first: how much extra
// second: is strictly greater in lower bits
// third: count

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int calc(int n, long long r, long long z) {
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < 2; y++) {
      dp[x][y] = 0;
      ndp[x][y] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < 60; i++) {
    bool b = r&(1LL<<i);
    int start = (z&(1LL<<i) ? 1 : 0);
    for (int k = start; k <= n; k+= 2) {
      for (int x = 0; x < N; x++) {
        for (int y = 0; y < 2; y++) {
          int q = x+k;
          int count = 1LL * binommod(n, k) * (dp[x][y]) % MOD;
          if (((q&1) > b) ||
              ((q&1) == b) && y) {
            ndp[q/2][1] = (ndp[q/2][1] + count) % MOD;
          }
          else {
            ndp[q/2][0] = (ndp[q/2][0] + count) % MOD;
          }
        }
      }
    }
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < 2; y++) {
        dp[x][y] = ndp[x][y];
        ndp[x][y] = 0;
      }
    }
  }
  int ans = 0;
  return dp[0][0];
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
  int n;
  long long l, r, z;
  cin >> n >> l >> r >> z;
  cout << (0LL+MOD+calc(n, r, z)-calc(n, l-1, z))%MOD << '\n';
}