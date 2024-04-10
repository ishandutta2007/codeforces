#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::cout << s << '\n';
  }
  return 0;
}