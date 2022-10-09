#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 3000;
std::vector<std::pair<int,int>> v;
int start[5 + nmax];
int dp[5 + nmax], dp2[5 + nmax], sumdp[5 + nmax];

int solve() {
  int n;
  std::cin >> n;
  v.clear();
  for(int i = 1;i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    v.push_back({y, -x});
  }
  v.push_back({1000000, 0});
  std::sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
    v[i].second = -v[i].second;

  for(int i = 0; i < v.size(); i++) {
    start[i] = -1;
    for(int j = 0; j < i; j++)
      if(v[j].first < v[i].second)
        start[i] = j;
  }

  int result = 0;
  for(int i = 0; i < v.size(); i++) {
    dp[i] = 1;
    int result2 = 0;
    //std::cout << v[i].first << " " << v[i].second << " " << start[i] << '\n';

    for(int j = 0; j < i; j++) {
      if(0 < j)
        sumdp[j] = sumdp[j - 1];
      else
        sumdp[j] = 0;
      if(v[i].second <= v[j].second) {
        dp2[j] = dp[j];
        if(0 <= start[j])
          dp2[j] = std::max(dp2[j], dp[j] + sumdp[start[j]]);
        result2 = std::max(result2, dp2[j]);
        if(0 < j)
          sumdp[j] = std::max(sumdp[j - 1], dp2[j]);
        else
          sumdp[j] = dp2[j];
      }
    }
    dp[i] = 1 + result2;
    result = std::max(result, dp[i]);
  }
  return result - 1;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}