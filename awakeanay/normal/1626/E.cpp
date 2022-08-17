#include <iostream>
#include <queue>
#include <vector>

#define int long long

const int MAXN = 300005;

int bit1[MAXN], bit2[MAXN];

void add(int x, int v, int bit[]) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x, int bit[]) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

int sum(int l, int r, int bit[]) {
  return sum(r, bit)-sum(l-1, bit);
}

int stim[MAXN], etim[MAXN];
int par[MAXN];
std::vector<int> Adj[MAXN];
std::vector<int> Adj2[MAXN];
int c[MAXN];
int b[MAXN];
int ct = -1;

void dfs(int u, int p) {
  par[u] = p;
  stim[u] = ++ct;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
  }
  etim[u] = ct;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++)
    std::cin >> c[i];

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  dfs(0, -1);

  int tot = 0;
  for(int i = 0; i < n; i++) {
    if(c[i]) {
      b[i] = 1;
      tot++;
      add(stim[i], 1, bit1);
      for(int j : Adj[i])
        b[j] = 1; 
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j : Adj[i]) {
      if(j == par[i])
        continue;

      int st = sum(stim[j], etim[j], bit1);
      if(st > 1) {
        Adj2[j].push_back(i);
      }
    }

    if(par[i] == -1)
      continue;

    int st = sum(stim[i], etim[i], bit1);
    if(tot-st > 1) {
      Adj2[par[i]].push_back(i);
    }
  }

  std::vector<int> dist(n, 0);
  std::queue<int> bfs;
  for(int i = 0; i < n; i++) {
    if(b[i]) {
      bfs.push(i);
      dist[i] = 1;
    }
  }

  while(!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();

    for(int j : Adj2[u]) {
      if(dist[j] == 0) {
        dist[j] = 1;
        bfs.push(j);
      }
    }
  }

  for(int i = 0; i < n; i++)
    std::cout << dist[i] << " ";
  std::cout << std::endl;
  
  return 0;
}