#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <bitset>

using ll = long long;

int const nmax = 2000;
std::bitset<1 + nmax * 2> v[1 + nmax];
int spec[1 + nmax], where[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,int>> edges;
  for(int i = 1;i <= n; i++)
    v[i][n + i] = 1;
  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    edges.push_back({x, y});
    v[x][y] = 1;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1;j < i; j++)
      if(v[i][spec[j]] == 1)
        v[i] ^= v[j];
    for(int j = 1;j <= n; j++)
      if(v[i][j] == 1) {
        spec[i] = j;
        where[j] = i;
        break;
      }
    for(int j = 1; j < i; j++)
      if(v[j][spec[i]] == 1)
        v[j] ^= v[i];
  }
  
  for(int i = 0; i < edges.size(); i++) {
    int x, y;
    x = edges[i].first;
    y = edges[i].second;
    if(v[where[y]][n + x] == 0)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }
  return 0;
}