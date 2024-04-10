#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2010;
const int MOD = 1e9 + 7;

int n, m, a[N];
bitset <N> vis;
int dp[N << 1];  
vector <int> g[N];
int forw[N][N << 2];
int bacw[N][N << 2];

int main() {
  cin >> n >> m;
  int edges = m;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  m = 0;
  int sum = 0;
  for (int u : g[1]) if (!vis[u]) {
    int len = 1, at = u, prv = 1;
    while (at != 1) {
      ++len, vis[at] = 1; int tmp = at;
      at = (g[tmp][0] ^ prv ^ g[tmp][1]), prv = tmp;
    }
    a[++m] = len, sum += len;
  }
  assert(sum == edges);
  // for (int i = 1; i <= m; ++i) cout << a[i] << " "; cout << '\n';
  forw[0][edges] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= edges + edges; ++j) {
      forw[i][j] = forw[i - 1][j];
      if (j >= a[i]) {
        forw[i][j] += forw[i - 1][j - a[i]];
        if (forw[i][j] >= MOD) forw[i][j] -= MOD;
      }
      if (j + a[i] <= edges + edges) {
        forw[i][j] += forw[i - 1][j + a[i]];
        if (forw[i][j] >= MOD) forw[i][j] -= MOD;  
      }
    }
  }
  bacw[m + 1][edges] = 1;
  for (int i = m; i >= 1; --i) {
    for (int j = 0; j <= edges + edges; ++j) {
      bacw[i][j] = bacw[i + 1][j];
      if (j >= a[i]) {
        bacw[i][j] += bacw[i + 1][j - a[i]];
        if (bacw[i][j] >= MOD) bacw[i][j] -= MOD;
      }
      if (j + a[i] <= edges + edges) {
        bacw[i][j] += bacw[i + 1][j + a[i]];
        if (bacw[i][j] >= MOD) bacw[i][j] -= MOD;  
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j < a[i]; ++j) {
      int target = a[i] - j - j;
      for (int x = -edges; x <= edges; ++x) {
        if (target - x < -edges or target - x > edges) continue;
        ll cur = (ll) forw[i - 1][x + edges] * bacw[i + 1][target - x + edges] % MOD;
        ans += cur; if (ans >= MOD) ans -= MOD;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j + 1 < a[i]; ++j) {
      int target = a[i] - j - j - 1;
      for (int x = -edges; x <= edges; ++x) {
        if (target - x < -edges or target - x > edges) continue;
        ll cur = (ll) forw[i - 1][x + edges] * bacw[i + 1][target - x + edges] % MOD;
        ans += cur; if (ans >= MOD) ans -= MOD;
      }
    }
  }
  ans *= 2, ans %= MOD;
  dp[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = edges; j >= a[i]; --j) {
      dp[j] += dp[j - a[i]];
      if (dp[j] >= MOD) dp[j] -= MOD;
    }
  }
  if (edges & 1) {
    for (int i = 1; i <= m; ++i) {
      int val = a[i], target = 1 + (edges >> 1) - val;
      if (target < 0) continue;
      for (int j = val; j <= edges; ++j) {
        dp[j] -= dp[j - val];
        if (dp[j] < 0) dp[j] += MOD;
      }
      ans += 4LL * dp[target], ans %= MOD;
      for (int j = edges; j >= val; --j) {
        dp[j] += dp[j - val];
        if (dp[j] >= MOD) dp[j] -= MOD;
      }
    }
  } else ans += dp[edges >> 1]; ans %= MOD;
  cout << ans << '\n';
  return 0;
}