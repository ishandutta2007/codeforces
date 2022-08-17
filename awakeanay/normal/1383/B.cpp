#include <iostream>

#define int long long 
#define CALC 400

signed main() {
  int t;
  std::cin >> t;

  int dp[CALC][CALC][2];
  dp[0][0][0] = 0;
  dp[0][0][1] = 1;

  for(int i = 0; i < CALC; i++) {
    for(int j = 0; j < CALC; j++) {
      for(int k = 0; k < 2; k++) {
        if(i+j == 0) continue;
        bool cur = false;
        bool other = (i+k+1)%2;

        if(i && (dp[i-1][j][other] == false)) cur = true;
        if(j && (dp[i][j-1][other] == false)) cur = true;

        dp[i][j][k] = cur;
      }
    }
  }

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    bool done = false;
    for(int j = 31; j >= 0; j--) {
      int count = 0;
      for(int i = 0; i < n; i++) {
        if(a[i] & (1ll << j))
          count++;
      }
      if(count%2) {
        done = true;

        if(dp[count%CALC][(n-count)%CALC][0])
          std::cout << "WIN" << std::endl;
        else
          std::cout << "LOSE" << std::endl;

        break;
      }
    }

    if(!done)
      std::cout << "DRAW" << std::endl;
  }

  return 0;
}