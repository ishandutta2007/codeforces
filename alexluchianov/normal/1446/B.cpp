#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int dp[1 + nmax][1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  std::string s, s2;
  std::cin >> s >> s2;
  s = "#" + s;
  s2 = "#" + s2;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++){
      dp[i][j] = std::max(dp[i - 1][j - 1] + 4 * (s[i] == s2[j]) - 2, 
          std::max(dp[i - 1][j] - 1, dp[i][j - 1] - 1)
          );
      dp[i][j] = std::max(dp[i][j], 0);      
    }
  int result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      result = std::max(result, dp[i][j]);
  std::cout << result;
  return 0;
}