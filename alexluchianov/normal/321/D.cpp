#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

int const nmax = 33;
int const inf = 1000000000;

int v[1 + nmax][1 + nmax];
int dp[1 + nmax][1 + nmax][2];
int p[1 + nmax];

int solve(int n, int curr) {
  int hf = (n + 1) / 2;
  if(curr == 0) {
    int result = 0;
    for(int i = 1; i <= hf; i++)
      result += std::max(dp[i][1][0], dp[i][1][1]);
    return result;
  } else {
    int result = -inf;
    for(p[curr] = -1; p[curr] <= 1; p[curr] += 2) {
      if(curr == hf) {
        dp[hf][curr][0] = p[curr] * v[curr][hf]; 
        dp[hf][curr][1] = p[curr] * v[curr][hf]; 
        for(int i = 1;i < hf; i++) {
          dp[i][curr][0] = v[curr][i] + p[curr] * v[curr][i + hf];
          dp[i][curr][1] = -1 * v[curr][i] + -1 * p[curr] * v[curr][i + hf];
        }
      } else {
        dp[hf][curr][0] = dp[hf][curr + 1][0] + p[curr] * v[curr][hf]
                           + p[hf] * p[curr] * v[hf + curr][hf];
        dp[hf][curr][1] = dp[hf][curr + 1][1] + p[curr] * v[curr][hf]
                           + p[hf] * p[curr] * v[hf + curr][hf];
        for(int i = 1;i < hf; i++) {
          dp[i][curr][0] = dp[i][curr + 1][0] + std::fabs(v[curr][i] + p[curr] * v[curr][i + hf]
                                    + v[curr + hf][i] + p[curr] * p[hf] * v[curr + hf][i + hf]);
          dp[i][curr][1] = dp[i][curr + 1][1] + std::fabs(v[curr][i] + p[curr] * v[curr][i + hf]
                                    + -1 * v[curr + hf][i] + -1 * p[curr] * p[hf] * v[curr + hf][i + hf]);
        }
      }
      result = std::max(result, solve(n, curr - 1));
    }
    return result;
  }
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      std::cin >> v[i][j];
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
      dp[i][j][0] = dp[i][j][1] = -inf;
  int hf = (n + 1) / 2;
  std::cout << solve(n, hf) << '\n';
  return 0;
}