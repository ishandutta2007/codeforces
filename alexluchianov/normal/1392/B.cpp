#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const inf = 1000000000;

void solve() {
  int n;
  ll k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];

  if(3 < k) {
    if(k % 2 == 0)
      k = 4;
    else
      k = 5;
  } 
  for(int i = 1;i <= k; i++) {
    int smax = -inf;
    for(int j = 0;j < n; j++) 
      smax = std::max(smax, v[j]);
    for(int j = 0; j < n; j++)
      v[j] = smax - v[j];
  }
  for(int j = 0; j < n; j++)
    std::cout << v[j] << " ";
  std::cout << '\n';
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