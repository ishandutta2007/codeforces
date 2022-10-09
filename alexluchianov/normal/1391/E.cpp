#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using ll = long long;
#define MIN(a, b) (((a) : (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
std::vector<int> g[1 + nmax];
int level[1 + nmax],  far[1 + nmax];
int _count[1 + nmax];

void dfs(int node, int parent) {
  far[node] = parent;
  level[node] = level[parent] + 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(level[to] == 0) {
      _count[node]++;
      dfs(to, node);
    }
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    g[i].clear();
    _count[i] = 0;
    far[i] = level[i] = 0;
  }

  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int n2 = (n + 1) / 2;
  
  for(int i = 1;i <= n; i++) {
    if(n2 <= level[i]) {
      int start = i;
      std::cout << "PATH\n" << level[start] << '\n';
      while(0 < start) {
        std::cout << start << " ";
        start = far[start];
      }
      std::cout << '\n';
      return ;
    }
  }
  std::queue<int> q;
  for(int i = 1;i <= n; i++)
    if(_count[i] == 0)
      q.push(i);
  std::vector<std::pair<int,int>> sol;
  while(0 < q.size()) {
    if(q.size() < 2)
      break;
    int node1 = q.front();
    q.pop();
    int node2 = q.front();
    q.pop();
    sol.push_back({node1, node2});
    _count[far[node1]]--;
    _count[far[node2]]--;
    if(_count[far[node1]] == 0)
      q.push(far[node1]);
    if(far[node1] != far[node2] && _count[far[node2]] == 0)
      q.push(far[node2]);
  }
  std::cout << "PAIRING\n";
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  std::cout << '\n';
  return ;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}