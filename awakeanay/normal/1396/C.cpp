#include <iostream>

#define int long long
#define INF 1000000000000000000

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, gun, laser, awp, d;
  std::cin >> n >> gun >> laser >> awp >> d;

  int one[n], two[n], tpref[n];
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;

    one[i] = x*gun + awp;
    two[i] = std::min(gun*(x+1), laser) + std::min(std::min(laser, awp), gun);
    two[i] = std::min(one[i], two[i]);
    tpref[i] = two[i];
    if(i) tpref[i] += tpref[i-1];
  }

  int dp[n];
  dp[0] = one[0];

  int reach = 0;
  int mreach = 0;
  for(int i = 1; i+1 < n; i++) {
    dp[i] = dp[i-1] + one[i] + d;
    dp[i] = std::min(dp[i], reach + 3*i*d + tpref[i]);
    reach = std::min(reach, dp[i-1] + d - 3*i*d - tpref[i-1]);
    mreach = std::min(mreach, dp[i-1] + d - 2*i*d - tpref[i-1]);
  }

  int ans = dp[n-2] + one[n-1] + d;
  ans = std::min(ans, mreach + 2*(n-1)*d  + tpref[n-2] + one[n-1]);
  ans = std::min(ans, mreach + 2*(n-1)*d + tpref[n-1] + 2*d);
  ans = std::min(ans, (n > 2 ? dp[n-3] + d : 0) + 3*d + two[n-1] + two[n-2]);

  std::cout << ans << std::endl;

  return 0;
}