#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const inf = 1000000000;

char v[4][1 + nmax];
int dp[10], dp2[10];

int hasbit(int mask, int bit) {
  return (0 < (mask & (1 << bit)));
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  if(4 <= n && 4 <= m)
    std::cout << -1;
  else {
    if(m < n) { 
      for(int i = 0;i < n; i++)
        for(int j = 0;j < m; j++) {
          std::cin >> v[j][i];
          v[j][i] -= '0';
        }
      std::swap(n, m);
    } else
      for(int i = 0;i < n; i++)
        for(int j = 0;j < m; j++) {
          std::cin >> v[i][j];
          v[i][j] -= '0';
        }
    
    int lim = (1 << n);
    
    for(int i = 0;i < lim; i++) {
      dp[i] = 0;
      for(int j = 0; j < n; j++)
        dp[i] += (hasbit(i, j) ^ v[j][0]);
    }

    for(int i = 1; i < m; i++) {
      for(int j = 0; j < lim; j++)
        dp2[j] = inf;
      for(int mask = 0; mask < lim; mask++) {
        if(dp[mask] < inf) {
          for(int mask2 = 0; mask2 < lim; mask2++) {
            int valid = 1, cost = 0;
            
            for(int j = 0; j < n; j++)
              cost += (hasbit(mask2, j) ^ v[j][i]);
            for(int j = 0; j < n - 1; j++) {
              int result = hasbit(mask, j) + hasbit(mask, j + 1) + hasbit(mask2, j) + hasbit(mask2, j + 1);
              if(result % 2 == 0) {
                valid = 0;
                break;
              }
            }

            if(valid == 1) 
              dp2[mask2] = std::min(dp2[mask2], dp[mask] + cost);
          }
        }
      }
      for(int j = 0; j < lim; j++)
        dp[j] = dp2[j];

    }
    int result = inf;
    for(int j = 0; j < lim; j++)
      result = std::min(result, dp[j]);
    std::cout << result << '\n';
  }
  return 0;
}