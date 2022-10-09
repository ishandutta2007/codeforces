#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 3000;
int seen[1 + nmax], dp[1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,int>> edges;
  for(int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    edges.push_back({x, y});
  }
  ll result = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1;j <= n; j++)
      seen[j] = dp[j] = 0;
    for(int h = 0;h < edges.size(); h++) {
      int x = edges[h].first, y = edges[h].second;
      if(x == i)
        seen[y] = 1;
    }
    for(int h = 0;h < edges.size(); h++) {
      int x = edges[h].first, y = edges[h].second;
      if(seen[x] == 1 && y != i) {
        result += dp[y];
        dp[y]++;
      }
    }
  }
  std::cout << result << '\n';
  return 0;
}