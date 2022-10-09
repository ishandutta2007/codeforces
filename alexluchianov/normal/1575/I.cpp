#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

class FenwickTree{
private:
  std::vector<ll> aib;
  int n;
public:
  FenwickTree(int n_) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }
  ll query(int pos) {
    ll result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};
int const nmax = 100000;
int const lgmax = 20;
int far[1 + lgmax][1 + nmax], level[1 + nmax];
std::vector<int> g[1 + nmax];
int start[1 + nmax], stop[1 + nmax];

int v[1 + nmax], ptr = 0;

void dfs(int node, int parent) {
  level[node] = level[parent] + 1;
  start[node] = ++ptr;
  far[0][node] = parent;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
    }
  }
  stop[node] = ptr;
}

void precompute(int n) {
  for(int h = 1; h < lgmax; h++)
    for(int i = 1; i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}

int getlca(int x, int y) {
  if(level[x] < level[y])
    std::swap(x, y);
  for(int h = lgmax - 1; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x]) {
      x = far[h][x];
    }
  if(x == y)
    return x;
  for(int h = lgmax - 1; 0 <= h; h--)
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
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    v[i] = std::max(v[i], -v[i]);
  }
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  precompute(n);
  FenwickTree aib(n);

  for(int i = 1;i <= n; i++) {
    aib.update(start[i], v[i]);
    aib.update(stop[i] + 1, -v[i]);
  }
  for(int i = 1;i <= q; i++) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if(op == 1) {
      int val = std::max(y, -y);
      aib.update(start[x], val - v[x]);
      aib.update(stop[x] + 1, -(val - v[x]));
      v[x] = val;
    } else {
      int lca = getlca(x, y);
      ll result = (aib.query(start[x]) + aib.query(start[y]) - 2 * aib.query(start[far[0][lca]]) - v[lca]) * 2 - v[x] - v[y];
      std::cout << result << '\n';
    }
  }
  return 0;
}