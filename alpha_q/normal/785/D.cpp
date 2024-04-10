#include <bits/stdc++.h> 

using namespace std;

const int N = 200010;
const int MOD = 1e9 + 7;

char s[N];
long long a[N], c[N], n, k, p, f[N + N];

long long bigMod (long long a, long long e) {
  if (e == -1) e = MOD - 2;
  long long r = 1ll;
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}

long long nCr (long long m, long long r) {
  if (m < 0 or r < 0 or m < r) return 0ll;
  long long res = f[m];
  res = (res * bigMod(f[r], -1)) % MOD;
  res = (res * bigMod(f[m - r], -1)) % MOD;
  return res;
}

int main (int argc, char const *argv[]) {
  f[0] = 1ll;
  for (long long i = 1; i < N + N; ++i) {
    f[i] = (i * f[i - 1]) % MOD;
  }
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      a[++k] = i;
    }
  }
  for (int i = 1; i <= k; ++i) {
    c[i] = n - k - a[i] + i; 
  }
  long long ans = 0ll;
  for (long long i = 1; i <= k; ++i) {
    ans += nCr(c[i] + i - 1ll, i);
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}