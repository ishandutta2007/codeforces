#include <iostream>

#define int long long

const int INF = 1'000'000'000'000'000'000;
const int MAXN = 205;

int c[MAXN][MAXN];
int dp[MAXN][MAXN];
int best[MAXN][MAXN];
int score[MAXN][MAXN];
int par[MAXN];

void dfs(int l, int r, int p) {
  if(r < l)
    return;
  int cur = best[l][r];
  par[cur] = p;
  dfs(l, cur-1, cur);
  dfs(cur+1, r, cur);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      std::cin >> c[i][j];
      c[i][j] = c[i][j] + c[i-1][j] + c[i][j-1] - c[i-1][j-1];
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      score[i][j] = c[i-1][j] - c[i-1][i-1] + c[n][j] - c[n][i-1] - c[j][j] + c[j][i-1];
    }
  }

  for(int i = 1; i <= n; i++) {
    dp[i][i] = score[i][i];
    best[i][i] = i;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 1; j+i-1 <= n; j++) {
      int k = j+i-1;
      dp[j][k] = INF;
      int cur = score[j][k];
      for(int l = j; l <= k; l++) {
        int next = cur + dp[j][l-1] + dp[l+1][k];
        if(next < dp[j][k]) {
          dp[j][k] = next;
          best[j][k] = l;
        }
      }
    }
  }

  dfs(1, n, 0);

  for(int i = 1; i <= n; i++)
    std::cout << par[i] << " ";
  std::cout << "\n";

  return 0;
}