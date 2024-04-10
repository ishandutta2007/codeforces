#include <iostream>
#include <stack>
#include <vector>

#define flag() (0)
#define par(x) (x+1)
#define opp(x) (n+1+x)

int n, m, q;
std::vector<int> dp;
std::vector<std::pair<int, int> > edges;
// dp[i] denotes the first number such that all edges excluding [i, dp[i]]
// form a bipartite graph. Not defined if edges [0, i-1] don't form bipartite
// graph. Calculated using DnC

struct bip
{
  std::vector<int> pers;
  std::stack<std::pair<int, int> > updates;
  std::stack<int> change;

  void update(int i, int j) {
    updates.push({i, pers[i]});
    pers[i] = j;
  }

  int root(int u) {
    while(pers[par(u)] >= 0)
      u = pers[par(u)];
    return u;
  }

  void merge(int u, int v) {
    if(!pers[flag()]) {
      change.push(0);
      return;
    }

    u = root(u);
    v = root(v);

    if(pers[opp(u)] == v) {
      change.push(0);
      return;
    }

    if(u == v) {
      update(flag(), 0);
      change.push(1);
      return;
    }

    int c = 0;

    int eu = pers[opp(u)];
    int ev = pers[opp(v)];

    //std::cout << u << " " << v << " " << eu << " " << ev << std::endl;
    if(ev != -1) {
      if(pers[par(ev)] < pers[par(u)])
        u ^= ev ^= u ^= ev;

      update(par(u), pers[par(ev)] + pers[par(u)]); c++;
      update(par(ev), u); c++;
    }
    
    if(eu != -1) {
      if(pers[par(eu)] < pers[par(v)])
        v ^= eu ^= v ^= eu;

      update(par(v), pers[par(eu)] + pers[par(v)]); c++;
      update(par(eu), v); c++;
    }

    update(opp(u), v); c++;
    update(opp(v), u); c++;

    change.push(c);
  }

  void undo() {
    int u = change.top();
    change.pop();
    while(u--) {
      std::pair<int, int> next = updates.top();
      updates.pop();
      pers[next.first] = next.second;
    }
  }
} graph;

void solve(int l, int r, int tl, int tr) {
  //std::cout << l << " " << r << " " << tl << " " << tr << std::endl;
  int mid = (l+r)/2;

  for(int i = l; i < mid; i++) {
    graph.merge(edges[i].first, edges[i].second);
    //std::cout << graph.pers[flag()] << std::endl;
  }

  int opt = tr;
  for(int i = tr; i > std::max(tl, mid); i--) {
    //std::cout << i << " ";
    graph.merge(edges[i].first, edges[i].second);
    //std::cout << graph.pers[flag()] << std::endl;
    if(graph.pers[flag()])
      opt = i-1;
  }

  dp[mid] = opt;
  //std::cout << mid << " " << opt << std::endl;

  for(int i = tr; i > std::max(tl, mid); i--)
    graph.undo();

  dp[mid] = opt;

  if(l == r) {
    for(int i = l; i < mid; i++)
      graph.undo();
    return;
  }

  graph.merge(edges[mid].first, edges[mid].second);
  solve(mid+1, r, opt, tr);
  for(int i = mid; i >= l; i--)
    graph.undo();

  if(l < mid) {
    for(int i = tr; i > opt; i--)
      graph.merge(edges[i].first, edges[i].second);
    solve(l, mid-1, tl, opt);
    for(int i = opt+1; i <= tr; i++)
      graph.undo();
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> m >> q;

  graph.pers = std::vector<int>(2*n+1, -1);
  graph.pers[flag()] = 1;
  edges.resize(m);

  int last = 0; // [0, last-1] is the largest interval corresponding to a bipartite graph
  for(int i = 0; i < m; i++) {
    std::cin >> edges[i].first >> edges[i].second;
    edges[i].first--; edges[i].second--;

    if(graph.pers[flag()])
      last = i;

    graph.merge(edges[i].first, edges[i].second);
  }

  dp.resize(last+1);

  for(int i = 0; i < m; i++)
    graph.undo();

  solve(0, last, 0, m-1);

  while(q--) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;

    if(l > last || r < dp[l])
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}