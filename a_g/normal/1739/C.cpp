#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 65;

int fact[N];
int invfact[N];
int dp[N];

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans[3] = {0, 0, 1};
    for (int i = 0; i < n; i++) {
      int j = n-i;
      int x = binommod(j-1, j/2);
      int y = binommod(j-1, j/2-1);
      if (i%4 == 0) ans[0] = (ans[0]+x) % MOD;
      else if (i%4 == 1) ans[1] = (ans[1]+y) % MOD;
      else if (i%4 == 2) ans[1] = (ans[1]+x) % MOD;
      else ans[0] = (ans[0]+y)%MOD;
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
}