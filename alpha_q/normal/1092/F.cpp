#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 200010;

vector <int> g[N];
int n; ll a[N], tot, sub[N], sum[N], ans;

void go (int u = 1, int from = -1) {
  sum[u] = a[u];
  for (int v : g[u]) if (v - from) {
    go(v, u);
    sum[u] += sum[v];
    sub[u] += sub[v] + sum[v];
  }
}

void dfs (int u = 1, int from = -1, ll now = sub[1]) {
  ans = max(ans, now);
  for (int v : g[u]) if (v - from) {
    dfs(v, u, now + tot - sum[v] - sum[v]);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    tot += a[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  go(); dfs();
  printf("%lld\n", ans);
  return 0;
}