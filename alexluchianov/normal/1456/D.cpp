#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int const inf = 1000000005;

ll t[5 + nmax], v[5 + nmax];
ll dp[5 + nmax][5 + nmax];

ll dist(int x, int y) {
  return fabs(v[x] - v[y]);
}

int main() {
  int n;
  std::cin >> n;
  
  for(int i = 1;i <= n; i++)
    std::cin >> t[i] >> v[i];
  for(int i = 0; i <= n + 1; i++)
    for(int j = 0; j <= n + 1; j++)
      dp[i][j] = inf;

  dp[0][0] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i; j <= n + 1; j++) {
      if(dp[i][j] < inf) {
        if(i + 1 < j) {
          if(t[i] + dist(i, i + 1) <= t[i + 1])
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
        } else if(i + 1 == j) {
          for(int h = j + 1; h <= n; h++) {
            ll tour = std::max(t[j], t[i] + dist(i, h));
            if(tour <= t[h] && (tour + dist(h, i + 2) <= t[i + 2]))
              dp[i + 2][h] = std::min(dp[i + 2][h], tour);
          }
          
        } else if(i == j) {
          for(int h = j + 1; h <= n; h++) {
            ll tour = std::max(t[i], dp[i][j] + dist(i, h));
            if(tour <= t[h] && (tour + dist(h, i + 1) <= t[i + 1]))
              dp[i + 1][h] = std::min(dp[i + 1][h], tour);
          }
        }
      }
    }
  }

  if(dp[n][n] < inf || dp[n - 1][n] < inf)
    std::cout << "YES";
  else
    std::cout << "NO";
  return 0;
}