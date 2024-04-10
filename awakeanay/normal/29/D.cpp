#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAXN = 305;

int order[MAXN];
std::vector<int> Adj[MAXN];

int dfs1(int u, int p) {
  int min = MAXN;
  std::vector<std::pair<int, int> > children;

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    int next = dfs1(j, u);
    min = std::min(min, next);
    children.push_back({next, j});
  }

  std::sort(children.begin(), children.end());

  Adj[u].clear();
  for(auto j : children)
    Adj[u].push_back(j.second);

  if(min == MAXN)
    min = order[u];

  return min;
}

std::vector<int> ans;
int n;

void dfs2(int u, int p) {
  ans.push_back(u);
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs2(j, u);
    ans.push_back(u);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  int leaves = 0;
  for(int j = 1; j < n; j++)
    if(Adj[j].size() == 1)
      leaves++;

  std::vector<int> check;
  for(int i = 0; i < leaves; i++) {
    int x;
    std::cin >> x;
    x--;
    check.push_back(x);
    order[x] = i;
  }

  dfs1(0, -1);
  dfs2(0, -1);
  int ct = 0;
  for(int j : ans) {
    if(ct < check.size() && check[ct] == j)
      ct++;
  }
  if(ct == check.size()) {
    for(int j : ans)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }
  else
    std::cout << -1 << std::endl;

  return 0;
}