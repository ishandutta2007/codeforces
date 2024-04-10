#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+5;
int mu[N], mult[N], inv[N];

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int n;
  cin >> n;
  mu[1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      if (j != i) mu[j] -= mu[i];
      mult[i]++;
    }
  }
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    ans = (ans-1LL*mult[i]*mu[i]*inv[n-mult[i]]) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}