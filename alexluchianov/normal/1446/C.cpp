#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const lgmax = 30;
int v[1 + nmax];

int solve(int from, int to, int bit) {
  if(from == to)
    return 1;
  int mid = from;
  for(int i = from + 1;i <= to; i++)
    if((v[i - 1] & (1<<bit)) < (v[i] & (1<<bit)))
      mid = i;
  if(mid == from)
    return solve(from, to, bit - 1);
  else
    return std::max(solve(from, mid - 1, bit - 1), solve(mid, to, bit - 1)) + 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::sort(v + 1, v + n + 1);
  std::cout << n - solve(1, n, lgmax);
  return 0;
}