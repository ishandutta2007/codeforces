#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MOD = 998244353;
const int INV2 = 499122177;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int s[n+1];
  std::vector<std::pair<int, int> > list;
  int open[n+1];

  for(int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y >> s[i+1];

    list.push_back({x, -(i+1)});
    list.push_back({y, i+1});
  }

  std::sort(list.begin(), list.end());

  for(int i = 0; i < 2*n; i++) {
    if(list[i].second > 0)
      open[list[i].second] = i;
  }

  std::vector<int> tele(n+1, 0), total(2*n, 0);

  if(s[n] == 1)
    total[2*n-1] = 2;
  else
    total[2*n-1] = 1;

  int ans = 0;
  for(int i = 2*n-1; i > 0; i--) {
    if(list[i-1].second < 0) {
      total[i-1] += (2*total[i] - (s[-list[i-1].second] == 0) + MOD)%MOD;
    }
    else {
      total[i-1] += total[i];
    }
    total[i-1] %= MOD;

    if(list[i].second < 0) {
      int u = -list[i].second;
      int sub = (total[i]-(s[u]==0)+MOD)%MOD;
      sub *= INV2;
      sub %= MOD;
      total[open[u]] += MOD - sub;
      total[open[u]] %= MOD;
    }

    ans += total[i]*(list[i].first-list[i-1].first+MOD);
    ans %= MOD;
  }

  ans += total[0]*list[0].first;
  ans %= MOD;

  std::cout << (ans+1)%MOD << std::endl;

  return 0;
}