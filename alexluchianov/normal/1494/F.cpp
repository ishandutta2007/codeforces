#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 3000;

struct Edge{
  int to;
  int rev;
  int active;
};
std::vector<Edge> g[5 + nmax];
int deg[5 + nmax], spec[5 + nmax], rem[5 + nmax];

void addEdge(int x, int y) {
  g[x].push_back({y, g[y].size(), 0});
  g[y].push_back({x, g[x].size() - 1, 0});
}

void euler(int node, std::vector<int> &sol) {
  for(int &h = rem[node]; h < g[node].size(); h++) {
    Edge &e = g[node][h];
    if(e.active == 0) {
      e.active = 1;
      g[e.to][e.rev].active = 1;
      euler(e.to, sol);
    }
  }
  sol.push_back(node);
}

void removeEdge(int x, int y) {
  g[x].pop_back();
  g[y].pop_back();
}
int seen[5 + nmax];

void dfstest(int node) {
  seen[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    Edge &e = g[node][h];
    if(e.active == 0 && seen[e.to] == 0)
      dfstest(e.to);
  }
}

int solve(int n, int m, int center) {
  for(int i = 1;i <= n; i++) {
    for(int h = 0; h < g[i].size(); h++)
      g[i][h].active = 0;
    rem[i] = 0;
    seen[i] = 0;
  }

  for(int i = 1; i <= n; i++) {
    deg[i] = g[i].size();
    spec[i] = 0;
  }
  spec[center] = 1;
  int friends = 0;
  for(int h = 0; h < g[center].size(); h++) {

    Edge &e = g[center][h];
    if(deg[e.to] % 2 == 1) {
      e.active = 1;
      g[e.to][e.rev].active = 1;
      spec[e.to] = 1;
      friends++;
    }
  }
  int root = center;
  for(int i = 1; i <= n; i++)
    if(spec[i] == 0 && deg[i] % 2 == 1) {
      if(root != center)
        return 0;
      root = i;
    }
  
  std::vector<int> sol;
  
  bool flagflag = false;
  
  if(center == root) {
    dfstest(center);
    for(int i = 1;i <= n; i++)
      if(seen[i] == 0) {
        for(int h = 0; h < g[i].size(); h++) {
          int to = g[i][h].to;
          if(to != root && spec[to] == 1) {
            root = to;
            friends--;
            flagflag = true;
            break;
          }
        }
        if(flagflag == true)
          break;
      }
  }
  if(center != root) 
    addEdge(center, root);
  euler(center, sol);

  if(center != root) {
    if(flagflag == false)
      sol.pop_back();
    bool flag = 0;
    std::vector<int> sol2;
    for(int i = 1; i < sol.size(); i++) {
      int node1 = sol[i - 1], node2 = sol[i];
      if(node1 == center && node2 == root) {
        for(int h = i; h < sol.size(); h++)
          sol2.push_back(sol[h]);
        for(int h = 0; h < i; h++)
          sol2.push_back(sol[h]);
        std::swap(sol, sol2);
        flag = 1;
        break;
      } else if(node1 == root && node2 == center) {
        for(int h = i; h < sol.size(); h++)
          sol2.push_back(sol[h]);
        for(int h = 0; h < i; h++)
          sol2.push_back(sol[h]);
        std::swap(sol, sol2);
        std::reverse(sol.begin(), sol.end());
        flag = 1;
        break;
      }
    }

    if(sol.back() == root && sol[0] == center)
      flag = true;
    if(flag == 0)
      return 0;
  }

  //std::cout << sol.size() << " " << friends << " " << m + 1 << '\n'; 
  if(sol.size() + friends == m + 1) {
    sol.push_back(-1);
    for(int i = 1; i <= n; i++)
      if(i != root && spec[i] == 1 && i != center) {
        sol.push_back(i);
        sol.push_back(center);
      }
    
    std::cout << sol.size() << '\n';
    for(int h = 0; h < sol.size(); h++)
      std::cout << sol[h] << " ";
    std::cout << '\n';
    return 1;
  } else
    return 0;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    addEdge(x, y);
  }
  for(int i = 1;i <= n; i++)
    if(solve(n, m, i) == 1) {
      return 0;
    }
  std::cout << 0 << '\n';
  return 0;
}