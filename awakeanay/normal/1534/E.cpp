#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<std::pair<int, int> > Adj[n+1];

  for(int i = 0; i <= n; i++) {
    for(int j = std::max(k-(n-i), 0ll); j <= std::min(i, k); j++) {
      int v = i-j+k-j;
      Adj[i].push_back({v, j});
    }
  }

  std::vector<int> par(n+1, -2), val(n+1, -1);

  std::queue<int> bfsq;
  bfsq.push(n);
  par[n] = -1;

  while(!bfsq.empty()) {
    int u = bfsq.front();
    bfsq.pop();

    for(std::pair<int, int> j : Adj[u]) {
      if(par[j.first] == -2) {
        par[j.first] = u;
        val[j.first] = j.second;
        bfsq.push(j.first);
      }
    }
  }

  if(par[0] == -2) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::vector<int> help;
  int cur = 0;
  while(par[cur] != -1) {
    help.push_back(val[cur]);
    cur = par[cur];
  }

  std::reverse(help.begin(), help.end());

  std::vector<int> even, odd;
  for(int i = 0; i < n; i++)
    even.push_back(i+1);

  int ans = 0;
  for(int j : help) {
    std::vector<int> neven, nodd;
    std::cout << "? ";
    for(int i = 0; i < even.size(); i++) {
      if(i < j) {
        nodd.push_back(even[i]);
        std::cout << even[i] << " ";
      }
      else
        neven.push_back(even[i]);
    }

    for(int i = 0; i < odd.size(); i++) {
      if(i < k-j) {
        neven.push_back(odd[i]);
        std::cout << odd[i] << " ";
      }
      else
        nodd.push_back(odd[i]);
    }
    even = neven;
    odd = nodd;
    std::cout << std::endl;
    int x;
    std::cin >> x;
    ans ^= x;
  }

  std::cout << "! " << ans << std::endl;

  return 0;
}