#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 5005;
int fact[N];
int invfact[N];
int dp[N][N];
// dp[x][y] = number of permutations of [x] with y increasing steps

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int k = q/p;
  int b = inversemod(q-k*p, p);
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

  for (int i = 1; i < N; i++) dp[i][0] = 1;

  for (int i = 1; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      dp[j][i] = (1LL*(i+1)*dp[j-1][i]+1LL*(j-i)*dp[j-1][i-1]) % MOD;
    }
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      ans += 1LL*dp[j][i]*invfact[j] % MOD;
      ans %= MOD;
    }
    ans = 1LL*ans*fact[n] % MOD;
    cout << ans << ' ';
  }
  cout << '\n';
}