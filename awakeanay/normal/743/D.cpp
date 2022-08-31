#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
#define MAXN 200005
#define INF 1000000000000000

int n;
std::vector<int> Adj[MAXN];
int a[MAXN];
int ans = -INF;
int sub[MAXN];

int dfs(int u, int p) {
  sub[u] = a[u];
  std::vector<int> ret;
  for(int v : Adj[u]) {
    if(v == p)
      continue;

    ret.push_back(dfs(v, u));
    sub[u] += sub[v];
  }

  int q = ret.size();
  if(q > 0) std::sort(ret.begin(), ret.end());
  if(ret.size() >= 2)
    ans = std::max(ans, ret[q-1] + ret[q-2]);

  return std::max(sub[u], q ? ret[q-1] : -INF);
}

signed main() {
  std::cin >> n;
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);

  if(ans == -INF)
    std::cout << "Impossible" << std::endl;
  else
    std::cout << ans << std::endl;

  return 0;
}