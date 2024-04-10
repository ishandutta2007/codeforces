#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
std::vector<int> g[1 + nmax];
std::vector<int> adj[1 + nmax];

int mex(std::vector<int> &aux) {
  std::sort(aux.begin(), aux.end());
  for(int i = 0; i < aux.size(); i++)
    if(aux[i] != (i + 1))
      return i + 1;
  return aux.size() + 1;
}
int seen[1 + nmax];

int dfs(int node, int parent, std::vector<std::vector<int>> &mult) {
  std::vector<int> aux;
  aux.push_back(node);
  seen[node] = 1;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      if(1 == dfs(to, node, mult))
        aux.push_back(to);
    }
  }
  if(1 < aux.size()) {
    mult.push_back(aux);
    return 0;
  } else {
    return 1;
  }
}

int sol[2][1 + nmax];

void solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    adj[i].clear();
    g[i].clear();
    adj[i].push_back(i);
  }

  for(int i = 1;i <= m; i++) {
    int l, r;
    std::cin >> l >> r;
    adj[l].push_back(r);
    adj[r].push_back(l);
  }
  
  for(int i = 1;i <= n; i++)
    if(adj[i].size() < n && 0 == g[i].size()) {
      int x = i, y = mex(adj[i]);
      g[x].push_back(y);
      g[y].push_back(x);
    }
  
  for(int i = 1;i <= n; i++)
    seen[i] = 0;
  
  std::vector<std::vector<int>> mult;
  
  for(int i = 1;i <= n; i++)
    if(0 < g[i].size() && seen[i] == 0) {
      if(dfs(i, 0, mult) == 1) 
        mult.back().push_back(i);
    } else if(0 == g[i].size() && seen[i] == 0) {
      mult.push_back({i});
      seen[i] = 1;
    }
  
  int ptr = 0;
  for(int i = 0; i < mult.size(); i++) {
    sol[1][mult[i][0]] = ptr + mult[i].size();
    for(int j = 1;j < mult[i].size(); j++) 
      sol[1][mult[i][j]] = ptr + j;
    for(int j = 0; j < mult[i].size(); j++) 
      sol[0][mult[i][j]] = ++ptr;
  }

  for(int i = 1; i <= n; i++)
    std::cout << sol[0][i] << " ";
  std::cout << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << sol[1][i] << " ";
  std::cout << '\n';
}

int main() {
  /*
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  */

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  
  return 0;
}