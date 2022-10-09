#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <bitset>
#include <queue>

using ll = long long;

int const nmax = 100;
int const inf = 1000;
std::bitset<5 + nmax> g[5 + nmax], invg[5 + nmax];
int dist[5 + nmax][5 + nmax];
std::pair<int,int> bus[5 + nmax];
std::bitset<5 + nmax> onpath[5 + nmax];
int frec[5 + nmax][5 + nmax];
int dp[5 + nmax];


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, start, stop;
  std::cin >> n >> m >> start >> stop;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      if(i != j)
        dist[i][j] = inf;

  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x][y] = 1;
    invg[y][x] = 1;
    dist[x][y] = 1;
  }

  for(int h = 1; h <= n; h++)
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= n; j++)
        dist[i][j] = std::min(dist[i][j], dist[i][h] + dist[h][j]);
  int k;
  std::cin >> k;

  for(int i = 1;i <= k; i++) {
    std::cin >> bus[i].first >> bus[i].second;
    if(dist[bus[i].first][bus[i].second] < inf) 
      for(int j = 1; j <= n; j++) {
        onpath[i][j] = ((dist[bus[i].first][j] + dist[j][bus[i].second]) == dist[bus[i].first][bus[i].second]);
        if(onpath[i][j] == 1)
          frec[i][dist[bus[i].first][j]] ++;
      }
  }

  for(int i = 1;i <= n; i++)
    dp[i] = -1;
  dp[stop] = 0;

  for(int step = 1;step <= n; step++) {
    std::bitset<1 + nmax> newlevel;
    for(int j = 1; j <= k; j++) {
      if(dist[bus[j].first][bus[j].second] < inf) {
        std::bitset<5 + nmax> reachable, proc, allowed = onpath[j];
        for(int h = 1; h <= n; h++)
          allowed[h] = (allowed[h] & (dp[h] == -1));

        if(-1 == dp[bus[j].second])
          reachable[bus[j].second] = 1;

        while(proc.count() < reachable.count()) {
          int node = (reachable ^ proc)._Find_first();
          proc[node] = 1;
          reachable = ((reachable | invg[node]) & allowed);
        }

        for(int h = 1; h <= n; h++)
          if(onpath[j][h] == 1 && reachable[h] == 0 && frec[j][dist[bus[j].first][h]] == 1) {
            newlevel[h] = 1;
          }
      }
    }
    for(int j = 1;j <= n; j++)
      if(dp[j] == -1 && newlevel[j] == 1)
        dp[j] = step;
  }
  std::cout << dp[start] << '\n';
  return 0;
}