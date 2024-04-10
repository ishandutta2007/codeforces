#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 4000;
ll const inf = 1000000000000000000;

int sz[5 + nmax], v[5 + nmax];
ll dp[5 + nmax][5 + nmax];
int k;

int divide(int from, int to) {
  if(from -1 == to)
    return 0;

  int mid = from;
  for(int j = from; j <= to; j++)
    if(v[j] < v[mid] )
      mid = j;
  sz[mid] = (to - from + 1);
  for(int j = 0; j <= sz[mid]; j++)
    dp[mid][j] = -inf;
  int left = divide(from, mid - 1), right = divide(mid + 1, to);

  for(int j = 0; j <= sz[left];j++)
    for(int j2 = 0; j2 <= sz[right]; j2++) {
      dp[mid][j + j2] = std::max(dp[mid][j + j2], dp[left][j] + dp[right][j2] + 1LL * (- 2 * j * j2) * v[mid] );
      dp[mid][j + j2 + 1] = std::max(dp[mid][j + j2 + 1], dp[left][j] + dp[right][j2] + 1LL * (k - 2 * j * j2 - 2 * j - 2 * j2 - 1) * v[mid] );
    }

  return mid;
}

int main() {
  int n;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::cout << dp[divide(1, n)][k] << '\n';
  return 0;
}