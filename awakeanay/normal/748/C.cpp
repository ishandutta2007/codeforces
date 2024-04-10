#include <iostream>
#include <vector>

signed main() {
  int n;
  std::cin >> n;

  int dp[n+1];
  dp[0] = 0;
  std::vector<int> last(n, 0);

  for(int i = 1; i <= n; i++) {
    char c;
    std::cin >> c;

    if(c == 'U') {
      dp[i] = dp[std::max(last[1] , std::min(last[2], last[3]))] + 1;
      last[0] = i;
    }
    else if(c == 'D') {
      dp[i] = dp[std::max(last[0] , std::min(last[2], last[3]))] + 1;
      last[1] = i;
    }
    else if(c == 'L') {
      dp[i] = dp[std::max(last[3] , std::min(last[0], last[1]))] + 1;
      last[2] = i;
    }
    else {
      dp[i] = dp[std::max(last[2] , std::min(last[0], last[1]))] + 1;
      last[3] = i;
    }
  }

  std::cout << dp[n] << std::endl;

  return 0;
}