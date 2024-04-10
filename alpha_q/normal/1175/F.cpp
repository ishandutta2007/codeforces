#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 300010;
const int MOD = 1e9 + 7;
const ll P[2] = {1000003, 998244353};
 
int n, m, a[N], pos[N];
ll pwr[2][N], h[2][N], p[2][N];

inline pair <ll, ll> get (int l, int r) {
  return make_pair((p[0][r] - p[0][l - 1] + MOD) % MOD, (p[1][r] - p[1][l - 1] + MOD) % MOD);
}

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for (int it = 0; it < 2; ++it) {
    pwr[it][0] = 1;
    for (int i = 1; i < N; ++i) pwr[it][i] = pwr[it][i - 1] * P[it] % MOD;
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 1) pos[++m] = i;
    for (int it = 0; it < 2; ++it) {
      h[it][i] = (h[it][i - 1] + pwr[it][i]) % MOD;
      p[it][i] = (p[it][i - 1] + pwr[it][a[i]]) % MOD;
    }
  }
  pos[m + 1] = n + 1;
  int ans = m;
  for (int i = 1; i <= m; ++i) {
    int l = pos[i - 1], at = pos[i], r = pos[i + 1];
    for (int j = at + 1, maxVal = 1; j < r; ++j) {
      maxVal = max(maxVal, a[j]);
      int k = j - maxVal + 1;
      if (k <= at and k > l and get(k, j) == make_pair(h[0][maxVal], h[1][maxVal])) {
        ++ans;
      }
    }
    for (int j = at - 1, maxVal = 1; j > l; --j) {
      maxVal = max(maxVal, a[j]);
      int k = j + maxVal - 1;
      if (k >= at and k < r and get(j, k) == make_pair(h[0][maxVal], h[1][maxVal])) {
        ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}