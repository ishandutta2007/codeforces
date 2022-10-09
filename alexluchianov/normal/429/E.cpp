#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>


using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int l[1 + nmax], r[1 + nmax];

struct Event{
  int id;
  int time;
  int ev;
  bool operator < (Event const a) {
    if(time != a.time)
      return time < a.time;
    else
      return ev < a.ev;
  }
};
int color[1 + nmax], seen[1 + nmax];

std::vector<std::pair<int,int>> g[1 + nmax];
void addedge(int x, int y, int cost)  {
  g[x].push_back({y, cost});
  g[y].push_back({x, cost});
}

void dfs(int node, int col) {
  if(seen[node] == 0) {
    seen[node] = 1;
    color[node] = col;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      dfs(to, col ^ g[node][h].second);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Event> aux;
  for(int i = 1;i <= n; i++) { 
    std::cin >> l[i] >> r[i];
    aux.push_back({i, l[i], 0});
    aux.push_back({i, r[i], 1});
  }
  std::sort(aux.begin(), aux.end());
  for(int i = 0; i < aux.size(); i += 2) 
    addedge(aux[i].id, aux[i + 1].id, 1 ^ aux[i].ev ^ aux[i + 1].ev);
  for(int i = 1;i <= n; i++)
    dfs(i, 0);
  for(int i = 1;i <= n; i++)
    std::cout << color[i] << " ";
  return 0;
}