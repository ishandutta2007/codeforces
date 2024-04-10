#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int INF = 10000000000000000;

std::vector<int> par, depth;

int calc(int u) {
  if(depth[u] != -1)
    return depth[u];
  return depth[u] = calc(par[u]) + 1;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    par = depth = std::vector<int>(n, -1);
    for(int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      par[i] = x-1;
    }

    int val[n];
    for(int i = 1; i < n; i++)
      std::cin >> val[i];

    std::vector<int> max(n, 0);
    depth[0] = 0;

    int maxd = 0;
    for(int i = 1; i < n; i++)
      maxd = std::max(maxd, calc(i));


    std::vector<std::pair<int, int> > help[maxd+1];
    for(int i = 1; i < n; i++)
      help[calc(i)].push_back({val[i], i});

    for(int i = maxd; i > 0; i--) {
      std::sort(help[i].begin(), help[i].end());

      int pref_best = -INF;
      int left = help[i].front().first;
      int right = help[i].back().first;

      for(int j = 0; j < help[i].size(); j++) {
        int p = par[help[i][j].second];
        max[p] = std::max(max[p], pref_best + help[i][j].first);
        max[p] = std::max(max[p], std::max(right-help[i][j].first, help[i][j].first-left) + max[help[i][j].second]);
        pref_best = std::max(pref_best, max[help[i][j].second] - help[i][j].first);
      }

      int suff_best = -INF;
      for(int j = ((int) help[i].size()) - 1; j >= 0; j--) {
        int p = par[help[i][j].second];
        max[p] = std::max(max[p], suff_best - help[i][j].first);
        suff_best = std::max(suff_best, max[help[i][j].second] + help[i][j].first);
      }
    }

    std::cout << max[0] << std::endl;
  }

  return 0;
}