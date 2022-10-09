#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;
int dp[1 + nmax];

ll solve(ll number) {
  if(number <= 20)
    return dp[number];

  if(number == 0)
    return 0;
  if(number % 4 == 2)
    return number - solve(number / 2);
  else
    return number - solve(number - 1);
}

int main() {
  int t;
  std::cin >> t;
  for(int i = 1;i <= nmax; i++) {
    if(i % 2 == 0)
      dp[i] = i - std::min(dp[i / 2], dp[i - 1]);
    else
      dp[i] = i - dp[i - 1];
  }
  for(int testcase = 1; testcase <= t; testcase++) {
    ll number;
    std::cin >> number;
    std::cout << solve(number) << '\n';
  }
}