#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using ll = long long;

int const nmax = 300000;
int const sigma = 26;
std::vector<int> g[1 + nmax];
int v[5 + nmax], sol[1 + nmax];
char ch[5 + nmax];

int start[1 + 2 * nmax];
int sz[1 + 2 * nmax], trie[1 + 2 * nmax][1 + sigma];

namespace man{
  std::queue<int> q;
  int ptr = 0;
  int newNode() {
    if(q.size() == 0)
      return ++ptr;
    int node = q.front();
    q.pop();
    return node;
  }
  void eraseNode(int node) {
    if(0 < node) {
      for(int i = 0; i < sigma; i++)
        trie[node][i] = 0;
      q.push(node);
    }
  }
};

int join(int gala, int galb) {
  if(gala == 0 && galb == 0)
    return 0;
  else if(gala == 0)
    return galb;
  else if(galb == 0)
    return gala;
  else if(gala == galb) 
    return gala;
  else {
    assert(0 < gala);
    sz[gala] = 1;
    for(int i = 0; i < sigma; i++) {
      trie[gala][i] = join(trie[gala][i], trie[galb][i]);
      sz[gala] += sz[trie[gala][i]];
    }
    man::eraseNode(galb);
    return gala;
  }
}

void dfs(int node, int parent) {
  start[node] = man::newNode();
  sz[start[node]] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      sz[start[node]] -= sz[trie[start[node]][ch[to]]];
      trie[start[node]][ch[to]] = join(trie[start[node]][ch[to]], start[to]);
      sz[start[node]] += sz[trie[start[node]][ch[to]]];
    }
  }
  sol[node] = sz[start[node]] + v[node];
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  
  for(int i = 1;i <= n; i++){
    std::cin >> v[i];
  }

  for(int i = 1;i <= n; i++) {
    std::cin >> ch[i];
    ch[i] -= 'a';
  }

  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  
  int smax = 0, scount = 0;
  for(int i = 1;i <= n; i++) {
    if(smax < sol[i]) {
      smax = sol[i];
      scount = 1;
    } else if(smax == sol[i])
      scount++;
  }
  std::cout << smax << '\n' << scount << '\n';
  return 0;
}