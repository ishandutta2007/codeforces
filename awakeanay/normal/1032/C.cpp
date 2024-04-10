#include <iostream>
#include <set>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  
  int dp[n][5];
  int last[n][5];
  
  for(int j = 0; j < 5; j++)
    dp[0][j] = 1;

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      dp[i][j] = 0;
      
      if(a[i] == a[i-1]) {
        for(int k = 0; k < 5; k++) {
          if(dp[i-1][k] && k != j) {
            dp[i][j] = 1;
            last[i][j] = k;
          }
        }
      }
      else if(a[i] < a[i-1]) {
        for(int k = j+1; k < 5; k++) {
          if(dp[i-1][k]) {
            dp[i][j] = 1;
            last[i][j] = k;
          }
        }
      }
      else {
        for(int k = 0; k < j; k++) {
          if(dp[i-1][k]) {
            dp[i][j] = 1;
            last[i][j] = k;
          }
        }
      }
    }
  }

  int ans[n];

  bool poss = false;
  for(int j = 0; j < 5; j++) {
    if(dp[n-1][j]) {
      poss = true;
      ans[n-1] = j;
    }
  }

  if(!poss) {
    std::cout << -1 << std::endl;
    return 0;
  }

  for(int i = n-2; i >= 0; i--) {
    ans[i] = last[i+1][ans[i+1]];
  }

  for(int j : ans) {
    std::cout << j+1 << " ";
  }

  std::cout << std::endl;
  return 0;
}