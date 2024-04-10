#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <queue>

using ll = long long;

int const nmax = 5000;
std::vector<int> g[1 + nmax], invg[1 + nmax];
int seen[1 + nmax], dist[1 + nmax];

int find_cycle(int n, int start) {
  std::queue<int> q;
  for(int i = 1;i <= n; i++)
    dist[i] = 0;
  q.push(start);
  dist[start] = 1;
  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(dist[to] == 0) {
        dist[to] = dist[node] + 1;
        q.push(to);
      } else if (to == start)
        return dist[node];
    }
  }
  return 0;
}

int mark[1 + nmax], group[1 + nmax];

void markzone(int n, int start) {
  for(int i = 1; i <= n; i++)
    mark[i] = 0;
  std::queue<int> q, q2;
  q.push(start);
  q2.push(start);
  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size();h ++) {
      int to = g[node][h];
      if((mark[to] & 1) == 0) {
        mark[to] |= 1;
        q.push(to);
      }
    }
  }
  while(0 < q2.size()) {
    int node = q2.front();
    q2.pop();
    for(int h = 0; h < invg[node].size();h ++) {
      int to = invg[node][h];
      if((mark[to] & 2) == 0) {
        mark[to] |= 2;
        q2.push(to);
      }
    }
  }
  for(int i = 1;i <= n; i++)
    if(mark[i] == 3)
      group[i] = start;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    invg[y].push_back(x);
  }

  int sol = 0;
  for(int i = 1;i <= n; i++) {
    if(group[i] == 0) {
      markzone(n, i);
    }
  }
  for(int i = 1;i <= n; i++)
    if(group[i] == i) {
      int result = find_cycle(n, i);
      for(int j = 1;j <= n; j++)
        if(group[j] == i) {
          result = std::min(result, find_cycle(n, j));
          for(int h = 0; h < g[j].size(); h++) {
            int to = g[j][h];
            if(group[to] != i)
              result = 0;
          }
        }
      if(0 < result)
        sol += result * 998 + 1;
    }
  std::cout << sol + n << '\n';
  return 0;
}