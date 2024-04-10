#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N];
int a[N], b[N], c[N], d[N];
long long ans;

void dfs(int v, int p) {
  a[v] = min(a[v], a[p]);
  int pos = 0;
  int neg = 0;
  d[v] = b[v]-c[v];
  if (d[v] > 0) pos++;
  else if (d[v] < 0) neg++;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    if (d[u] > 0) pos += d[u];
    else if (d[u] < 0) neg -= d[u];
    d[v] += d[u];
  }
  ans += 2LL*min(pos, neg)*a[v];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  ans = 0;
  dfs(1, 1);

  cout << (d[1] ? -1 : ans) << '\n';
}