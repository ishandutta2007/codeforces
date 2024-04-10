#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
std::vector<std::pair<int,int>> g[1 + nmax], grev[1 + nmax];
int idx[1 + nmax], lowlink[1 + nmax];

ll dp[1 + nmax], dp2[1 + nmax], cycle[1 + nmax];

int ptr = 0;
int in_stack[1 + nmax], head[1 + nmax];
int mark[1 + nmax];

std::vector<int> components, comp;

void dfs(int node){
  idx[node] = lowlink[node] = ++ptr;
  in_stack[node] = 1;
  comp.push_back(node);

  for(int i = 0 ; i < g[node].size() ;i++){
    int newnode = g[node][i].first;
    if(idx[newnode] == 0){
      dfs(newnode);
      lowlink[node] = std::min(lowlink[node] ,lowlink[newnode]);
    } else if(in_stack[newnode] == 1){
      lowlink[node] = std::min(lowlink[node] ,lowlink[newnode]);
    }
  }

  if(idx[node] == lowlink[node]){
    int newnode;
    head[idx[node]] = node;
    components.push_back(idx[node]);
    do{
      newnode = comp.back();
      mark[newnode] = idx[node];
      in_stack[newnode] = 0;
      comp.pop_back();
    } while(0 < comp.size() && newnode != node);
  }
}

void dfsmark(int node) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(mark[node] != mark[to])
      continue;
    if(to == head[mark[node]]) 
      cycle[mark[node]] = std::__gcd(dp[node] + g[node][h].second, cycle[mark[node]]);
    else if(0 == dp[to]) {
      dp[to] = dp[node] + g[node][h].second;
      dfsmark(to);
    }
  }
}

void dfsmark2(int node) {
  for(int h = 0; h < grev[node].size(); h++) {
    int to = grev[node][h].first;
    if(mark[node] != mark[to])
      continue;
    if(to == head[mark[node]]) 
      cycle[mark[node]] = std::__gcd(dp2[node] + grev[node][h].second, cycle[mark[node]]);
    else if(0 == dp2[to]) {
      dp2[to] = dp2[node] + grev[node][h].second;
      dfsmark2(to);
    }
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int a, b, l;
    std::cin >> a >> b >> l;
    g[a].push_back({b, l});
    grev[b].push_back({a, l});
  }

  for(int i = 1;i <= n; i++)
    if(idx[i] == 0) {
      dfs(i);
    }

  for(int h = 0; h < components.size(); h++) {
    int node = head[components[h]];
    dfsmark(node);
    dfsmark2(node);
  }


  for(int i = 1;i <= n; i++) {
    for(int h = 0; h < g[i].size(); h++) {
      int to = g[i][h].first;
      if(mark[i] == mark[to])
        cycle[mark[i]] = std::__gcd(cycle[mark[i]], dp[i] + g[i][h].second + dp2[to]);
    }
  }

  int q;
  std::cin >> q;
  for(int i = 1;i <= q; i++) {
    int start;
    ll init, modulo;
    std::cin >> start >> init >> modulo;
    if(init == 0)
      std::cout << "YES\n";
    else if(cycle[mark[start]] == 0) {
      std::cout << "NO\n";
    } else {
      init = (modulo - init) % modulo;
      if(init % std::__gcd(modulo, cycle[mark[start]]) == 0)
        std::cout << "YES\n";
      else
        std::cout << "NO\n";
    }
  }
  return 0;
}