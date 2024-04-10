#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 400;
int dp[1 + nmax][1 + nmax];

int main() {
  int a, b;
  std::cin >> a >> b;
  for(int sum = 1; sum <= nmax; sum++)
    for(int i = 1; i <= nmax; i++) {
      int j = sum - i;
      if(1 <= j && j <= nmax) {
        if(2 <= i)
          dp[i][j] = std::max(dp[i][j], dp[i - 2][j + 1] + 1);
        if(2 <= j)
          dp[i][j] = std::max(dp[i][j], dp[i + 1][j - 2] + 1);
      }
    }
  std::cout << dp[a][b];
  return 0;
}