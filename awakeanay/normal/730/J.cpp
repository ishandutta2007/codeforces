#include <iostream>
#include <algorithm>

#define int long long

const int MX = 10001;
int dp[101][MX];

const int INF = 10000000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int sa = 0;
  std::pair<int, int> ta[n];
  for(int i = 0; i < n; i++) {
    std::cin >> ta[i].second;
    sa += ta[i].second;
  }

  for(int i = 0; i < n; i++) {
    std::cin >> ta[i].first;
  }

  std::sort(ta, ta+n);
  std::reverse(ta, ta+n);

  int cur = 0;
  int t1 = 0;
  for(int i = 0; i < n; i++) {
    cur += ta[i].first;
    t1++;
    if(cur >= sa)
      break;
  }

  int k = t1;

  for(int j = 0; j < 101; j++) {
    for(int i = 0; i < MX; i++) {
      dp[j][i] = -INF;
    }
  }
  dp[0][0] = 0;

  for(int k = 0; k < n; k++) {
    for(int i = t1; i >= 1; i--) {
      for(int j = 0; j < MX; j++) {
        if(ta[k].first <= j) {
          dp[i][j] = std::max(dp[i][j], dp[i-1][j-ta[k].first] + ta[k].second);
        }
      }
    }
  }

  int best = 0;
  for(int i = sa; i < MX; i++)
    best = std::max(best, dp[k][i]);

  //std::cout << sa << " " << best << std::endl;
  std::cout << t1 << " " << sa-best << std::endl;

  return 0;
}