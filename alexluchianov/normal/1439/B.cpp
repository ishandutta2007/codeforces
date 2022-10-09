#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>

using ll = long long;

int const nmax = 100000;
std::set<int> g[5 + nmax];
int deg[5 + nmax], active[1 + nmax];
std::unordered_set<int> gfast[1 + nmax];

std::vector<int> findSet(int n, int target) {
  std::queue<int> q;
  for(int i = 1;i <= n; i++)
    if(g[i].size() < target)
      q.push(i);
  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    if(g[node].size() == target - 1) {
      std::vector<int> aux;
      aux.push_back(node);
      bool verdict = true;
      for(std::set<int>::iterator it = g[node].begin(); it != g[node].end(); it++)
        aux.push_back(*it);
      for(int i = 0; i < aux.size(); i++)
        if(g[aux[i]].size() < target - 1) {
          verdict = false;
          break;
        }
      
      for(int i = 0; i < aux.size() && verdict == true; i++) {
        int node = aux[i];
        for(int j = i + 1; j < aux.size() && verdict == true; j++)
          if(gfast[aux[i]].find(aux[j]) == gfast[aux[i]].end())
            verdict = false;
      }

      for(int i = 0; i < aux.size(); i++)
        active[aux[i]] = 0;

      if(verdict == true) {
        aux.insert(aux.begin(), 2);
        return aux;
      } 
    }
    for(std::set<int>::iterator it = g[node].begin(); it != g[node].end(); it++) {
      int to = *it;
      g[to].erase(node);
      if(g[to].size() == (target - 1)) {
        q.push(to);
      }
    }
  }
  std::vector<int> sol;
  for(int i = 1; i <= n; i++)
    if(target <= g[i].size())
      sol.push_back(i);
  if(0 < sol.size())
    sol.insert(sol.begin(), 1);
  return sol;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  for(int i = 1;i <= n; i++) {
    g[i].clear();
    gfast[i].clear();
  }
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].insert(y);
    gfast[x].insert(y);
    g[y].insert(x);
    gfast[y].insert(x);
  }
  std::vector<int> sol = findSet(n, k);
  if(sol.size() == 0)
    std::cout << -1 << '\n';
  else {
    std::cout << sol[0] ;
    if(sol[0] == 1)
      std::cout << " " << sol.size() - 1 << '\n';
    else
      std::cout << '\n';

    for(int i = 1;i < sol.size(); i++)
      std::cout << sol[i] << " ";
    std::cout << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();  
}