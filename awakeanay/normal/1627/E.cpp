#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define int long long

const int INF = 1'000'000'000'000'000'000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int x[n];
    for(int i = 0; i < n; i++)
      std::cin >> x[i];

    std::map<std::pair<int, int>, int> mp;
    std::vector<std::pair<int, int> > flr[n];
    std::vector<std::vector<std::pair<int, int> > > Adj;
    mp[{0, 0}] = 0;
    mp[{n-1, m-1}] = 1;
    flr[0].push_back({0, 0});
    flr[n-1].push_back({m-1, 1});
    Adj.push_back(std::vector<std::pair<int, int> >());
    Adj.push_back(std::vector<std::pair<int, int> >());

    for(int i = 0; i < k; i++) {
      int a, b, c, d, h;
      std::cin >> a >> b >> c >> d >> h;
      a--; b--; c--; d--;
      if(mp.find({a, b}) == mp.end()) {
        mp[{a, b}] = Adj.size();
        Adj.push_back(std::vector<std::pair<int, int> >());
        flr[a].push_back({b, mp[{a, b}]});
      }
      if(mp.find({c, d}) == mp.end()) {
        mp[{c, d}] = Adj.size();
        Adj.push_back(std::vector<std::pair<int, int> >());
        flr[c].push_back({d, mp[{c, d}]});
      }

      Adj[mp[{a, b}]].push_back({mp[{c, d}], -h});
    }

    std::vector<int> dp(Adj.size(), INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
      std::sort(flr[i].begin(), flr[i].end());

      int leftM = INF+x[i];
      int sz = flr[i].size();
      //std::cout << i << " " << sz << std::endl;
      for(int j = 0; j < sz; j++) {
        int u = flr[i][j].second;
        leftM = std::min(leftM, dp[u]-flr[i][j].first*x[i]);
        dp[u] = std::min(dp[u], leftM+x[i]*flr[i][j].first);
      }

      int rightM = INF+m*x[i];
      for(int j = sz-1; j >= 0; j--) {
        int u = flr[i][j].second;
        rightM = std::min(rightM, dp[u]+flr[i][j].first*x[i]);
        dp[u] = std::min(dp[u], rightM-x[i]*flr[i][j].first);
        if(dp[u] == INF)
          continue;
        for(auto k : Adj[u])
          dp[k.first] = std::min(dp[k.first], dp[u] + k.second);
      }
      /*
      for(int j = 0; j < sz; j++) {
        std::cout << i << " " << flr[i][j].first << " " << dp[flr[i][j].second] << std::endl;
      }
      */
    }

    if(dp[1] == INF) {
      std::cout << "NO ESCAPE" << std::endl;
    }
    else
      std::cout << dp[1] << std::endl;
  }

  return 0;
}