#include <iostream>
#include <vector>

#define int long long

const int MAXN = 300005;

std::vector<std::pair<int, int> > Adj[MAXN];
std::vector<int> comp[MAXN];
int par[MAXN];
std::vector<int> ans;
int eval[MAXN];

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u];
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  eval[u] += eval[v];
  while(comp[v].size()) {
    comp[u].push_back(comp[v].back());
    par[comp[v].back()] = u;
    comp[v].pop_back();
  }

  while(Adj[v].size()) {
    Adj[u].push_back(Adj[v].back());
    Adj[v].pop_back();
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, x;
  std::cin >> n >> m >> x;

  int sum = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> eval[i];
    eval[i] -= x;
    sum += eval[i];
    par[i] = -1;
    comp[i].push_back(i);
  }

  if(sum + x < 0) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  std::cout << "YES" << std::endl;

  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back({v, i+1});
    Adj[v].push_back({u, i+1});
    par[u]--; par[v]--;
  }

  for(int i = 0; i < n; i++) {
    while(eval[root(i)] >= 0 && Adj[root(i)].size()) {
      int u = root(i);
      std::pair<int, int> j = Adj[u].back();
      Adj[u].pop_back();
      par[u]++;
      if(u != root(j.first)) {
        ans.push_back(j.second);
        merge(u, j.first);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(std::pair<int, int> j : Adj[i]) {
      if(root(j.first) != root(i)) {
        merge(j.first, i);
        ans.push_back(j.second);
      }
    }
  }

  for(int j : ans)
    std::cout << j << std::endl;

  return 0;
}