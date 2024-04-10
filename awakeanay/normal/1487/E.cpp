#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define int long long

const int INF = 100000000000000;


signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int sz[4];
  int p[5];
  p[0] = 0;
  for(int i = 0; i < 4; i++) {
    std::cin >> sz[i];
    p[i+1] = sz[i];
    p[i+1] += p[i];
  }

  std::vector<std::pair<int, int> > vals[4];
  std::set<int> Adj[p[3]];
  for(int i = 0; i < 4; i++) {
    vals[i].resize(sz[i]);
    for(int j = 0; j < sz[i]; j++) {
      std::cin >> vals[i][j].first;
      vals[i][j].second = p[i] + j;
    }
  }

  for(int i = 0; i < 3; i++) {
    int c;
    std::cin >> c;

    while(c--) {
      int x, y;
      std::cin >> x >> y;
      x--; y--;
      Adj[x+p[i]].insert(p[i+1] + y);
    }
  }

  std::sort(vals[3].begin(), vals[3].end());

  int ans = INF;
  for(int i = 2; i >= 0; i--) {
    for(int j = 0; j < sz[i]; j++) {
      if(Adj[p[i]+j].size() == sz[i+1]) {
        vals[i][j].first = INF;
        continue;
      }

      for(int k = 0; k < sz[i+1]; k++) {
        if(!Adj[p[i]+j].count(vals[i+1][k].second)) {
          vals[i][j].first += vals[i+1][k].first;
          break;
        }
      }
    }

    std::sort(vals[i].begin(), vals[i].end());
    if(i == 0)
      ans = vals[i][0].first;
  }

  if(ans >= INF)
    std::cout << -1 << std::endl;
  else
    std::cout << ans << std::endl;

  return 0;
}