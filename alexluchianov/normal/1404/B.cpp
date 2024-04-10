#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
std::vector<int> g[1 + nmax];

void dfs(int node, int parent, std::vector<int> &level) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      level[to] = level[node] + 1;
      dfs(to, node, level);
    }
  }
}

std::vector<int> get_distances(int n, int node) {
  std::vector<int> level(1 + n);
  dfs(node, 0, level);
  return level;
}

int get_max(int n, std::vector<int> &level) {
  int id = 0;
  for(int i = 1; i <= n; i++) 
    if(level[id] < level[i])
      id = i;
  return id;
}

int solve() {
  int n, a, b, da, db;
  std::cin >> n >> a >> b >> da >> db;
  for(int i = 1;i <= n; i++)
    g[i].clear();
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> level = get_distances(n, a);
  if(level[b] <= da)
    return 0;
  int node = get_max(n, level);
  level = get_distances(n, node);
  if(da * 2 < level[get_max(n, level)] && da * 2 < db)
    return 1;
  return 0;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    if(solve() == 0)
      std::cout << "Alice\n";
    else
      std::cout << "Bob\n";
  return 0;
}