#include <iostream>
#include <vector>
 
const int MAXN = 200005;
 
int anc[MAXN];
int par[MAXN];
int dep[MAXN];
int st[MAXN];
int pos[MAXN];
std::vector<int> Adj[MAXN];
int ct;
 
void dfs(int u, int p, int d) {
  pos[u] = ++ct;
  st[d] = u;
  par[u] = p;
  dep[u] = d;
  anc[u] = st[d-(d&(-d))];
 
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, d+1);
  }
}
 
int lca(int u, int v) {
  if(dep[v] > dep[u])
    u ^= v ^= u ^= v;
 
  while(dep[u] > dep[v]) {
    if(dep[anc[u]] >= dep[v])
      u = anc[u];
    else
      u = par[u];
  }
 
  while(u != v) {
    if(anc[u] != anc[v]) {
      u = anc[u];
      v = anc[v];
    }
    else {
      u = par[u];
      v = par[v];
    }
  }
 
  return u;
}

int dist(int u, int v) {
  return dep[u] + dep[v] - 2*dep[lca(u, v)];
}
 
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
 
  int n, q;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    Adj[i].clear();
 
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
 
  ct = -1;
  dfs(1, 0, 1);
  std::cin >> q;
 
  while(q--) {
    int k;
    std::cin >> k;

    std::pair<int, int> last = {-1, -1};
    int a[k];
    for(int i = 0; i < k; i++) {
      std::cin >> a[i];
      last = std::max(last, {pos[a[i]], a[i]});
    }

    std::pair<int, int> other = {-1, -1};
    for(int i = 0; i < k; i++) {
      other = std::max(other, {dist(last.second, a[i]), a[i]});
    }

    int u = last.second;
    int v = other.second;
    bool poss = true;
    for(int i = 0; i < k; i++) {
      poss &= dist(a[i], u) + dist(a[i], v) == dist(u, v);
    }

    std::cout << (poss ? "YES" : "NO") << "\n";
  }
 
  return 0;
}