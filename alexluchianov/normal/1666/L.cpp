#include <iostream>
#include <vector>
#include <queue>

using ll = long long;

int const nmax = 200000;
std::vector<int> g[5 + nmax];
int mark[5 + nmax], prev[5 + nmax];

void printPath(int node, int acc) {
  if(prev[node] != 0)
    printPath(prev[node], acc + 1);
  else
    std::cout << acc << '\n';
  std::cout << node << " ";
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, start;
  std::cin >> n >> m >> start;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::queue<int> q;
  q.push(start);
 
  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(to == start)
        continue;
      if(node == start) {
        mark[to] = to;
        prev[to] = node;
        q.push(to);
      } else {
        if(mark[to] == 0) {
          mark[to] = mark[node];
          prev[to] = node;
          q.push(to);
        } else if(mark[to] != mark[node]) {
          std::cout << "Possible\n";

          printPath(to, 1);
          std::cout << '\n';
          prev[to] = node;
          printPath(to, 1);
          std::cout << '\n';
          return 0;
        } 
      }
    }
  }
  std::cout << "Impossible\n";
  return 0;
}