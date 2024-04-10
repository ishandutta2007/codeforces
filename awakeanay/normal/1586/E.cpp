#include <iostream>
#include <stack>
#include <vector>

#define int long long

const int MAXN = 300005;

int par[MAXN];

int root(int x) {
  if(par[x] < 0)
    return x;
  return par[x] = root(par[x]);
}

std::stack<int> cur;
std::vector<std::stack<int> > ans;
std::vector<int> Adj[MAXN];
int deg[MAXN];
int count = 0;

void dfs(int u, int p, int s) {
  cur.push(u+1);
  if(s == u)
    ans.push_back(cur);
  for(int j : Adj[u]) {
    if(j != p)
      dfs(j, u, s);
  }
  cur.pop();
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);
  
  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++)
    par[i] = -1;

  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    if(root(u) == root(v))
      continue;
    merge(u, v);
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  int q;
  std::cin >> q;

  for(int i = 0; i < q; i++) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;
    if(deg[a])
      count--;
    else
      count++;
    if(deg[b])
      count--;
    else
      count++;
    deg[a] ^= 1;
    deg[b] ^= 1;
    dfs(b, -1, a);
  }

  if(count) {
    std::cout << "NO" << std::endl;
    std::cout << count/2 << std::endl;
  }
  else {
    std::cout << "YES" << std::endl;
    for(int i = 0; i < q; i++) {
      std::cout << ans[i].size() << std::endl;
      while(!ans[i].empty()) {
        std::cout << ans[i].top() << " ";
        ans[i].pop();
      }
      std::cout << std::endl;
    }
  }

  return 0;
}