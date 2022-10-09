#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 200000;
int v[1 + nmax];
std::vector<int> g[1 + nmax];

int mex(std::vector<int> aux) {
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  for(int i = 0; i < aux.size(); i++)
    if(aux[i] != i)
      return i;
  return aux.size();
}

int color[1 + nmax], dp[1 + nmax];

void dfs(int node) {
  std::vector<int> aux;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(color[to] == -1) 
      dfs(to);
    aux.push_back(color[to]);
  }
  color[node] = mex(aux);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  
  for(int i = 1;i <= n; i++)
    color[i] = -1;

  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  for(int i = 1;i <= n; i++)
    if(color[i] == -1)
      dfs(i);
  for(int i = 1;i <= n; i++)
    dp[color[i]] ^= v[i];
  int result = 0;
  for(int i = 0;i <= n; i++)
    result += (dp[i] != 0);
  if(result == 0)
    std::cout << "LOSE\n";
  else {
    for(int i = n; 0 <= i; i--) 
      if(dp[i] != 0) {
        std::cout << "WIN\n";
        for(int j = 1; j <= n; j++)
          if(color[j] == i) {
            if(0 < dp[i] && (v[j] ^ dp[i]) < v[j]) {
              v[j] ^= dp[i];
              dp[i] ^= dp[i];
              for(int h = 0; h < g[j].size(); h++) {
                int to = g[j][h];
                if(0 < dp[color[to]]) {
                  v[to] ^= dp[color[to]];
                  dp[color[to]] = 0;
                }
              }
              break;
            }
          }
        for(int j = 1;j <= n; j++)
          std::cout << v[j] << " ";
        std::cout << '\n';
        return 0;
      }
  }
  return 0;  
}