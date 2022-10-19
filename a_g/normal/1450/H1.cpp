#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2e5+5;
int fact[N];
int invfact[N];

int c[3][2];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  if (a == 0) return 0;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
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

  int n, m;
  string s;
  cin >> n >> m >> s;

  for (int i = 0; i < n; i++) {
    int index;
    if (s[i] == 'b') index = 0;
    else if (s[i] == 'w') index = 1;
    else index = 2;
    c[index][i&1]++;
  }

  int k = c[2][0] + c[2][1];
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    int d = c[1][0] - c[1][1] + i - c[2][1];
    if (d&1) continue;
    ans += 1LL*abs(d)*binommod(k, i) % MOD;
    ans %= MOD;
  }
  ans = 1LL * ans * expmod(2, MOD-k-1, MOD) % MOD;
  cout << ans << '\n';
}