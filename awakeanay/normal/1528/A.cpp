#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;

std::vector<int> Adj[MAXN];
int l[MAXN], r[MAXN];

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

std::pair<int, int> dfs(int u, int p) {
  std::pair<int, int> cur = {0, 0};
  for(int j : Adj[u]) {
    if(j == p)
      continue;

    std::pair<int, int> next = dfs(j, u);

    cur.first += std::max(abso(l[u]-l[j]) + next.first, abso(l[u]-r[j]) + next.second);
    cur.second += std::max(abso(r[u]-l[j]) + next.first, abso(r[u]-r[j]) + next.second);
  }

  return cur;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      std::cin >> l[i] >> r[i];
      Adj[i].clear();
    }

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    std::pair<int, int> next = dfs(0, -1);

    std::cout << std::max(next.first, next.second) << std::endl;
  }

  return 0;
}