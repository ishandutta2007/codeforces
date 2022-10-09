#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 200000;

class SegmentTree{
private:
  class Info{
    public:
    int count0;
    int count1;
    ll sum0;
    ll sum1;
    Info operator + (Info const oth) {
      return {count0 + oth.count0,
              count1 + oth.count1,
              sum0 + oth.sum0,
              sum1 + oth.sum1};
    }
  };

  std::vector<Info> aint;
  std::vector<int> lazy;

public:
  SegmentTree(int n = 0) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  
  void build(int node, int from, int to, int *aux) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, aux);
      build(node * 2 + 1, mid + 1, to, aux);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {1, 0, aux[from], 0};
  }
  
  void cleannode(int node, int from, int to) {
    if(lazy[node] == 0)
      return ;
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    std::swap(aint[node].count0, aint[node].count1);
    std::swap(aint[node].sum0, aint[node].sum1);
    lazy[node] = 0;
  }

  void update(int node, int from, int to, int x, int y) {
    if(from == x && to == y) {
      lazy[node] ^= 1;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid));
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }

  std::pair<int,ll> query() {
    return {aint[1].count1, aint[1].sum1};
  }
};

namespace HLD{
  std::vector<std::pair<int,int>> g[5 + nmax];
  int sz[5 + nmax];

  void computesz(int node, int parent) {
    sz[node] = 1;

    for(int h = 0; h < g[node].size(); h++)
      if(g[node][h].first == parent) {
        g[node].erase(g[node].begin() + h);
        break;
      }

    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      computesz(to, node);
      sz[node] += sz[to];
    }
  }
  
  bool compare(std::pair<int,int> x, std::pair<int,int> y) {
    return sz[x.first] < sz[y.first];
  }
  
  int pos[5 + nmax], id[5 + nmax], jumpfar[5 + nmax], far[5 + nmax], ptr = 0;

  void dfs(int node) {
    std::sort(g[node].begin(), g[node].end(), compare);
    std::reverse(g[node].begin(), g[node].end());
    
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      pos[to] = ++ptr;
      id[ptr] = g[node][h].second;
      far[to] = node;
      if(h == 0)
        jumpfar[to] = jumpfar[node];
      else
        jumpfar[to] = to;
      dfs(to);
    }
  }
  SegmentTree aint;
  int active[5 + nmax];
  
  int root;

  void buildHLD(int _root = 1) {
    root = _root;
    computesz(root, 0);
    jumpfar[root] = root;
    dfs(root);
    aint = SegmentTree(ptr);
    aint.build(1, 1, ptr, id);
    active[root] = 1;
  }
  
  void update(int node) {
    active[node] = 1;
    while(0 < pos[node]) {
      aint.update(1, 1, ptr, std::max(1, pos[jumpfar[node]]), pos[node]);
      node = far[jumpfar[node]]; 
    }
  }
  
  std::pair<int,ll> query() {
    return aint.query();
  }
 
  int explore(int node, std::vector<int> &ord) {
    int curr = 1;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      int id = g[node][h].second;
      if(active[to] == 1) {
        int temp = explore(to, ord);
        if(temp % 2 == 1)
          ord.push_back(id);
        curr += temp;
      }
    }
    return curr;
  }

  void printSolution() {
    std::vector<int> ord;
    explore(root, ord);
    std::sort(ord.begin(), ord.end());
    std::cout << ord.size() << " " ;
    for(int i = 0; i < ord.size(); i++)
      std::cout << ord[i] << " ";
    std::cout << std::endl;
  }
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    HLD::g[x].push_back({y, i});
    HLD::g[y].push_back({x, i});
  }
  HLD::buildHLD();
  ll last = 0;
  int activeNodes = 1;
  while(true) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int x;
      std::cin >> x;
      activeNodes++;
      HLD::update(x);
      std::pair<int,ll> sol = HLD::query();
      if(activeNodes % 2 == 1 || activeNodes < sol.first * 2) {
        last = 0;
        std::cout << 0 << std::endl; 
      } else {
        last = sol.second;
        std::cout << sol.second << std::endl;
      }
    } else if(op == 2){
      if(0 < last)
        HLD::printSolution();
      else
        std::cout << 0 << std::endl;
    } else
      return 0;
  }
  return 0;
}