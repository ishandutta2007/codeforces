#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

#define MAXN 100005

std::set<int> Adj[MAXN];
int p[MAXN];
int hmax, cur;

void dfs(int u, int h) {
  if(h > hmax) {
    cur = u;
    hmax = h;
  }
  
  for(auto it = Adj[u].begin(); it != Adj[u].end(); it++)
    dfs(*it, h+1);
}

signed main() {
  int n;
  std::cin >> n;

  for(int i = 1; i < n; i++) {
    std::cin >> p[i];
    Adj[p[i]].insert(i);
  }

  dfs(0, 1);

  std::vector<int> moves;
  while(cur) {
    if(Adj[p[cur]].size() > 1) {
      moves.push_back(cur);
      int next = *Adj[p[cur]].begin() == cur ? *Adj[p[cur]].rbegin() : *Adj[p[cur]].begin();
      Adj[p[cur]].erase(cur);
      Adj[next].insert(cur);
      p[cur] = next;
    }
    else
      cur = p[cur];
  }

  while(true) {
    std::cout << cur << " ";
    if(!Adj[cur].size())
      break;
    cur = *Adj[cur].begin();
  }
    
  std::reverse(moves.begin(), moves.end());

  std::cout << std::endl << moves.size() << std::endl;
  for(int j : moves)
    std::cout << j << " ";
  
  std::cout << std::endl;

  return 0;
}