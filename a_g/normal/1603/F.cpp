#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e7+4;
int a[N], ainv[N], pow2[N];

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

int add(int x, int y){
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int g (int n, int k) {
  if (n > k) return 0;
  return a[k]*(1LL*ainv[k-n]*ainv[n] % MOD) % MOD;
}

int p (int n, int k, int x) {
  if (x == 0) {
    if (n > k) return 0;
    int ans = 1;
    for (int term: {expmod(2, 1LL*n*(n-1)/2, MOD), a[k], ainv[k-n]}) {
      ans = 1LL*ans*term % MOD;
    }
    return ans;
  }
  else {
    int ans = 0;
    int u = expmod(2, n, MOD);
    int v = 1;
    int q = expmod(pow2[k]-1, MOD-2, MOD);
    for (int i = 0; i < k; i++) {
      int s = 1;
      for (int term:
          {
          g(i, k),
          int(1-1LL*(pow2[i]-1)*q % MOD),
          (k^i)&1 ? 1 : -1, 
          a[k-i-1],
          v
          }
          ) {
        s = 1LL * s * term % MOD;
      }
      if (s < 0) s += MOD;
      ans = add(ans, s);
      v = 1LL*v*u % MOD;
    }
    if (ans < 0) ans += MOD;
    return ans;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  pow2[0] = 1;
  for (int i = 1; i < N; i++) {
    pow2[i] = add(pow2[i-1], pow2[i-1]);
  }

  int s = 1;
  a[0] = 1;
  for (int i = 1; i < N-1; i++){
    a[i] = 1LL*a[i-1]*(pow2[i]-1) % MOD;
  }

  ainv[N-2] = expmod(a[N-2], MOD-2, MOD);
  for (int i = N-3; i >= 0; i--){
    ainv[i] = 1LL*ainv[i+1]*(pow2[i+1]-1) % MOD;
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k, x;
    cin >> n >> k >> x;
    cout << p(n, k, x) << '\n';
  }
}