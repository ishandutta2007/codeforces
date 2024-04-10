#include <iostream>
#include <vector>

const int MAXN = 100005;

std::vector<int> init[MAXN];
std::vector<int> finale[MAXN];
int val[MAXN];
std::vector<int> Adj[MAXN];

int n, k, sk;

void dfs1(int u, int p = -1) {
  init[u] = std::vector<int>(sk, 0);
  init[u][0] = val[u];
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs1(j, u);
    for(int i = 0; i < sk; i++) {
      init[u][(i+1)%sk] ^= init[j][i];
    }
  }
}

void dfs2(int u, int p) {
  for(int j : Adj[u]) {
    if(j == p)
      continue;

    for(int i = 0; i < sk; i++) {
      finale[j][(i+1)%sk] ^= finale[u][i]^init[j][(i-1+sk)%sk];
    }

    dfs2(j, u);
  }
}

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  std::cin >> n >> k;
  sk = 2*k;

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  for(int i = 0; i < n; i++)
    std::cin >> val[i];

  dfs1(0, -1);

  for(int i = 0; i < n; i++)
    finale[i] = init[i];

  dfs2(0, -1);

  for(int i = 0; i < n; i++) {
    int cur = 0;
    for(int j = k; j < sk; j++)
      cur ^= finale[i][j];

    if(cur == 0)
      std::cout << 0 << " ";
    else
      std::cout << 1 << " ";
  }

  std::cout << std::endl;

  return 0;
}