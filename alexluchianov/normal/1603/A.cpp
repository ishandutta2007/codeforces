#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> v;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    v.push_back(val);
  }
  int ptr = v.size() - 1;
  while(0 < v.size() && 0 <= ptr) {
    if(0 < (v[ptr] % (ptr + 2))) {
      v.erase(v.begin() + ptr);
      ptr = v.size() - 1;
    } else
      ptr--;
  }
  return v.size() == 0;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    if(solve())
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  return 0;
}