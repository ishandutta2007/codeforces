#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;

int const nmax = 100000;
int const inf = 1000000000;

class SegmentTree{
private:
  std::vector<int> aint;
public:
  SegmentTree(int n = 0) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = std::min(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }
  int query(int node, int from, int to, int x, int y) {
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return std::min(query(node * 2, from, mid, x, mid),
                        query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

class Tree{
private:
  std::vector<std::vector<int>> g;
  std::vector<int> start, stop;
  std::vector<int> sz, level, far, farbig;
  SegmentTree aint;
  int n;
public:
  
  void computesz(int node, int parent) {
    sz[node] = 1;
    level[node] = level[parent] + 1;
    far[node] = parent;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(to != parent) {
        computesz(to, node);
        sz[node] += sz[to];
      }
    }
  }
  
  void dfs(int node, int parent, int &ptr) {
    start[node] = ++ptr;
    int son = 0;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(to != parent && sz[son] < sz[to])
        son = to;
    }
    if(0 < son) {
      farbig[son] = farbig[node];
      dfs(son, node, ptr);
    }
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(to != parent && to != son) {
        farbig[to] = to;
        dfs(to, node, ptr);
      }
    }
    stop[node] = ptr;
  }

  Tree(int n_, std::vector<std::pair<int,int>> &edges) {
    n = n_;
    assert(edges.size() == n - 1);
    g.resize(1 + n);
    start.resize(1 + n);
    stop.resize(1 + n);
    sz.resize(1 + n);
    level.resize(1 + n);
    farbig.resize(1 + n);
    far.resize(1 + n);

    for(int i = 0; i < edges.size(); i++) {
      int x, y;
      x = edges[i].first;
      y = edges[i].second;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    computesz(1, 0);
    int ptr = 0;
    farbig[1] = 1;
    dfs(1, 0, ptr);
    aint = SegmentTree(n);
  }
  
  int getlevel(int node) {
    return level[node];
  }

  int getfather(int node) {
    return far[node];
  }

  void update(int node, int val) {
    aint.update(1, 1, n, start[node], val);
  }
  
  std::pair<int,int> query(int x, int y) {
    int result = inf;
    while(x != y) {
      if(farbig[x] == farbig[y]) {
        if(level[x] < level[y])
          std::swap(x, y);
        result = std::min(result, aint.query(1, 1, n, start[y], start[x]));
        x = y;
      } else {
        if(level[farbig[x]] < level[farbig[y]])
          std::swap(x, y);
        result = std::min(result, aint.query(1, 1, n, start[farbig[x]], start[x]));
        x = far[farbig[x]];
      }
    }
    return {x, std::min(result, aint.query(1, 1, n, start[x], start[x]))};
  }
};

std::vector<int> g[1 + nmax];
std::vector<int> comp[1 + nmax];
int v[1 + nmax];
int level[1 + nmax], up[1 + nmax], group[1 + nmax];

void computeup(int node, int parent) {
  up[node] = level[node];
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      if(level[to] == 0) {
        level[to] = level[node] + 1;
        computeup(to, node);
        up[node] = std::min(up[node], up[to]);
      } else 
        up[node] = std::min(up[node], level[to]);
    }
  }
}

void makepartition(int node, int parent, int &ptr) {
  if(up[node] + 1 < level[node]) {
    group[node] = group[parent];
  } else
    group[node] = ++ptr;
  comp[group[node]].push_back(node);

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(level[node] + 1 == level[to]) {
      makepartition(to, node, ptr);
      if(up[to] == level[node])
        comp[group[to]].push_back(node);
    }
  }
}
std::multiset<int> myset[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m >> q;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int ptr = 0;
  level[1] = 1;
  computeup(1, 0);
  makepartition(1, 0, ptr);
  
  std::vector<std::pair<int,int>> edges;

  for(int i = 1;i <= ptr; i++) 
    for(int j = 0; j < comp[i].size(); j++)
      edges.push_back({n + i, comp[i][j]});
  for(int i = 1;i <= n; i++)
    for(int h = 0; h < g[i].size(); h++) {
      int to = g[i][h];
      if(level[i] + 1 == level[to] && up[to] == level[to])
        edges.push_back({i, to});
    }

  Tree tree(n + ptr, edges);
  for(int i = 1; i <= n; i++)
    tree.update(i, v[i]);
  for(int i = 1;i <= ptr; i++) {
    myset[i].insert(inf);
    for(int h = 0; h < comp[i].size(); h++) {
      int to = comp[i][h];
      if(tree.getfather(to) == (n + i))
        myset[i].insert(v[to]);
    }
    tree.update(n + i, *myset[i].begin());
  }

  for(int i = 1;i <= q; i++) {
    char op;
    int x, y;
    std::cin >> op >> x >> y;
    if(op == 'C') {
      int to = tree.getfather(x);
      if(n < to) 
        myset[to - n].erase(myset[to - n].find(v[x]));
      v[x] = y;

      if(n < to) {
        myset[to - n].insert(v[x]);
        tree.update(to, *myset[to - n].begin());
      }
      tree.update(x, v[x]);
    } else {
      std::pair<int,int> sol = tree.query(x, y);

      if(n < sol.first) {
        int to = tree.getfather(sol.first);
        if(to <= n)
          sol.second = std::min(sol.second, v[to]);
      }
      std::cout << sol.second << '\n';
    }
  }
  return 0;
}