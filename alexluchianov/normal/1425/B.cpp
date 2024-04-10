#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
int const modulo = 1000000007;

std::vector<int> g[1 + nmax];
int seen[1 + nmax];

int explore(int node, int last) {
  seen[node] = 1;
  if(node == 1)
    return 1;
  else
    return 1 + explore(g[node][0] + g[node][1] - last, node);
}

int dp[1 + nmax][1 + nmax * 2];
int dp2[1 + nmax][1 + nmax * 2];
int dp3[1 + nmax][1 + nmax * 2];
int dp4[1 + nmax][1 + nmax * 2];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> v;
  v.push_back(0);
  for(int h = 0;h < g[1].size(); h++) {
    int to = g[1][h];
    if(seen[to] == 0) 
      v.push_back(explore(to, 1));
  }
  dp[0][nmax] = 1;
  dp3[0][nmax] = 1;
  dp2[v.size()][nmax] = 1;
  dp4[v.size()][nmax] = 1;

  for(int i = 1;i < v.size(); i++) {
    for(int j = 0; j <= nmax * 2; j++) {
      dp[i][j] = dp[i - 1][j];
      if(v[i] <= j) {
        dp[i][j] += dp[i - 1][j - v[i]];
        dp3[i][j] += dp3[i - 1][j - v[i]];
        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;
        if(modulo <= dp3[i][j])
          dp3[i][j] -= modulo;
      }

      if(j + v[i] <= nmax * 2) {
        dp[i][j] += dp[i - 1][j + v[i]];
        dp3[i][j] += dp3[i - 1][j + v[i]];
        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;
        if(modulo <= dp3[i][j])
          dp3[i][j] -= modulo;
      }
    }
  }
  for(int i = v.size() - 1; 1 <= i; i--) {
    for(int j = 0; j <= nmax * 2; j++) {
      dp2[i][j] = dp2[i + 1][j];
      if(v[i] <= j) {
        dp2[i][j] += dp2[i + 1][j - v[i]];
        dp4[i][j] += dp4[i + 1][j - v[i]];
      }

      if(modulo <= dp2[i][j])
        dp2[i][j] -= modulo;
      if(modulo <= dp4[i][j])
        dp4[i][j] -= modulo;

      if(j + v[i] <= nmax * 2) {
        dp2[i][j] += dp2[i + 1][j + v[i]];
        dp4[i][j] += dp4[i + 1][j + v[i]];
      }

      if(modulo <= dp2[i][j])
        dp2[i][j] -= modulo;
      if(modulo <= dp4[i][j])
        dp4[i][j] -= modulo;
    }
  }

  ll result = dp3[v.size() - 1][nmax];
  for(int i = 1;i < v.size(); i++) {
    for(int j = -v[i] + 1; j <= v[i] -1; j++) {
      int part = 0;
      if(j == -v[i] + 1 || j == v[i] - 1)
        part = 1;
      else
        part = 2;
      for(int h = 0; h <= 2 * nmax; h++) {
        if(part == 2) {
          if(0 <= (2 * nmax - h) + j && (2 * nmax - h) + j <= 2 * nmax) {
            result += 2LL * dp[i - 1][h] * dp2[i + 1][(2 * nmax - h) + j] % modulo;
            if(modulo <= result)
              result -= modulo;
          }
        } else { 
          if(0 <= (2 * nmax - h) + j && (2 * nmax - h) + j <= 2 * nmax) {
            result += 2LL * dp3[i - 1][h] * dp4[i + 1][(2 * nmax - h) + j] % modulo;
            if(modulo <= result)
              result -= modulo;
          }
        }
      }
    }

  }
  std::cout << result;
  return 0;
}