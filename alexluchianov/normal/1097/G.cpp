#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const kmax = 200;
int const modulo = 1000000007;

std::vector<int> g[5 + nmax];
int sz[5 + nmax], comb[5 + kmax][5 + kmax];
int dp[5 + nmax][5 + kmax][2][2], dp2[5 + kmax][2][2];

void dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
  sz[node] = 1;
  dp[node][0][0][0] = 1;
  dp[node][0][1][0] = 1;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      for(int i = 0;i <= kmax && i <= sz[node]; i++)
        for(int j = 0; j + i<= kmax && j <= sz[to]; j++)
          for(int h = (0 < i); h < 2; h++)
            for(int h2 = 0; h2 <= h; h2++)
              if(0 < dp[node][i][h][h2]) {
                for(int h3 = (0 < j); h3 < 2; h3++)
                  for(int h4 = 0; h4 <= h3; h4++) {
                    dp2[i + j][h | h3][(h3 < h2) | (h < h4)] = (dp2[i + j][h | h3][(h3 < h2) | (h < h4)] 
                        +1LL *  dp[node][i][h][h2] * dp[to][j][h3][h4]) % modulo;
                    if(h3 == 1)
                      dp2[i + j + 1][h | h3][(h3 < h2) | (h < h4) | (h + h3 < 2)] = (dp2[i + j + 1][h | h3][(h3 < h2) | (h < h4) | (h + h3 < 2)] 
                          + 1LL * dp[node][i][h][h2] * dp[to][j][h3][h4]) % modulo;
                  }
              }
      sz[node] += sz[to];
      for(int i = 0; i <= kmax; i++)
        for(int h = 0; h < 2; h++)
          for(int h2 = 0; h2 <= h; h2++) {
            dp[node][i][h][h2] = dp2[i][h][h2];
            dp2[i][h][h2] = 0;
          }
    }
  }
}

int com[1 + nmax][1 + kmax];

void precompute() {
  com[0][0] = 1;
  for(int i = 1;i <= kmax; i++) {
    for(int j = 1; j <= i; j++)
      com[i][j] = (1LL * com[i - 1][j - 1] * j + 1LL * com[i - 1][j] * j) % modulo;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  precompute();
  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int result = 0;

  for(int i = 1;i <= k; i++)
    result = (result + 1LL * com[k][i] * dp[1][i][1][0]) % modulo;
  std::cout << result << '\n';
  return 0;
}