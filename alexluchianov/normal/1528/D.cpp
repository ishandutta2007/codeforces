#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 600;
int const inf = 1500000000;

int cost[1 + nmax][1 + nmax];
int dp[1 + nmax], seen[1 + nmax];

void solve(int n, int start) {
  for(int i = 1;i <= n; i++) {
    dp[i] = inf;
    seen[i] = 0;
  }

  for(int i = 1; i <= n; i++)
    if(cost[start][i] != -1)
      dp[i] = cost[start][i];

  for(int i = 1;i <= n; i++) {
    for(int j = 2;j <= n; j++)
      dp[j] = std::min(dp[j], dp[j - 1] + 1);
    
    dp[1] = std::min(dp[n] + 1, dp[1]);
    for(int j = 2;j <= n; j++)
      dp[j] = std::min(dp[j], dp[j - 1] + 1);

    int pivot = -1;
    for(int j = 1;j <= n; j++)
      if(seen[j] == 0)
        if(pivot == -1 || dp[j] < dp[pivot])
          pivot = j;
    
    seen[pivot] = 1;
    
    for(int j = 1;j <= n; j++)
      if(cost[pivot][j] != -1) {
        int target = j + dp[pivot];
        if(n < target)
          target = (target - 1) % n + 1;

        if(dp[pivot] + cost[pivot][j] < dp[target]) {
          dp[target] = dp[pivot] + cost[pivot][j];
        }
      }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      cost[i][j] = -1;
  for(int i = 1;i <= m; i++) {
    int x, y, cost_;
    std::cin >> x >> y >> cost_;
    x++;
    y++;
    cost[x][y] = cost_;
  }

  for(int i = 1;i <= n; i++) {
    solve(n, i);
    for(int j = 1;j <= n; j++) {
      if(j == i)
        std::cout << 0 << " ";
      else
        std::cout << dp[j] << " ";
    }
    std::cout << '\n';
  }
  return 0;
}