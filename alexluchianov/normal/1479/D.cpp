#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>
#include <random>
#include <chrono>

using ll = long long;

int const nmax = 300000;
int const lgmax = 20;

ll const inf = 1000000000000000000;

std::mt19937 rnd(std::chrono::high_resolution_clock().now().time_since_epoch().count());

ll myrand() {
  return std::uniform_int_distribution<ll>(0, inf)(rnd);
}

int v[1 + nmax];
std::set<ll> used;
ll id[1 + nmax];
std::vector<int> g[1 + nmax];

class FenwickTree{
private:
  std::vector<ll> aib;
  int n;
public:
  FenwickTree(int n_ = 0) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, ll val) {
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] ^= val;
  }
  ll query(int pos) {
    ll result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result ^= aib[x];
    return result;
  }
};

int start[1 + nmax], stop[1 + nmax], ptr = 0;
int sol[1 + nmax], level[1 + nmax], far[1 + lgmax][1 + nmax];

void dfs(int node) {
  start[node] = ++ptr;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(start[to] == 0) {
      level[to] = level[node] + 1;
      far[0][to] = node;
      dfs(to);
    }
  }
  stop[node] = ptr;
}

int getlca(int x, int y) {
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

struct Query{
  int x;
  int y;
  int lca;
  int l;
  int r;
  int id;
};

FenwickTree aib;
std::vector<int> frec[1 + nmax];

void divide(int from, int to, std::vector<Query> queries) {
  for(int i = from; i <= to; i++) {
    for(int h = 0; h < frec[i].size(); h++) {
      int pos = frec[i][h];
      aib.update(start[pos], id[i]);
      aib.update(stop[pos] + 1, id[i]);
    }
  }
  int mid = (from + to) / 2;
  std::vector<Query> queriesleft, queriesright; 
  for(int i = 0; i < queries.size(); i++) {
    Query e = queries[i];
    
    if(sol[e.id] == -1) {
      if(e.l == from && e.r == to) {
        ll key = aib.query(start[e.x]) ^ aib.query(start[e.y]);
        if(e.l <= v[e.lca] && v[e.lca] <= e.r)
          key ^= id[v[e.lca]];

        if(from == to) {
          if(0 < key)
            sol[e.id] = from;
        } else if(0 < key){
          queriesleft.push_back({e.x, e.y, e.lca, e.l, mid, e.id});
          queriesright.push_back({e.x, e.y, e.lca, mid + 1, e.r, e.id});
        }
      } else {
        if(e.l <= mid)
          queriesleft.push_back({e.x, e.y, e.lca, e.l, std::min(mid, e.r), e.id});
        if(mid + 1 <= e.r)
          queriesright.push_back({e.x, e.y, e.lca, std::max(e.l, mid + 1), e.r, e.id});
      }
    }
  }
  for(int i = from; i <= to; i++) {
    for(int h = 0; h < frec[i].size(); h++) {
      int pos = frec[i][h];
      aib.update(start[pos], id[i]);
      aib.update(stop[pos] + 1, id[i]);
    }
  }
  
  if(from < to) {
    divide(from, mid, queriesleft);
    divide(mid + 1, to, queriesright);
  }

}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  aib = FenwickTree(n);

  for(int i = 1;i <= n; i++) {
    while(true) {
      ll val = myrand();
      if(used.find(val) == used.end()) {
        used.insert(val);
        id[i] = val;
        break;
      }
    }
  }

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    frec[v[i]].push_back(i);
  }

  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  level[1] = 1;
  dfs(1);
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1; i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];

  std::vector<Query> queries;
  for(int i = 1;i <= q; i++) {
    int x, y, l, r;
    std::cin >> x >> y >> l >> r;
    queries.push_back({x, y, getlca(x, y), l, r, i});
    sol[i] = -1;
  }
  
  divide(1, n, queries);

  for(int i = 1;i <= q; i++)
    std::cout << sol[i] << '\n';
  return 0;
}