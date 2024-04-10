#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int const nmax = 20;

int getBit(int mask, int bit) {
  return 0 < (mask & (1 << bit));
}

int dp[1 + nmax][1 << nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, k;
  std::cin >> n >> m >> k;
  
  int maskStart = 0, maskStop = 0;
  for(int i = 0; i < k; i++) {
    char val;
    std::cin >> val;
    maskStart |= ((val - '0')<<i);
  }
  for(int i = 0; i < k; i++) {
    char val;
    std::cin >> val;
    maskStop |= ((val - '0')<<i);
  }

  int p[5 + nmax] = {0};
  for(int i = 1;i <= k; i++)
    p[i] = i;
  
  std::vector<int> v(1 + n);
  std::vector<int> v2(1 + n);
  
  v[0] = maskStart;
  
  for(int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    std::swap(p[x], p[y]);

    for(int j = 1; j <= k; j++) {
      v2[i] |= (getBit(maskStop, j - 1) << (p[j] - 1));
    }
    for(int j = 1; j <= k; j++) {
      v[i] |= (getBit(maskStart, j - 1) << (p[j] - 1));
    }
  }

  for(int h = 0; h <= k; h++)
    for(int i = 0; i < (1 << k); i++)
      dp[h][i] = n;
  for(int i = 0; i < n; i++)
    dp[k][v[i]] = std::min(dp[k][v[i]], i);

  for(int h = k; 0 < h; h--)
    for(int mask = 0; mask < (1 << k); mask++)
      for(int h2 = 0; h2 < k; h2++) {
        dp[h - 1][mask ^ (1 << h2)] = std::min(dp[h - 1][mask ^ (1 << h2)], dp[h][mask]);
      }

  /*
  std::cout << "Mask\n";
  for(int i = 0; i <= n; i++)
    std::cout << v[i] << " ";
  std::cout << '\n';
  for(int i = 0; i <= n; i++)
    std::cout << v2[i] << " ";
  std::cout << '\n';
  */

  int smax = -1, xmax = 0, ymax = 0;
  for(int i = 1;i <= n; i++)
    for(int h = smax + 1; h <= k; h++)
      if(dp[h][v2[i]] <= i - m) {
        smax = h;
        xmax = dp[h][v2[i]];
        ymax = i;
      }
  std::cout << smax << '\n';
  std::cout << xmax + 1<< " " << ymax << '\n';

  return 0;
}