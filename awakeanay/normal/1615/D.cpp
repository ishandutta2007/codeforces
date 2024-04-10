#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

int par[MAXN];
int col[MAXN];
int actual[MAXN];
std::vector<std::pair<int, int> > Adj[MAXN];

int root(int x) {
  if(par[x] < 0)
    return x;
  int next = par[x];
  par[x] = root(par[x]);
  col[x] ^= col[next];
  return par[x];
}

int inc;

void merge(int u, int v, int p) {
  int x = root(u);
  int y = root(v);

  if(x == y) {
    if(col[u]^col[v]^p)
      inc = 1;
    return;
  }

  if(par[x] > par[y]) {
    x ^= y ^= x ^= y;
    u ^= v ^= u ^= v;
  }

  par[x] += par[y];
  col[y] = col[u]^col[v]^p;
  par[y] = x;
}

void dfs(int u, int p, int cur) {
  for(auto j : Adj[u]) {
    if(j.first == p)
      continue;

    if(j.second == -1) {
      root(u);
      root(j.first);
      int sum = __builtin_parity(cur)^col[u]^col[j.first];
      j.second = cur^sum;
    }

    std::cout << u+1 << " " << j.first+1 << " " << j.second << std::endl;
    dfs(j.first, u, cur^j.second);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    inc = 0;
    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      par[i] = -1;
      col[i] = 0;
      actual[i] = 0;
    }

    for(int i = 1; i < n; i++) {
      int u, v, w;
      std::cin >> u >> v >> w;
      u--; v--;
      Adj[u].push_back({v, w});
      Adj[v].push_back({u, w});

      if(w == -1)
        continue;

      int p = __builtin_parity(w);
      merge(u, v, p);
    }

    for(int i = 0; i < m; i++) {
      int u, v, p;
      std::cin >> u >> v >> p;
      u--; v--;
      merge(u, v, p);
    }

    if(inc) {
      std::cout << "NO" << std::endl;
      continue;
    }
    else {
      std::cout << "YES" << std::endl;
      dfs(0, -1, 0);
    }
  }

  return 0;
}