#include <iostream>
#include <vector>

using ll = long long;

int solve() {
  std::string s;
  std::cin >> s;
  int result = 0;
  for(int i = 0; i < s.size(); i++)
    result = std::max(result, s[i] - '0');
  return result;
}
int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}