#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

int const nmax = 200000;
std::vector<int> g[1 + nmax];
int dist[1 + nmax];

void solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    g[i].clear();
    dist[i] = 1;
  }
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> sol;
  for(int i = 1;i <= n; i++) {
    if(dist[i] < 3) {
      for(int h = 0;h < g[i].size(); h++) {
        int to = g[i][h];
        dist[to] = std::max(dist[to], dist[i] + 1);
      }
    } else 
      sol.push_back(i);
  }
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();

}