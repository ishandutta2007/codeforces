#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const lgmax = 30;

int v[1 + nmax];
int frec[1 + nmax];

int lg(int number) {
  return 31 - __builtin_clz(number);
}

void solve() {
  int n;
  std::cin >> n;
  for(int i = 0;i <= lgmax; i++)
    frec[i] = 0;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    frec[lg(v[i])]++;
  }
  ll result = 0;
  for(int i = 0;i <= lgmax; i++)
    result += 1LL * frec[i] * (frec[i] - 1) / 2;
  std::cout << result << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}