#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 200000;
std::vector<int> g[1 + nmax];

void dfs(int node, int parent, int val, int* frec) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node, !val, frec);
  }
  frec[val]++;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int frec[2] = {0};
  dfs(1, 0, 0, frec);
  std::cout << std::min(frec[0], frec[1]) - 1;
  return 0;
}