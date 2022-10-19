#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
vector<pair<int, int>> G[N];
vector<int> A[N];
int sz[N], csz[2*N], cpar[N];
// sz[v] = size of subtree rooted at v
// csz[v] = size of color component of v

void dfs(int v, int p) {
  csz[v] = sz[v] = 1;
  for (auto& [u, x]: G[v]) {
    if (u == p) continue;
    cpar[u] = A[x].back();
    A[x].emplace_back(u);
    dfs(u, v);
    csz[cpar[u]] -= sz[u];
    sz[v] += sz[u];
    csz[v] += sz[u];
    A[x].pop_back();
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    G[u].emplace_back(v, x);
    G[v].emplace_back(u, x);
  }
  for (int i = 1; i <= n; i++) {
    A[i].emplace_back(i+n);
    csz[i+n] = n;
  }
  dfs(1, 1);

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1LL * csz[i] * csz[cpar[i]];
  }
  cout << ans << '\n';

}