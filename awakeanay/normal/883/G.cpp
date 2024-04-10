#include <iostream>
#include <queue>
#include <vector>

#define int long long

const int MAXN = 300005;

std::vector<int> Adj[MAXN], Au[MAXN];
std::vector<std::pair<int, int> > unor;
int search[MAXN];
int vis2;

void dfs(int u) {
  search[u] = true;
  vis2++;

  for(int j : Adj[u]) {
    if(!search[j])
      dfs(j);
  }
}

signed main() {
  int n, m, s;
  std::cin >> n >> m >> s;

  s--;
  for(int i = 0; i < m; i++) {
    int t, u, v;
    std::cin >> t >> u >> v;
    u--; v--;
    Au[u].push_back(v);
    if(t == 1) {
      Adj[u].push_back(v);
    }
    else {
      Au[v].push_back(u);
      unor.push_back({u, v});
    }
  }

  std::queue<int> bfsq;
  bfsq.push(s);
  int vis = 0;
  std::vector<int> d(n, 2*n+5);
  d[s] = 0;
  while(!bfsq.empty()) {
    vis++;
    int u = bfsq.front();
    bfsq.pop();

    for(int j : Au[u]) {
      if(d[j] == 2*n+5) {
        d[j] = d[u] + 1;
        bfsq.push(j);
      }
    }
  }

  std::cout << vis << std::endl;
  for(int i = 0; i < unor.size(); i++) {
    if(d[unor[i].first] < d[unor[i].second])
      std::cout << '+';
    else
      std::cout << '-';
  }

  std::cout << std::endl;
  dfs(s);

  std::cout << vis2 << std::endl;
  for(int i = 0; i < unor.size(); i++) {
    if(search[unor[i].first] && (!search[unor[i].second]))
      std::cout << '-';
    else
      std::cout << '+';
  }

  std::cout << std::endl;

  return 0;
}