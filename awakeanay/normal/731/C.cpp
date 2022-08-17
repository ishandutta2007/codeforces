#include <iostream>
#include <set>
#include <vector>

#define int long long

#define MAXN 200005

int n, m, k;
std::vector<int> Adj[MAXN];
std::vector<int> vis(MAXN, false);
int c[MAXN];
int max = 0;
std::vector<int> cols(MAXN, 0);
std::set<int> cur;
int count = 0;

void dfs(int u, int p) {
  count++;
  vis[u] = true;
  cur.insert(u);
  cols[c[u]] += p;
  max = std::max(cols[c[u]], max);

  for(int v : Adj[u])
    if(!vis[v])
      dfs(v, p);
}

signed main() {
  std::cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
    std::cin >> c[i];

  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(vis[i])
      continue;
    
    max = 0;
    count = 0;
    dfs(i, 1);
    ans += count-max;
    while(!cur.empty()) {
      int u = *cur.begin();
      cur.erase(cur.begin());
      cols[c[u]]--;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}