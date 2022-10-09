#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

bool valid(int a, int b, int k) {
  int n = a + b;
  int c = n / 2 + n % 2, d = n / 2;
  if(a < c) {
    int dist = c - a, aux = std::min(c - dist, d);
    k -= dist;
    if(0 <= k && k <= aux * 2 && k % 2 == 0)
      return 1;
    return 0; 
  } else {
    int dist = a - c, aux = std::min(c, d - dist);
    k -= dist;
    if(0 <= k && k <= aux * 2 && k % 2 == 0)
      return 1;
    return 0;
  }
}

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::vector<int> sol;
  for(int i = 0; i <= a + b; i++)
    if(valid(a, b, i) == 1 || valid(b, a, i) == 1)
      sol.push_back(i);
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}