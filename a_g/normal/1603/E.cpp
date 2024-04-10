#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int fact[N];
int invfact[N];
int dp[N][N][N]; // (i, sum, number chosen) -> EGF coefficient

int n, MOD;

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int calc(int a) {
  // number of sequences such that, when sorted, the following holds:
  // 0 <= b_i <= n+1-a
  // sum of b_i <= a
  // for i > a, i+1-a <= b_i
  dp[n+2-a][0][0] = 1;
  for (int i = n+2-a; i >= 1; i--) {
    for (int s = 0; s <= a; s++) {
      int mn = (i >= 2 ? n+2-a-i : n-a);
      for (int k = mn; k <= n; k++) {
        if (!dp[i][s][k]) continue;
        for (int l = 0; s+l*(i-1) <= a && k+l <= n; l++) {
          dp[i-1][s+l*(i-1)][k+l] += 1LL*invfact[l]*dp[i][s][k] % MOD;
          dp[i-1][s+l*(i-1)][k+l] %= MOD;
        }
      }
    }
  }


  int ans = 0;
  for (int i = n+2-a; i >= 0; i--) {
    for (int s = 0; s <= a; s++) {
      for (int k = 0; k <= n; k++) {
        if (i == 0 && k == n) ans = (ans + dp[i][s][k]) % MOD;
        dp[i][s][k] = 0;
      }
    }
  }
  return (1LL*ans*fact[n]) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> MOD;

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int ans = 0;
  for (int a = n; (n+2-a)*(n+1-a)/2 <= a+1; a--) {
    ans = (ans + calc(a))%MOD;
  }
  cout << ans << '\n';
}