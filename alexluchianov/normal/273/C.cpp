#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <cmath>

int const nmax = 300000;
int v[1 + nmax]; 
std::vector<int> g[1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
     int x, y;
     std::cin >> x >> y;
     g[x].push_back(y);
     g[y].push_back(x);
   }
   std::queue<int> q;
   for(int i = 1;i <= n; i++)
     q.push(i);
  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    int curr = 0;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(v[to] == v[node]) 
        curr++;
    }
    if(1 < curr) {
      v[node] = !v[node];
      for(int h = 0; h < g[node].size(); h++)
        q.push(g[node][h]);
    }
  }

  for(int i = 1;i <= n; i++)
    std::cout << v[i];
}