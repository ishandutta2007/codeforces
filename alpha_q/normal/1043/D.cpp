#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const ll P = 29;
const int K = 2;
const int M = 12;
const int N = 100010;
int MOD[] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9, 1000 * 1000 * 1000 + 21, 1000 * 1000 * 1000 + 33, 1000 * 1000 * 1000 + 87, 1000 * 1000 * 1000 + 93};

ll pwr[N][K];
ll inv[N][K];
ll hsh[K][M][N];
int n, m, s[M][N], pos[M][N];

ll bigMod (ll a, ll e, int mod) {
  if (e == -1) e = mod - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % mod;
    a = a * a % mod, e >>= 1;
  }
  return ret;
}

ll getHash (int at, int l, int r) {
  ll ret = 0;
  for (int i = 0; i < K; ++i) {
    ll cur = (hsh[i][at][r] - hsh[i][at][l - 1]) * inv[l][i] % MOD[i];
    if (cur < 0) cur += MOD[i];
    ret += cur;
  }
  return ret;
}

bool ok (int val, int len) {
  ll yo = getHash(1, pos[1][val], pos[1][val] + len - 1);
  for (int i = 2; i <= m; ++i) {
    ll cur = getHash(i, pos[i][val], pos[i][val] + len - 1);
    if (cur != yo) return 0;
  }
  return 1;
}

int main() {
  srand(time(0));
  random_shuffle(MOD, MOD + 6);
  for (int i = 0; i < K; ++i) {
    pwr[0][i] = 1, inv[0][i] = 1;
    ll Q = bigMod(P, -1, MOD[i]);
    for (int j = 1; j < N; ++j) {
      pwr[j][i] = pwr[j - 1][i] * P % MOD[i];
      inv[j][i] = inv[j - 1][i] * Q % MOD[i];
    }
  }
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", s[i] + j);
      pos[i][s[i][j]] = j;
    }
    for (int k = 0; k < K; ++k) {
      ll tmp = P; 
      for (int j = 1; j <= n; ++j) {
        hsh[k][i][j] = (hsh[k][i][j - 1] + tmp * s[i][j]) % MOD[k];
        tmp = tmp * P % MOD[k];
      }
    }
  }
  // cout << getHash(1, 3, 5) << endl;
  // cout << getHash(2, 2, 4) << endl;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int lo = 1, hi = n;
    for (int j = 1; j <= m; ++j) {
      hi = min(hi, n - pos[j][i] + 1);
    }
    while (lo < hi) {
      int mid = lo + hi + 1 >> 1;
      if (ok(i, mid)) lo = mid;
      else hi = mid - 1;
    }
    ans += (long long) lo;
    // cout << i << " --> " << lo << '\n';
  }
  printf("%lld\n", ans);
  return 0;
}