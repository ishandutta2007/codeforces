#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <set>

using ll = long long;

struct Edge{
  int x;
  int y;
  int cost;
  bool operator < (Edge const oth) {
    return cost < oth.cost;
  }
};
int const nmax = 200000;

namespace DSU{
  namespace Internal{
    int mult[5 + nmax];
    int sz[5 + nmax];

    int jump(int gala) {
      if(mult[gala] != gala)
        mult[gala] = jump(mult[gala]);
      return mult[gala];
    }
    void initialize(int n) {
      for(int i = 1;i <= n; i++) {
        mult[i] = i;
        sz[i] = 1;
      }
    }
    bool connected(int x, int y) {
      return jump(x) == jump(y);
    }
    void unite(int x, int y) {
      x = jump(x);
      y = jump(y);
      if(x == y)
        return ;
      if(sz[x] < sz[y])
        std::swap(x, y);
      mult[y] = x;
      sz[x] += sz[y];
      sz[y] = 0;
    }
  };

  int mult[5 + nmax];
  std::set<std::pair<int,int>> myset[5 + nmax];

  int jump(int gala) {
    if(mult[gala] != gala)
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }

  std::vector<Edge> internalEdges;

  std::set<std::pair<int,int>> forbidden;

  void initialize(int n, std::set<std::pair<int,int>> &alreadyEdges) {
    forbidden.clear();
    std::swap(forbidden, alreadyEdges);

    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++) {
      myset[i].clear();
      myset[i].insert({i, i});
    }
    Internal::initialize(n);
    internalEdges.clear();
  }

  bool valid(int x, int y) {
    if(y < x)
      std::swap(x, y);
    return forbidden.find({x, y}) == forbidden.end();
  }

  void append(std::set<std::pair<int,int>> &wset, std::pair<int,int> val, int cost) {
    val.first = Internal::jump(val.first);

    std::vector<int> addLater;
    std::set<std::pair<int,int>>::iterator it = wset.begin(), it2 = wset.end();
    it2--;

    while(it->first != it2->first) {
      if(it2->first != val.first) {
        std::pair<int,int> curr = *it2;
        wset.erase(it2--);
        curr.first = Internal::jump(curr.first);

        if(curr.first != val.first && valid(curr.second, val.second)) {
          Internal::unite(curr.first, val.first);
          internalEdges.push_back({curr.second, val.second, cost});
        }
        addLater.push_back(curr.second);
        val.first = Internal::jump(val.first);
      } else {
        std::pair<int,int> curr = *it;
        wset.erase(it++);
        curr.first = Internal::jump(curr.first);

        if(curr.first != val.first && valid(curr.second, val.second)) {
          Internal::unite(curr.first, val.first);
          internalEdges.push_back({curr.second, val.second, cost});
        }
        addLater.push_back(curr.second);
        val.first = Internal::jump(val.first);
      }
    }
    
    while(it != wset.end() && val.first != it->first) {
      std::pair<int,int> curr = *it;
      wset.erase(it++);
      curr.first = Internal::jump(curr.first);

      if(curr.first != val.first && valid(curr.second, val.second)) {
        Internal::unite(curr.first, val.first);
        internalEdges.push_back({curr.second, val.second, cost});
      }
      addLater.push_back(curr.second);
      val.first = Internal::jump(val.first);

    }

    for(const auto &to : addLater) 
      wset.insert({Internal::jump(to) , to});
    wset.insert({Internal::jump(val.first), val.second});
  }

  void unite(int x, int y, int cost) {
    x = jump(x);
    y = jump(y);

    if(x == y)  
      return ;

    if(myset[x].size() < myset[y].size())
      std::swap(x, y);
    for(const auto &it : myset[y]) {
      append(myset[x], it, cost);
    }

    myset[y].clear();
    mult[y] = x;
  }
};

namespace ShortestPath{
  int mult[5 + nmax];
  std::set<int> active[5 + nmax];

  int jump(int gala) {
    if(mult[gala] != gala)
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }

  void unite(int gala, int galb, int cost, std::vector<Edge> &queries) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    if(active[gala].size() < active[galb].size())
      std::swap(gala, galb);

    for(const auto &val : active[galb]) {
      std::set<int>::iterator it = active[gala].find(val);
      if(it != active[gala].end()) {
        queries[val].cost = cost;
        active[gala].erase(it);
      } else
        active[gala].insert(val);
    }

    mult[galb] = gala;
    active[galb].clear();
  }

  void initialize(int n, std::vector<Edge> &tree, std::vector<Edge> &queries) {
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      active[i].clear();

    for(int i = 0; i < queries.size(); i++) {
      active[queries[i].x].insert(i);
      active[queries[i].y].insert(i);
    }
    std::sort(tree.begin(), tree.end());
    for(int i = 0; i < tree.size(); i++) {
      int x = tree[i].x;
      int y = tree[i].y;
      int cost = tree[i].cost;
      unite(x, y, cost, queries);
    }
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Edge> edges(m);

  std::set<std::pair<int,int>> alreadyEdges;

  for(int i = 0; i < m; i++) { 
    std::cin >> edges[i].x >> edges[i].y >> edges[i].cost;
    if(edges[i].y < edges[i].x)
      std::swap(edges[i].x, edges[i].y);
    alreadyEdges.insert({edges[i].x, edges[i].y});
  }

  std::vector<int> id(m);
  std::iota(id.begin(), id.end(), 0);
  std::sort(id.begin(), id.end(), [&](int x, int y){return edges[x].cost < edges[y].cost;});

  DSU::initialize(n, alreadyEdges);

  for(const auto &it : id) {
    Edge e = edges[it];
    DSU::unite(e.x, e.y, e.cost);
  }

  std::vector<Edge> newEdges;
  std::swap(newEdges, DSU::internalEdges);

  ShortestPath::initialize(n, newEdges, edges);
  for(int i = 0; i < edges.size(); i++)
    std::cout << edges[i].cost << " ";
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}