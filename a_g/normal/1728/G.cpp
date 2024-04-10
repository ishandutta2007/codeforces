#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int M = 20;
int between[M][M], dp[M][M];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int d, n, m;
  cin >> d >> n >> m;
  vector<int> l(n), p(m);
  for (int& x: l) cin >> x;
  for (int& x: p) cin >> x;
  p.push_back(-d);
  p.push_back(2*d);
  sort(l.begin(), l.end());
  sort(p.begin(), p.end());
  for (int i = 0; i < m+2; i++) {
    for (int j = i+1; j < m+2; j++) {
      between[i][j] = 1;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; p[i] < l[k]; i++) {
      for (int j = m+1; p[j] > l[k]; j--) {
        int dist = min(l[k]-p[i], p[j]-l[k]);
        if (i == 0 && j == m+1) dist = d+1;
        between[i][j] = 1LL*between[i][j]*dist % MOD;
      }
    }
  }

  for (int mask = 0; mask < (1<<m); mask++) {
    int u = (mask<<1)|1|(1<<(m+1));
    int val = (__builtin_popcount(mask)&1 ? -1 : 1);
    while (__builtin_popcount(u) >= 2) {
      int l = __builtin_ctz(u);
      int r = __builtin_ctz(u^(1<<l));
      val = 1LL*val*between[l][r] % MOD;
      u ^= 1<<l;
    }

    u = (mask<<1)|1|(1<<(m+1));
    while (__builtin_popcount(u) >= 2) {
      int l = __builtin_ctz(u);
      int r = __builtin_ctz(u^(1<<l));
      dp[l][r] = (dp[l][r]+val) % MOD;
      u ^= 1<<l;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int f;
    cin >> f;
    int ans = 0;
    for (int l = 0; p[l] < f; l++) {
      for (int r = m+1; p[r] > f; r--) {
        int dist = min(f-p[l], p[r]-f);
        if (l == 0 && r == m+1) dist = d+1;
        ans = (ans+1LL*dp[l][r]*dist) % MOD;
      }
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
  }
}