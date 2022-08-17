#include <iostream>
#include <queue>
#include <vector>
#include <set>

#define int long long

const int MAXN = 200005;
const int MOD = 1000000007;

std::vector<int> Adj[MAXN];

int d[MAXN];
int c[MAXN];
int b[MAXN];

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;

    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

void bfs(int u, int n) {
  for(int i = 0; i < n; i++) {
    d[i] = MAXN;
    c[i] = 0;
    b[i] = 0;
  }

  d[u] = 0;
  c[u] = 1;

  std::queue<int> bfs;
  std::vector<int> order;
  bfs.push(u);

  while(!bfs.empty()) {
    int u = bfs.front();
    order.push_back(u);
    bfs.pop();

    for(int j : Adj[u]) {
      if(d[j] == MAXN) {
        bfs.push(j);
        d[j] = d[u] + 1;
        c[j] = c[u];
      }
      else if(d[j] == d[u] + 1) {
        c[j] = (c[j] + c[u])%MOD;
      }
    }
  }

  for(int i : order) {
    for(int j : Adj[i]) {
      if(d[j] == d[i]) {
        b[i] += c[j];
      }
      else if(d[j] + 1 == d[i]) {
        b[i] += b[j];
      }
      b[i] %= MOD;
    }
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

    for(int i = 0; i < n; i++)
      Adj[i].clear();

    int s, t;
    std::cin >> s >> t;

    s--; t--;

    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    bfs(s, n);
    int ans = (c[t] + b[t])%MOD;

    std::cout << ans << std::endl;
  }

  return 0;
}