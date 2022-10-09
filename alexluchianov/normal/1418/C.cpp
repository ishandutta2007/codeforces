#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

int dp[1 + nmax], dp2[1 + nmax];
int v[1 + nmax];

void solve() {
  int n;
  std::cin >> n;
  for(int i = 0; i <= n; i++)
    dp[i] = dp2[i] = 5 + nmax;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  dp[1] = v[1];
  dp2[0] = 0;
  for(int i = 2;i <= n; i++) {
    dp[i] = std::min(dp2[i - 1] + v[i], dp2[i - 2] + v[i- 1] + v[i]);
    dp2[i] = std::min(dp[i - 1], dp[i - 2]);
  }
  std::cout << std::min(dp[n], dp2[n]) << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}