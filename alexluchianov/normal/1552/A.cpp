#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::string s2 = s;
  std::sort(s2.begin(), s2.end());
  int result = 0;
  for(int i = 0; i < s.size(); i++) {
    result += (s[i] != s2[i]);
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