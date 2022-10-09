#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 500;

char v[5 + nmax], v2[5 + nmax];
int pre[5 + nmax], edges[5 + nmax][2];

void precompute(int m) {
  int ptr = 0;
  for(int i = 2;i <= m; i++) {
    while(true) {
      if(v2[i] == v2[1 + ptr]) {
        ptr++;
        pre[i] = ptr;
        break;
      } else if(0 == ptr) {
        pre[i] = 0;
        break;
      } else {
        ptr = pre[ptr];
      }
    }
  }

  for(int i = 0;i <= m; i++) {
    for(char ch = '0'; ch <= '1'; ch++) {
      int curr = i;
      while(true) {
        if(curr < m && v2[curr + 1] == ch) {
          curr++;
          break;
        } else if(0 < curr) {
          curr = pre[curr];
        } else {
          break;
        }
      }
      edges[i][ch - '0'] = curr;
    }
  }
}

int dp[5 + nmax][5 + nmax];
int dp2[5 + nmax][5 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= m; i++)
    std::cin >> v2[i];
  precompute(m);

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++) 
      dp[i][j] = dp2[i][j] = n * 2;
  dp[0][0] = 0;
  for(int step = 1; step <= n; step++) {
    int lim = std::min(step, m);
    int lim2 = std::max(0, step - m + 1);
    for(int i = 0; i <= lim2; i++)
      for(int j = 0; j <= lim; j++) {
        for(int h = 0; h < 2; h++) {
          dp2[i + (edges[j][h] == m)][edges[j][h]] = std::min(dp2[i + (edges[j][h] == m)][edges[j][h]], dp[i][j] + (h != (v[step] - '0')));
        }
      }
    for(int i = 0; i <= lim2; i++)
      for(int j = 0; j <= lim; j++) {
        dp[i][j] = dp2[i][j];
        dp2[i][j] = n * 2;
      }
  }
  for(int i = 0; i <= n - m + 1; i++) {
    int result = dp[i][0];
    for(int j = 0; j <= m; j++) {
      result = std::min(result, dp[i][j]);
    }
    if(n < result) {
      std::cout << -1 << " ";
    } else
      std::cout << result << " ";
  }
  std::cout << '\n';
  return 0;
}