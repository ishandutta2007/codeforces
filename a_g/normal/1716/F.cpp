#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int K = 2005;
int S[K][K], fact[K];

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  S[0][0] = 1;
  fact[0] = 1;
  for(int i = 1; i < K; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
    for(int j = 1; j < K; j++) {
      S[i][j] = (S[i-1][j-1] + 1LL*j*S[i-1][j]) % MOD;
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int z = 1LL*((m+1)/2)*expmod(m, n-1, MOD) % MOD;
    int frac = 1LL*((m+1)/2)*expmod(m, MOD-2, MOD) % MOD;
    int b = n;
    int ans = 0;
    for (int l = 1; l <= k; l++) {
      ans = ans + (1LL*S[k][l]*b % MOD)*z % MOD;
      if (ans >= MOD) ans -= MOD;
      z = 1LL*z*frac % MOD;
      b = 1LL*b*(n-l) % MOD;
    }
    cout << ans << '\n';
  }
}