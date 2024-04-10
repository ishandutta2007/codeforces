#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;

int const nmax = 200000;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&v](int x, int y) {return v[x] < v[y];});
  int sz = 0, answer = 0;
  for(auto node: ord) {
    if(sz + 1 == v[node]) {
      sz = 0;
      answer++;
    } else
      sz++;
  }
  return answer;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}