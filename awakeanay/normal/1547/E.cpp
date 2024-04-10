#include <iostream>
#include <set>
#include <vector>

#define int long long

const int MAXN = 300005;
const int INF = 2000000000;

std::vector<std::pair<int, int> > Adj[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::pair<int, int> inp[k];
    for(int i = 0; i < k; i++)
      std::cin >> inp[i].first;
    for(int i = 0; i < k; i++)
      std::cin >> inp[i].second;

    for(int i = 0; i < k; i++) {
      Adj[0].push_back({inp[i].first, inp[i].second});
    }

    for(int i = 2; i <= n; i++) {
      Adj[i].push_back({i-1, 1});
      Adj[i-1].push_back({i, 1});
    }

    std::set<std::pair<int, int> > dij;
    dij.insert({0, 0});

    std::vector<int> d(n+1, INF);
    d[0] = 0;

    while(!dij.empty()) {
      int u = (*dij.begin()).second;
      dij.erase(dij.begin());

      for(std::pair<int, int> j : Adj[u]) {
        if(d[j.first] > d[u] + j.second) {
          dij.erase({d[j.first], j.first});
          d[j.first] = d[u] + j.second;
          dij.insert({d[j.first], j.first});
        }
      }
    }

    for(int i = 1; i <= n; i++)
      std::cout << d[i] << " ";
    std::cout << std::endl;

    for(int i = 0; i <= n; i++)
      Adj[i].clear();
  }

  return 0;
}