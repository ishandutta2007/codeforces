#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
std::vector<int> g[1 + nmax];
std::vector<int> ginv[1 + nmax];
int alive[1 + nmax], in_q[1 + nmax];

void solve(int k) {
  if(k == 0) 
    return ;
  else if(alive[k] == 1) {
    solve(k - 1);
  } else {
    alive[k] = 1;
    for(int h = 0; h < g[k].size(); h++) {
      int to = g[k][h];
      alive[to] = 1;
    }
    solve(k - 1);
    in_q[k] = 1;
    for(int h = 0; h < ginv[k].size(); h++) {
      int to = ginv[k][h];
      in_q[k] &= !in_q[to];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    ginv[y].push_back(x);
  }
  solve(n);
  int result = 0;
  for(int i = 1;i <= n; i++) {
    if(in_q[i] == 1)
      result++;
  }
  std::cout << result << '\n';
  for(int i = 1;i <= n; i++)
    if(in_q[i] == 1)
      std::cout << i << " " ;
  return 0;
}