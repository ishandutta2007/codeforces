#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;

int const nmax = 500000;
std::vector<int> g[1 + nmax];

int sz[1 + nmax],  mult[1 + nmax];
int stop[1 + 2 * nmax], start[1 + 2 * nmax], nxt[1 + 2 * nmax], id[1 + 2 * nmax];

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
  mult[galb] = gala;
  sz[gala] += sz[galb];
  if(0 < start[gala]) {
    if(0 < start[galb]) {
      nxt[stop[gala]] = start[galb];
      stop[gala] = stop[galb];
    }
  } else {
    start[gala] = start[galb];
    stop[gala] = stop[galb];
  }
}

std::set<std::pair<int,int>> edges;
std::pair<int,int> query[1 + nmax];

void dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
  if(parent != 0 && jump(node) != jump(parent)) {
    int realname = jump(node);
    int target = start[realname];
    
    while(0 < target && jump(query[id[target]].first) == jump(query[id[target]].second))
      target = nxt[target];
    if(0 < target) {
      start[realname] = nxt[target];
      if(start[realname] == 0)
        stop[realname] = 0;
      std::cout << node << " " << parent << " " << query[id[target]].first << " " << query[id[target]].second << '\n';
      unite(query[id[target]].first, query[id[target]].second);
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
    if(y < x)
      std::swap(x, y);
    edges.insert({x, y});
  }
  for(int i = 1;i <= n; i++) {
    sz[i] = 1;
    mult[i] = i;
  }

  int ptr = 0;

  std::vector<std::pair<int,int>> fast;

  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    if(y < x)
      std::swap(x, y);
    if(edges.find({x, y}) == edges.end()) {
      nxt[++ptr] = start[x];
      start[x] = ptr;
      id[ptr] = i;
      if(0 == stop[x])
        stop[x] = ptr;

      nxt[++ptr] = start[y];
      start[y] = ptr;
      id[ptr] = i;
      if(0 == stop[y])
        stop[y] = ptr;
      query[i] = {x, y};
    } else
      fast.push_back({x, y});
  }

  for(int i = 0; i < fast.size(); i++) {
    int x = fast[i].first, y = fast[i].second;
    unite(x, y);
  }
  std::cout << n - 1 - fast.size() << '\n';
  dfs(1, 0 );
  return 0;
}