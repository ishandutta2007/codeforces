#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> g[N];
int t, n, bound, h[N], dp[N];

void go (int u = 1, int par = -1, int far = 0) {
  h[u] = far;
  for (int v : g[u]) if (v ^ par) go(v, u, far + 1);
}

void dfs (int u = 1, int par = -1) {
  if (u > 1 and g[u].size() == 1) {
    dp[u] = h[u]; return;
  }
  int cur = bound + h[u] - 1, bad = 0;
  for (int v : g[u]) if (v ^ par) {
    dfs(v, u);
    if (dp[v] > cur) ++bad;
  }
  dp[u] = 69696969;
  if (bad > 1) return;
  if (bad == 1) {
    for (int v : g[u]) if (v ^ par) {
      if (dp[v] > cur) {
        dp[u] = dp[v];
        break;
      }
    }
    return;
  }
  assert(!bad);
  for (int v : g[u]) if (v ^ par) {
    dp[u] = min(dp[u], dp[v]);
  }
}

bool ok (int up) {
  bound = up; dfs(); return dp[1] <= up;
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    go();
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = lo + hi >> 1;
      if (ok(mid)) hi = mid;
      else lo = mid + 1;
    }
    printf("%d\n", lo);
  }
  return 0;
}