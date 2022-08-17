#include <iostream>
#include <queue>
#include <vector>

#define int long long

const int MOD = 32768;

std::vector<int> Adj[MOD];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 0; i < MOD; i++) {
    Adj[(2*i)%MOD].push_back(i);
    Adj[(i+1)%MOD].push_back(i);
  }

  std::vector<int> d(MOD, MOD);
  std::queue<int> bfsq;
  bfsq.push(0);
  d[0] = 0;

  while(!bfsq.empty()) {
    int u = bfsq.front();
    bfsq.pop();

    for(int j : Adj[u]) {
      if(d[j] == MOD) {
        bfsq.push(j);
        d[j] = d[u] + 1;
      }
    }
  }

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    std::cout << d[x] << " ";
  }
  std::cout << std::endl;

  return 0;
}