#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 10;
const int N = 100010;
const ll INF = 1e16 + 5;
const int M = (1 << 7) + 5;

int n, p, k, id[N];
ll a[N], s[N][P], dp[N][M];

int main() {
  cin >> n >> p >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [] (int i, int j) {
    return a[i] > a[j];
  });
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < p; ++j) {
      scanf("%lld", s[i] + j);
    }
  }
  for (int mask = 1; mask < 1 << p; ++mask) {
    dp[0][mask] = -INF;
  }
  for (int i = 1; i <= n; ++i) {
    for (int mask = 0; mask < 1 << p; ++mask) {
      dp[i][mask] = (i - 1 - __builtin_popcount(mask) >= k ? 0 : a[id[i]]) + dp[i - 1][mask];
      for (int j = 0; j < p; ++j) if (mask & 1 << j) {
        dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ 1 << j] + s[id[i]][j]);
      } 
    }
  }
  cout << dp[n][(1 << p) - 1] << '\n';
  return 0;
}