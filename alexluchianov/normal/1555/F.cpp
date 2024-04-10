#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;

class DSU{
  private:
    std::vector<int> mult;
    std::vector<int> sz;
  public:
    DSU(int n) {
      mult.resize(1 + n);
      sz.resize(1 + n);
      std::fill(sz.begin(), sz.end(), 1);
      std::iota(mult.begin(), mult.end(), 0);
    }
    int jump(int gala) {
      if(mult[gala] != gala) 
        mult[gala] = jump(mult[gala]);
      return mult[gala];
    }
    void unite(int gala, int galb) {
      gala = jump(gala);
      galb = jump(galb);
      if(gala == galb)
        return ;
      if(sz[gala] < sz[galb])
        std::swap(gala, galb);
      sz[gala] += sz[galb];
      sz[galb] = 0;
      mult[galb] = gala;
    }
    bool connected(int gala, int galb) {
      return jump(gala) == jump(galb);
    }
};

class FenwickTree{
  private:
    std::vector<int> aib;
  public:
    FenwickTree(int n) {
      aib.resize(1 + n);
    }
    void update(int pos, int val) {
      for(int x = pos; x < aib.size(); x += (x ^ (x & (x - 1))))
        aib[x] += val;
    }
    int query(int pos) {
      int result = 0;
      for(int x = pos; 0 < x; x = (x & (x - 1)))
        result += aib[x];
      return result;
    }
};

struct Edge{
  int x;
  int y;
  int cost;
};

int const nmax = 300000;
int const lgmax = 20;

std::vector<std::pair<int,int>> g[5 + nmax];
int level[5 + nmax], start[5 + nmax], stop[5 + nmax];
int far[1 + lgmax][5 + nmax], path[5 + nmax];

void computefar(int n) {
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}

void dfs(int node, int &ptr) {
  start[node] = ++ptr;
  for(const auto &e : g[node]) {
    if(level[e.first] == 0) {
      level[e.first] = level[node] + 1;
      far[0][e.first] = node;
      path[e.first] = (path[node] ^ e.second);
      dfs(e.first, ptr);
    }
  }
  stop[node] = ptr;
}

int get_lca(int x, int y) {
  if(level[x] < level[y])
    std::swap(x, y);
  for(int h = lgmax; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax; 0 <= h; h--)
    if(far[h][x] != far[h][y]) {
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  DSU dsu(n);
  std::vector<Edge> edges(q);
  for(int i = 0;i < q; i++)
    std::cin >> edges[i].x >> edges[i].y >> edges[i].cost;
  std::vector<int> answer(q);

  for(int i = 0; i < q; i++) {
    if(dsu.connected(edges[i].x, edges[i].y) == 0) { 
      dsu.unite(edges[i].x, edges[i].y);
      answer[i] = 1;
      g[edges[i].x].push_back({edges[i].y, edges[i].cost});
      g[edges[i].y].push_back({edges[i].x, edges[i].cost});
    }
  }

  int ptr = 0;
  for(int i = 1;i <= n; i++)
    if(level[i] == 0) {
      level[i] = 1;
      dfs(i, ptr);
    }
  computefar(n);
  FenwickTree aib(n);
  
  auto is_valid = [&](int x, int y, int cost) {
    int lca = get_lca(x, y);
    
    if((path[x] ^ path[y] ^ cost) == 1) {
      if((aib.query(start[x]) + aib.query(start[y]) - aib.query(start[lca]) * 2) == 0)
        return true;
    } 
    return false;
  };

  for(int i = 0; i < q; i++) {
    if(answer[i] == 0) {
      Edge e = edges[i];
      if(is_valid(e.x, e.y, e.cost) == 1) {
        answer[i] = 1;
        while(e.x != e.y) {
          if(level[e.x] < level[e.y])
            std::swap(e.x, e.y);
          
          aib.update(start[e.x], 1);
          aib.update(stop[e.x] + 1, -1);
          e.x = far[0][e.x];
        }
      }
    }
  }
  
  auto formatOutput = [&](int val) {
    if(val == 1) 
      return "YES";
    else
      return "NO";
  };

  for(int i = 0; i < q; i++)
    std::cout << formatOutput(answer[i]) << '\n';
  return 0;
}