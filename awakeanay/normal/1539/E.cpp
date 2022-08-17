#include <iostream>
#include <vector>
#include <set>

#define int long long

std::set<std::pair<int, int> > lset, lsetr, rset, rsetr;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  // dp[i][j]: Can you make the first i moves such that, ith number goes to j?
  // -1 if not possible, otherwise how many previous moves card goes to j
  int dp[n+1][2];
  dp[0][0] = dp[0][1] = 1;

  lset.insert({0, 0});
  lsetr.insert({0, 0});
  rset.insert({0, 0});
  rsetr.insert({0, 0});

  int failR = -1, failL = -1;

  for(int i = 1; i <= n; i++) {
    int k;
    std::cin >> k;

    int la, lb, ra, rb;
    std::cin >> la >> lb >> ra >> rb;

    if(k < la || k > lb)
      failL = i;
    if(k < ra || k > rb)
      failR = i;

    while(!lset.empty()) {
      std::pair<int, int> cur = *lset.begin();
      if(cur.first >= la)
        break;
      lsetr.erase({cur.second, cur.first});
      lset.erase(cur);
    }

    while(!lset.empty()) {
      std::pair<int, int> cur = *lset.rbegin();
      if(cur.first <= lb)
        break;
      lsetr.erase({cur.second, cur.first});
      lset.erase(cur);
    }

    while(!rset.empty()) {
      std::pair<int, int> cur = *rset.begin();
      if(cur.first >= ra)
        break;
      rsetr.erase({cur.second, cur.first});
      rset.erase(cur);
    }

    while(!rset.empty()) {
      std::pair<int, int> cur = *rset.rbegin();
      if(cur.first <= rb)
        break;
      rsetr.erase({cur.second, cur.first});
      rset.erase(cur);
    }

    dp[i][0] = dp[i][1] = -1;
    if(!lset.empty()) {
      std::pair<int, int> cur = *lsetr.rbegin();
      if(failR <= cur.first)
        dp[i][1] = i-cur.first;
    }
    if(!rset.empty()) {
      std::pair<int, int> cur = *rsetr.rbegin();
      if(failL <= cur.first)
        dp[i][0] = i-cur.first;
    }

    if(dp[i][0] != -1) {
      lset.insert({k, i});
      lsetr.insert({i, k});
    }
    if(dp[i][1] != -1) {
      rset.insert({k, i});
      rsetr.insert({i, k});
    }
  }

  if(dp[n][0] != -1 || dp[n][1] != -1)
    std::cout << "Yes" << std::endl;
  else {
    std::cout << "No" << std::endl;
    return 0;
  }

  int x = n, y = 0;
  if(dp[n][1] != -1)
    y = 1;

  std::vector<int> ans;
  while(x != 0) {
    int cur = dp[x][y];
    for(int i = 0; i < cur; i++)
      ans.push_back(y);
    y = !y;
    x -= cur;
  }

  for(int i = 0; i < n; i++)
    std::cout << ans[n-i-1] << " ";
  std::cout << std::endl;

  return 0;
}