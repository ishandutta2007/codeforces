#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int dp[1 + nmax][2];
int v[1 + nmax];

int solve(int n) {
  dp[1][1] = v[1] ^ 1;
  dp[0][1] = nmax;
  dp[1][0] = nmax;
  
  for(int i = 2;i <= n; i++) 
    for(int h = 0; h < 2; h++) 
      dp[i][h] = std::min(dp[i - 1][!h] + (v[i] ^ h), dp[i - 2][!h] + (v[i] ^ h) + (v[i - 1] ^ h));
  return dp[n][0];
}

void shift(int n) {
  for(int i = 1; i <= n; i++)
    v[i - 1] = v[i];
  v[n] = v[0];
}

int solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  s = "#" + s;  
  for(int i = 1;i <= n; i++)
    if(s[i] == 'L')
      v[i] = 0;
    else
      v[i] = 1;
  int result = solve(n);
  shift(n);
  result = std::min(result, solve(n));
  shift(n);
  result = std::min(result, solve(n));
  shift(n);
  result = std::min(result, solve(n));
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}