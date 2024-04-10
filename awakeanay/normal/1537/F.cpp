#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> Adj[MAXN];
int ch[MAXN];
int col[MAXN];
int bip;

void dfs(int u, int c) {
  col[u] = c;

  for(int j : Adj[u]) {
    if(col[j] == col[u])
      bip = false;
    else if(col[j] == 0) {
      dfs(j, 3-c);
      ch[u] -= ch[j];
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

    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      std::cin >> ch[i];
    }

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      col[i] = 0;
      ch[i] = x-ch[i];
    }

    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    bip = true;
    dfs(0, 1);

    if(((!bip) && ch[0]%2 == 0) || (ch[0] == 0)) {
      std::cout << "YES" << std::endl;
    }
    else
      std::cout << "NO" << std::endl;

  }

  return 0;
}