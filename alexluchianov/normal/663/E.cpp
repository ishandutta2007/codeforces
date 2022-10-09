#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const kmax = 20;

int v[1 + nmax];

int dp[(1<<kmax)][1 + kmax];
int dp2[(1<<kmax)][1 + kmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::string s[1 + kmax];
  for(int i = 0; i < n; i++)
    std::cin >> s[i];
  for(int i = 1;i <= m; i++) 
    for(int j = 0; j < n; j++)
      v[i] |= ((s[j][i - 1] - '0')<<j);
  for(int j = 1; j <= m; j++)
    dp[v[j]][0]++;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < (1 << n); j++)
      for(int h = 0; h <= i; h++) {
        dp2[j][h] += dp[j][h];
        dp2[j ^ (1 << i)][h + 1] += dp[j][h];
      }
    for(int j = 0; j < (1 << n); j++) 
      for(int h = 0; h < n; h++) {
        dp[j][h] = dp2[j][h];
        dp2[j][h] = 0;
      }
  }
  int result = (1 << n) * n;
  for(int i = 0; i < (1 << n); i++) {
    int aux = 0;
    for(int h = 0; h <= n; h++)  {
      aux += std::min(h, n  - h) * dp[i][h];
    }
    result = std::min(result, aux); 
  }
  std::cout << result;
  return 0;
}