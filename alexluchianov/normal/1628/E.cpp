#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>

struct Edge{
  int x;
  int y;
  int w;
  bool operator < (Edge const oth) const {
    return w < oth.w;
  }
};

class Dsu{
private:
  std::vector<int> mult;
  std::vector<int> sz;
  std::vector<int> acc;
  std::vector<std::deque<int>> chain;
public:
  Dsu(int n) {
    mult.resize(1 + n);
    sz.resize(1 + n);
    acc.resize(1 + n);
    std::iota(mult.begin(), mult.end(), 0);
    std::fill(sz.begin(), sz.end(), 1);
    chain.resize(1 + n);
  }
  int jump(int gala) {
    if(gala != mult[gala]) {
      int target = jump(mult[gala]);
      if(target != mult[gala]) {
        acc[gala] += acc[mult[gala]];
        mult[gala] = mult[mult[gala]];
      }
    }
    return mult[gala];
  }
  void unite(int gala, int galb, int val) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    
    chain[gala].push_back(val);

    if(sz[gala] < sz[galb]) {
      for(;0 < chain[gala].size(); chain[gala].pop_back())
        chain[galb].push_front(chain[gala].back());
      std::swap(chain[gala], chain[galb]);
    } else {
      for(;0 < chain[galb].size(); chain[galb].pop_front())
        chain[gala].push_back(chain[galb].front());
    }

    sz[gala] += sz[galb];
    mult[galb] = gala;
    acc[galb] -= acc[gala];
  }

  void increase(int gala, int val) {
    gala = jump(gala);
    acc[gala] += val;
  }
  int getSize(int gala) {
    return sz[jump(gala)];
  }
  int getAcc(int gala) {
    jump(gala);
    if(gala != mult[gala])
      return acc[gala] + acc[mult[gala]];
    return acc[gala];
  }
  std::vector<int> getChain(int gala) {
    gala = jump(gala);
    return std::vector<int>(chain[gala].begin(), chain[gala].end());
  }
};

class SegmentTree{
private:
  std::vector<std::pair<int,int>> aint;
  std::vector<std::pair<int,int>> base;
  std::vector<int> lazy;
  std::pair<int,int> nullBase;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    base.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
    nullBase = {n + 1, 0};
    
    std::fill(aint.begin(), aint.end(), nullBase);
    std::fill(lazy.begin(), lazy.end(), 0);
  }
  std::pair<int,int> join(std::pair<int,int> f1, std::pair<int,int> f2) {
    return {std::min(f1.first, f2.first), std::max(f1.second, f2.second)};
  }
  
  void build(int node, int from, int to, std::vector<int> &aux) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, aux);
      build(node * 2 + 1, mid + 1, to, aux);
      base[node] = join(base[node * 2], base[node * 2 + 1]);
    } else
      base[node] = {aux[from], aux[from]};
  }

  void cleannode(int node, int from, int to) {
    if(lazy[node] == 0)
      return ;
    if(from < to) 
      lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
    if(lazy[node] == 1)
      aint[node] = base[node];
    else
      aint[node] = nullBase;
    lazy[node] = 0;
  }

  void update(int node, int from, int to, int x, int y, int val) {
    if(from == x && to ==y ) {
      lazy[node] = val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid  +1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    }
  }

  std::pair<int,int> query(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, to, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return join(query(node * 2, from, mid, x, mid),
                    query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

class RMQ{
private:
  std::vector<std::vector<int>> rmq;
  int lg(int number) {
    return 31 - __builtin_clz(number);
  }
public:
  RMQ(int n, std::vector<int> aux) {
    rmq.resize(1 + lg(n));
    for(int i = 0; i <= lg(n); i++)
      rmq[i].resize(1 + n);
    for(int i = 0; i < aux.size(); i++)
      rmq[0][i] = aux[i];
    for(int h = 1; h <= lg(n); h++)
      for(int i = 0; i < n - (1 << h); i++)
        rmq[h][i] = std::max(rmq[h - 1][i], rmq[h - 1][i + (1 << (h - 1))]);
  }
  int extract(int x, int y) {
    x--;
    y--;
    int h = lg(y - x + 1);
    return std::max(rmq[h][x], rmq[h][y - (1 << h) + 1]);
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  std::vector<Edge> edges;
  for(int i = 1;i < n; i++) {
    int x, y, w;
    std::cin >>  x >> y >> w;
    edges.push_back({x, y, w});
  }
  std::sort(edges.begin(), edges.end());
  Dsu dsu(n);
  for(int i = 0; i < edges.size(); i++) {
    int x = edges[i].x;
    int y = edges[i].y;
    dsu.increase(y, dsu.getSize(x));
    dsu.unite(x, y, edges[i].w);
  } 
  dsu.increase(1, 1);
  SegmentTree aint(1 + n);
  std::vector<int> aux(1 + n);
  for(int i = 1;i <= n; i++)
    aux[i] = dsu.getAcc(i);

  aint.build(1, 1, n, aux);
  RMQ rmq(n, dsu.getChain(1));


  for(int i = 1; i <= q; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int x, y;
      std::cin >> x >> y;
      aint.update(1, 1, n, x, y, 1);
    } else if(op == 2) {
      int x, y;
      std::cin >> x >> y;
      aint.update(1, 1, n, x, y, -1);
    } else {
      int target;
      std::cin >> target;
      target = dsu.getAcc(target);
      std::pair<int,int> sol = aint.query(1, 1, n, 1, n);
      int result = -1;

      if(sol.first < target) 
        result = std::max(result, rmq.extract(sol.first, target - 1));
      if(target < sol.second)
        result = std::max(result, rmq.extract(target, sol.second - 1));
      std::cout << result << '\n';
    }
  }
  return 0;
}