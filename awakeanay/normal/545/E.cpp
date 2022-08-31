#include <iostream>
#include <vector>
#include <set>

#define int long long

struct node
{
  int len, w, v, id;
};

struct compare {
  bool operator()(const node& a, const node& b) {
    if(a.len < b.len)
      return true;
    if(a.len == b.len && a.w < b.w)
      return true;
    if(a.len == b.len && a.w == b.w && a.id < b.id)
      return true;
    return false;
  }
};

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, std::pair<int, int> > > Adj[n];
  for(int i = 0; i < m; i++) {
    int a, b, w;
    std::cin >> a >> b >> w;
    a--; b--;
    Adj[a].push_back({b, {w, i} });
    Adj[b].push_back({a, {w, i} });
  }

  int u;
  std::cin >> u;
  u--;

  std::set<node, compare> dj;
  node init;
  init.v = u;
  init.len = init.w = 0;
  init.id = m;
  dj.insert(init);
  
  std::vector<int> vis(n, 0);
  int ans = 0;
  std::vector<int> mark(m+1, 0);

  while(!dj.empty()) {
    node cur = *dj.begin();
    dj.erase(dj.begin());
    //std::cout << cur.v << " " << cur.id << " " << cur.len << " " << cur.w << std::endl;

    if(vis[cur.v])
      continue;

    vis[cur.v] = true;
    mark[cur.id] = true;
    ans += cur.w;

    for(std::pair<int, std::pair<int, int> > j : Adj[cur.v]) {
      if(vis[j.first]) {
        continue;
      }

      node next;
      next.v = j.first;
      next.len = cur.len + j.second.first;
      next.w = j.second.first;
      next.id = j.second.second;
      dj.insert(next);
    }
  }

  std::cout << ans << std::endl;
  for(int i = 0; i < m; i++)
    if(mark[i])
      std::cout << i+1 << " ";
  std::cout << std::endl;

  return 0;
}