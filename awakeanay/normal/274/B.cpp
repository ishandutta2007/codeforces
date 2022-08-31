#include <iostream>
#include <vector>

#define int long long
#define MAXN 100005

std::vector<int> Adj[MAXN];
int a[MAXN];

std::pair<int, int> dfs(int u, int p = -1) {
  std::pair<int, int> ret = {0, 0};
  int in = 0, out = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    std::pair<int, int> next = dfs(j, u);
    in = std::max(in, next.first);
    out = std::max(out, next.second);
  }
  ret.first = in;
  ret.second = out;
  int cur = a[u] + ret.first - ret.second;
  if(cur < 0)
    ret.first -= cur;
  else
    ret.second += cur;
  return ret;
}


signed main() {
  int n;
  std::cin >> n;

  for(int i = 1; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;
    Adj[a].push_back(b);
    Adj[b].push_back(a);
  }

  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::pair<int, int> ret = dfs(0);
  std::cout << ret.first + ret.second << std::endl;
  return 0;
}