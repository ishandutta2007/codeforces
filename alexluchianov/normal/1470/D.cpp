#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

std::vector<int> solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(1 + n);
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> seen(1 + n);
  std::queue<int> q;
  q.push(1);
  seen[1] = 1;
  
  std::vector<int> sol;

  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    if(seen[node] == 1) {
      sol.push_back(node);
      seen[node] = 2;

      std::vector<int> aux;
      for(int h = 0; h < g[node].size(); h++) {
        int to = g[node][h];
        if(seen[to] < 2){
          seen[to] = 2;
          aux.push_back(to);
        }
      }
      for(int h = 0;h < aux.size(); h++){
        int to = aux[h];
        for(int h2 = 0; h2 < g[to].size(); h2++) {
          int to2 = g[to][h2];
          if(seen[to2] == 0) {
            seen[to2] = 1;
            q.push(to2);
          }
        }
      }
    }
  }
  for(int i = 1; i <= n; i++)
    if(0 == seen[i])
      sol.clear();
  return sol;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::vector<int> sol = solve();
    if(sol.size() == 0)
      std::cout << "NO\n"; 
    else {
      std::cout << "YES\n";
      std::sort(sol.begin(), sol.end());

      std::cout << sol.size() << '\n';
      for(int i = 0; i < sol.size(); i++)
        std::cout << sol[i] << " ";
      std::cout << '\n';
    }
  }
  return 0;
}