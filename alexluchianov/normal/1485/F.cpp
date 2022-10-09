#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;

int const nmax = 200000;
int const modulo = 1000000007;

std::map<ll, int> mp;

int solve() {
  int n;
  std::cin >> n;

  int result = 1;
  ll offset = 0;
  mp.clear();
  mp[0] = 1;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    offset += val;
    int coef = mp[val - offset];
    mp[val - offset] = result;
    result = (modulo + 1LL * result * 2 - coef) % modulo;
  }
  return result;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}