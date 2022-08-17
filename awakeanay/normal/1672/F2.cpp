#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> adj[MAXN];
std::vector<int> vis;

int avoid;
int cycle;

void dfs(int u) {
  vis[u] = 1;
  for(int j : adj[u]) {
    if(j == avoid)
      continue;
    if(vis[j] == 1)
      cycle = 1;
    if(!vis[j])
      dfs(j);
  }
  vis[u] = 2;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    vis = std::vector<int>(n, 0);

    int a[n];
    bool poss;
    std::vector<int> d(n, 0);
    int max = 0;
    for(int i = 0; i < n; i++) {
      adj[i].clear();
      std::cin >> a[i];
      d[a[i]-1]++;
      max = std::max(max, d[a[i]-1]);
    }

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      adj[a[i]-1].push_back(x-1);
    }

    for(int i = 0; i < n; i++) {
      if(d[i] == max) {
        cycle = 0;
        avoid = i;
        for(int j = 0; j < n; j++)
          if(vis[j] == 0 && j != avoid)
            dfs(j);
        poss = !cycle;
        break;
      }
    }

    std::cout << (poss ? "AC" : "WA") << std::endl;
  }

  return 0;
}