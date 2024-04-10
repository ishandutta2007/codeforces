#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;

int const lgmax = 20;
int const nmax = 100000;
std::vector<std::pair<int,int>> g[1 + nmax];
int start[1 + nmax], rev[1 + nmax], ptr = 0;
int level[1 + nmax], far[1 + lgmax][1 + nmax];
ll dist[1 + nmax];

void dfs(int node, int parent) {
  start[node] = ++ptr;
  rev[ptr] = node;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent) {
      level[to] = level[node] + 1;
      far[0][to] = node;
      dist[to] = dist[node] + g[node][h].second;
      dfs(to, node);
    }
  }
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
  x = far[0][x];
  return x;
}

ll getdist(int a, int b) {
  int lca = getlca(a, b);
  return dist[a] + dist[b] - dist[lca] * 2;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  dfs(1, 0);
  for(int h = 1; h < lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
  int q;

  std::cin >> q;
  std::set<int> myset;

  ll result = 0;

  for(int i = 1;i <= q; i++) {
    char op;
    int x;
    std::cin >> op;
    if(op == '+') {
      std::cin >> x;
      myset.insert(start[x]);
      std::set<int>::iterator it = myset.find(start[x]), it2;
      it2 = it;
      it++;
      if(it == myset.end())
        it = myset.begin();
      if(it2 == myset.begin())
        it2 = myset.end();
      it2--;
      result += getdist(rev[*it], x) + getdist(rev[*it2], x) - getdist(rev[*it], rev[*it2]);
    } else if(op == '-') {
      std::cin >> x;
      std::set<int>::iterator it = myset.find(start[x]), it2;
      it2 = it;
      it++;
      if(it == myset.end())
        it = myset.begin();
      if(it2 == myset.begin())
        it2 = myset.end();
      it2--;
      myset.erase(start[x]);
      if(0 < myset.size()) {
        result -= getdist(rev[*it], x) + getdist(rev[*it2], x) - getdist(rev[*it], rev[*it2]);
      }
    } else
      std::cout << result / 2 << '\n';
  }
  return 0;
}