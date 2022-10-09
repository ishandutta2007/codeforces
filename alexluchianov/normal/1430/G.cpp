#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 18;
int const inf = 1000000000;
int _cost[1 + nmax], cost[(1 << nmax)];
int _inner[1 + nmax], inner[1 + (1 << nmax)];

int dp[(1 << nmax)], last[(1 << nmax)];

int sol[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    x--;
    y--;
    _cost[y] -= w;
    _cost[x] += w;
    _inner[y] |= (1 << x);
  }
  for(int mask = 0; mask < (1 << n); mask++)
    for(int i = 0; i < n; i++)
      if((1 << i) & mask)
        cost[mask] += _cost[i];
  for(int mask = 0; mask < (1 << n); mask++)
    for(int i = 0; i < n; i++)
      if((1 << i) & mask)
        inner[mask] |= _inner[i];

  for(int mask = 0; mask < (1 << n); mask++)
    dp[mask] = inf;
  for(int mask = 0; mask < (1 << n); mask++) {
    if(inner[mask] == 0) {
      dp[mask] = 0;
      last[mask] = mask;
    }
    for(int mask2 = mask; 0 < mask2; mask2 = ((mask2 - 1) & mask))
      if(inner[mask2] == (inner[mask2] & (mask ^ mask2))) {
        if(dp[mask ^ mask2] + cost[mask ^ mask2] < dp[mask]) {
          dp[mask] = dp[mask ^ mask2] + cost[mask ^ mask2];
          last[mask] = mask2;
        }
      }
  }
  int ptr = 0;
  int mask = (1 << n) - 1;
  
  while(0 < mask) { 
    int mask2 = last[mask];

    for(int i = 0; i < n; i++)
      if((1 << i) & mask2)
        sol[i] = ptr;
    ptr++;
    mask ^= mask2;
  }
  for(int i = 0; i < n; i++)
    std::cout << sol[i] << " ";
  return 0;
}