#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 10;
int v[1 + nmax];
int dp[(1<<nmax)];

int lg(int number) {
  return 31 - __builtin_clz(number);
}

bool solve() {
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++) {
    std::cin >> v[i];
    v[i] = std::max(v[i], -v[i]);
  }

  for(int mask = 1; mask < (1 << n); mask++) {
    int bit = lg(mask ^ (mask & (mask - 1)));
    dp[mask] = dp[mask & (mask - 1)] + v[bit];
  }
  for(int mask = 1; mask < (1 << n); mask++) {
    for(int mask2 = mask; 0 < mask2; mask2 = (mask & (mask2 - 1)))
      if(dp[mask] == dp[mask2] * 2)
        return true;
  }
  return false;
}

int main() {
  int t;
  std::cin >> t;
  
  for(int testcase = 1; testcase <= t; testcase++) {
    if(solve() == 1)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }

  return 0;
}