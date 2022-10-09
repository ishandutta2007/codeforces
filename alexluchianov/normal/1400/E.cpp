#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int const inf = 1000000000;
int v[1 + nmax];

int solve(int from, int to) {
  if(to < from)
    return 0;
  else if(from == to)
    return std::min(v[from], 1);
  int smin = inf;
  for(int i = from; i <= to; i++)
    smin = std::min(smin, v[i]);
  for(int i = from; i <= to; i++)
    v[i] -= smin;
  ll result = smin;
  int last = from - 1;
  for(int i = from; i <= to; i++)
    if(0 == v[i]) {
      result += solve(last + 1, i - 1);
      last = i;
    }
  result += solve(last + 1, to);
  return std::min(to - from + 1LL, result);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::cout << solve(1, n);  
  return 0;
}