#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll const inf = 1000000000000000000;
int p[1 + nmax];
ll dp[1 + nmax], dp2[1 + nmax];

int main() {
  int n, c;
  std::cin >> n >> c;
  for(int i = 1;i <= n; i++) 
    std::cin >> p[i];
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    result += std::min(val, p[i]);
    p[i] -= val;
  }
  

  for(int i = 1;i <= n; i++) {
    for(int j = 0; j <= i; j++) 
      dp2[j] = inf;
    if(p[i] < 0) {
      for(int j = 0;j < i; j++)
        dp2[j + 1] = std::min(dp2[j + 1], dp[j] + 1LL * (i - 1 - j) * c);
      for(int j = 0; j < i; j++)
        dp2[j] = std::min(dp2[j], dp[j] + (-p[i]));
    } else if(p[i] == 0){
      for(int j = 0; j < i; j++)
        dp2[j + 1] = std::min(dp2[j + 1], dp[j] + 1LL * (i - 1 - j) * c);
      for(int j = 0; j < i; j++)
        dp2[j] = std::min(dp2[j], dp[j]);
    } else {
      for(int j = 0; j < i; j++)
        dp2[j + 1] = std::min(dp2[j + 1], dp[j] + 1LL * (i - 1 - j) * c + p[i]);
      for(int j = 0;j < i; j++)
        dp2[j] = std::min(dp2[j], dp[j]); 
    }
    for(int j = 0;j <= i; j++)
      dp[j] = dp2[j];
  }

  ll result2 = inf;
  for(int j = 0; j <= n; j++)
    result2 = std::min(result2, dp[j]);

  std::cout << result + result2;
  return 0;
}