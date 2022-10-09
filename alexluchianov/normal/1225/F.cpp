#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 100000;
std::vector<int> g[1 + nmax];
int sz[1 + nmax];

void computesz(int node) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    computesz(to);
    sz[node] = std::max(sz[node], sz[to] + 1);
  }
}

bool compare(int a, int b) {
  return sz[a] < sz[b];
}
void dfs(int node, std::vector<int> &sol) {
  std::cout << node << " " ;
  if(0 == g[node].size())
    return ;

  std::sort(g[node].begin(), g[node].end(), compare);
  for(int h = g[node].size() - 1; 0 < h; h--) {
    int to1 = g[node][h - 1], to2 = g[node][h];
    g[to1].push_back(to2);
    sz[to1] = std::max(sz[to1], sz[to2] + 1);
    sol.push_back(to2);
  }
  dfs(g[node][0], sol);
}


int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i < n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> sol;
  computesz(0);
  dfs(0, sol);
  std::cout << '\n' << sol.size() << '\n';
  std::reverse(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
  return 0;
}