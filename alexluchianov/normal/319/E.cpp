#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;

int const nmax = 100000;

struct Query{
  int op;
  int x;
  int y;
} v[1 + nmax];

std::map<int,int> mp;

int normalize(int n) {
  std::vector<int> aux;
  for(int i = 1;i <= n; i++) {
    if(v[i].op == 1) {
      aux.push_back(v[i].x);
      aux.push_back(v[i].y);
    }
  }
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  
  for(int i = 0; i < aux.size(); i++)
    mp[aux[i]] = 1 + i;
  for(int i = 1;i <= n; i++) {
    if(v[i].op == 1) {
      v[i].x = mp[v[i].x];
      v[i].y = mp[v[i].y];
    }
  }
  return aux.size();
}

class Dsu{
private:
public:
  std::vector<int> mult;
  std::vector<int> l, r;
  Dsu(int n = 0) {
    mult.resize(1 + n);
    l.resize(1 + n);
    r.resize(1 + n);
  }
  
  void update(int node, int x, int y) {
    mult[node] = node;
    l[node] = x;
    r[node] = y;
  }

  int jump(int node) {
    if(node != mult[node]) 
      mult[node] = jump(mult[node]);
    return mult[node];
  }

  void unite(int gala, int galb) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    mult[galb] = gala;
    l[gala] = std::min(l[gala], l[galb]);
    r[gala] = std::max(r[gala], r[galb]);
  }
};

class SegmentTree{
private:
  std::vector<std::vector<int>> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void compress(int node, int from, int to, int x, int target, Dsu &dsu) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        compress(node * 2, from, mid, x, target, dsu);
      else
        compress(node * 2 + 1, mid + 1, to, x, target, dsu);
    }
    while(1 < aint[node].size()) {
      dsu.unite(target, aint[node].back());
      aint[node].pop_back();
    }
    if(1 == aint[node].size())
      dsu.unite(target, aint[node].back());
  }

  void update(int node, int from, int to, int x, int y, int target) {
    if(from == x && to == y)
      aint[node].push_back(target);
    else {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(mid, y), target);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, target);
    }
  }
};
std::pair<int,int> intervals[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i].op >> v[i].x >> v[i].y;
  int lim = normalize(n);

  Dsu dsu(n);
  SegmentTree aint(lim);
  int ptr = 0;
  
  for(int i = 1;i <= n; i++) {
    if(v[i].op == 1) {
      ++ptr;
      dsu.update(ptr, v[i].x, v[i].y);
      intervals[ptr] = {v[i].x, v[i].y};
      aint.compress(1, 1, lim, v[i].x, ptr, dsu);
      aint.compress(1, 1, lim, v[i].y, ptr, dsu);
      if(v[i].x + 1 <= v[i].y - 1)
        aint.update(1, 1, lim, v[i].x + 1, v[i].y - 1, ptr);
    } else {
      int x = v[i].x, y = dsu.jump(v[i].y);
      if(dsu.jump(x) == dsu.jump(y)) {
        std::cout << "YES\n";
      } else if(dsu.l[y] < intervals[x].first && intervals[x].first < dsu.r[y]) {
        std::cout << "YES\n";
      } else if(dsu.l[y] < intervals[x].second && intervals[x].second < dsu.r[y]) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }
  return 0;
}