#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;

int const nmax = 250000;
int const lgmax = 20;
std::vector<int> g[5 + nmax];
int far[1 + lgmax][5 + nmax], level[5 + nmax];

void dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      level[to] = level[node] + 1;
      far[0][to] = node;
      dfs(to, node);
    }
  }
}

void computefar(int n) {
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
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

int mult[5 + nmax];

int jump(int gala) {
  if(gala != mult[gala])
    mult[gala] = jump(mult[gala]);
  return mult[gala];
}

void unite(int gala, int galb) {
  gala = jump(gala);
  galb = jump(galb);
  mult[galb] = gala;
}
std::vector<int> g2[5 + nmax];

void solve(int node, int parent) {
  for(int h = 0; h < g2[node].size(); h++) {
    int to = g2[node][h];
    if(to != parent) {
      solve(to, node);
    }
  }

  if(parent != 0) {
    int x = node;
    int y = parent;
    int lca = getlca(x, y);
    if(level[lca] < level[jump(x)]) {
      x = jump(x);
      unite(far[0][x], x);
      std::cout << x << " " << far[0][x] << " " << node << " " << parent << '\n';
    } else {
      assert(level[lca] < level[jump(y)]);
      for(int h = lgmax; 0 <= h; h--) {
        if((1 << h) <= level[y] && level[lca] < level[jump(far[h][y])])
          y = far[h][y];
      }
      unite(far[0][y], y);
      std::cout << y << " " << far[0][y] << " " << node << " " << parent << '\n';
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  computefar(n);
  for(int i = 1; i <= n; i++)
    mult[i] = i;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g2[x].push_back(y);
    g2[y].push_back(x);
  }
  std::cout << n - 1 << '\n';
  solve(1, 0);
  return 0;
}