#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  ll result = 0;
  for(int i = 0; i < s.size(); i += 2)
    std::cout << s[i];
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}