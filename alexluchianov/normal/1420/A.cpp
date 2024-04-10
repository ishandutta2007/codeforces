#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50000;
int v[1 + nmax];

void solve() {
  int verdict = 0, n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 2; i <= n;i++)
    if(v[i - 1] <= v[i])
      verdict = 1;
  if(verdict == 1)
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}