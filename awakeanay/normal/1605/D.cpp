#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> bip[2];
std::vector<int> Adj[MAXN];

void dfs(int u, int p, int c) {
  bip[c].push_back(u);
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, c^1);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    bip[0].clear();
    bip[1].clear();
    for(int i = 0; i < n; i++)
      Adj[i].clear();

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    dfs(0, -1, 0);

    int lo = 0;
    int sz[2];
    for(int j = 0; j < 2; j++)
      sz[j] = bip[j].size();

    if(sz[1] < sz[0])
      lo = 1;

    int a = 0, b = 0;
    int ans[n];
    for(int i = 1; i <= n; i++) {
      int first = 0;
      for(int j = 0; j < 20; j++) {
        if((i >> j)&1)
          first = j;
      }

      if((sz[lo] >> first)&1) {
        ans[bip[lo][a++]] = i;
      }
      else {
        ans[bip[lo^1][b++]] = i;
      }
    }

    for(int i = 0; i < n; i++) {
      std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}