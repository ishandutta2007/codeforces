#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int K = 4;
const int N = 300010;
ll P[K] = {1000003, 15485863, 8960453, 7368787};
int MOD[K] = {998244353, 982451653, 1000000007, 1000000009};

ll bigMod (ll a, ll e, int mod) {
  if (e == -1) e = mod - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % mod;
    a = a * a % mod, e >>= 1;
  }
  return ret;
}

map <ll, int> freq;
int t, n, a[N], st[N], ptr, en;
ll pf[N], sf[N], h[2][N], pwr[2][N], inv[2][N];

inline ll get (int l, int r) {
  if (l > r) return 0;
  ll one = (h[0][r] - h[0][l - 1]) * inv[0][l] % MOD[0];
  ll two = (h[1][r] - h[1][l - 1]) * inv[1][l] % MOD[1];
  if (one < 0) one += MOD[0]; if (two < 0) two += MOD[1];
  return (one << 31LL) | two;
}

ll solve (int lo, int hi) {
  if (lo == hi) return 0;
  int mid = lo + hi >> 1; 
  ptr = 0, freq.clear();
  for (int i = mid + 1; i <= hi; ++i) {
    int x = a[i];
    if (ptr and st[ptr] == x) --ptr;
    else {
      st[++ptr] = x;
      for (int it = 0; it < 2; ++it) {
        h[it][ptr] = (h[it][ptr - 1] + x * pwr[it][ptr]) % MOD[it];
      }
    }
    ++freq[get(1, ptr)];
  }
  ptr = 0; ll ret = 0;
  for (int i = mid; i >= lo; --i) {
    int x = a[i];
    if (ptr and st[ptr] == x) --ptr;
    else {
      st[++ptr] = x;
      for (int it = 0; it < 2; ++it) {
        h[it][ptr] = (h[it][ptr - 1] + x * pwr[it][ptr]) % MOD[it];
      }
    }
    ret += freq[get(1, ptr)];
  }
  ret += solve(lo, mid); ret += solve(mid + 1, hi);
  return ret;
}

int main() {
  srand(time(0));
  random_shuffle(P, P + K);
  random_shuffle(MOD, MOD + K);
  for (int it = 0; it < 2; ++it) {
    pwr[it][0] = inv[it][0] = 1;
    ll inv_mod = bigMod(P[it], -1, MOD[it]);
    for (int i = 1; i < N; ++i) {
      pwr[it][i] = pwr[it][i - 1] * P[it] % MOD[it];
      inv[it][i] = inv[it][i - 1] * inv_mod % MOD[it];
    }
  }
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    printf("%lld\n", solve(1, n));
  }
  return 0;
}