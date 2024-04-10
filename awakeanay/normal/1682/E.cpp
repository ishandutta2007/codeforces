#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::pair<int, int> edges[m];
  std::vector<std::pair<int, int> > Adj[n];

  int p[n];
  for(int i = 0; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
  }

  std::vector<int> val(n, -1);
  std::vector<int> par(n, -1);
  for(int i = 0; i < n; i++) {
    if(val[i] != -1)
      continue;
    val[i] = 0;
    par[i] = -1;
    int cur = p[i];
    int ct = 1;
    while(val[cur] == -1) {
      val[cur] = ct++;
      par[cur] = i;
      cur = p[cur];
      par[i]--;
    }
  }

  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back({v, i});
    Adj[v].push_back({u, i});
  }

  std::vector<int> Adj2[m];
  std::vector<int> deg(m, 0);

  for(int i = 0; i < n; i++) {
    std::vector<std::pair<int, int> > help;
    int sz = (par[i] < 0 ? -par[i] : -par[par[i]]);
    for(auto j : Adj[i]) {
      int u = (val[j.first] - val[i] + sz)%sz;
      help.push_back({u, j.second});
    }

    std::sort(help.begin(), help.end());
    for(int j = 1; j < help.size(); j++) {
      deg[help[j].second]++;
      Adj2[help[j-1].second].push_back(help[j].second);
    }
  }

  std::queue<int> q;
  for(int j = 0; j < m; j++) {
    if(deg[j] == 0)
      q.push(j);
  }

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    std::cout << u+1 << " ";
    for(int j : Adj2[u]) {
      deg[j]--;
      if(deg[j] == 0)
        q.push(j);
    }
  }

  return 0;
}