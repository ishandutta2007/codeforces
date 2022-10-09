#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <queue>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

struct Edge{
  int to;
  int l;
  int r;
  bool operator < (Edge const &oth) const {
    return l < oth.l;
  }
};
int const nmax = 500000;

std::vector<Edge> g[1 + nmax];

struct Event{
  int node;
  int start;
  int stop;
  bool operator < (Event const &oth) const {
    return start > oth.start;
  }
};
int ptreven[1 + nmax], ptrodd[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int a, b, x, y;
    std::cin >> a >> b >> x >> y;
    g[a].push_back({b, x, y});
    g[b].push_back({a, x, y});
  }

  for(int i = 1; i <= n; i++)
    std::sort(g[i].begin(), g[i].end());

  std::priority_queue<Event> pq;
  pq.push({1, 0, 0});

  while(0 < pq.size()) {
    Event curr = pq.top();
    pq.pop();

    if(curr.node == n) {
      std::cout << curr.start;
      return 0;
    } else {
      int node = curr.node;
      if(curr.start % 2 == 0) {
        int start = ptreven[node];
        while(ptreven[node] < g[node].size() && g[node][ptreven[node]].l <= curr.stop) {
          if(curr.stop < g[node][ptreven[node]].r) 
            curr.stop += (g[node][ptreven[node]].r - curr.stop) / 2 * 2;
          ptreven[node]++;
        }
        for(int j = start; j < ptreven[node]; j++) {
          Edge e = g[node][j];
          int newl = curr.start;
          int newr = curr.stop;
          e.r--;

          if(newl < e.l) 
            newl += (e.l - newl + 1) / 2 * 2;
          if(e.r < newr)
            newr -= (newr - e.r + 1) / 2 * 2;

          if(newl <= newr)
            pq.push({e.to, newl + 1, newr + 1});
        }
      } else {
        int start = ptrodd[node];
        while(ptrodd[node] < g[node].size() && g[node][ptrodd[node]].l <= curr.stop) {
          if(curr.stop < g[node][ptrodd[node]].r) 
            curr.stop += (g[node][ptrodd[node]].r - curr.stop) / 2 * 2;
          ptrodd[node]++;
        }
        for(int j = start; j < ptrodd[node]; j++) {
          Edge e = g[node][j];
          int newl = curr.start;
          int newr = curr.stop;
          e.r--;
          if(newl < e.l) 
            newl += (e.l - newl + 1) / 2 * 2;
          if(e.r < newr)
            newr -= (newr - e.r + 1) / 2 * 2;
          if(newl <= newr)
            pq.push({e.to, newl + 1, newr + 1});
        }
      }
    }
  }
  std::cout << -1;
  return 0;
}