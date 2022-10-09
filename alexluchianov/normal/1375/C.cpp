#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[1 + nmax];

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  if(v[1] < v[n])
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
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