#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100000;
int const modulo = 1000000007;
vector<int> g[1 + nmax];

int dp[1 + nmax][2];
int dp2[1 + nmax][2][2][2];

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
  }
  for(int h = 1; h <= g[node].size(); h++)
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++)
          dp2[h][i][j][k] = 0;
  dp2[0][0][0][0] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++){
          dp2[h + 1][i][j][k] += dp2[h][i][j][k];

          if(modulo <= dp2[h + 1][i][j][k])
            dp2[h + 1][i][j][k] -= modulo;

          dp2[h + 1][i][j | 1][k]     += 1LL * dp2[h][i][j][k] * (modulo + dp[to][0] - 1) % modulo;
          dp2[h + 1][i ^ 1][j][k | 1] += 1LL * dp2[h][i][j][k] * dp[to][1] % modulo;
          if(modulo <= dp2[h + 1][i][j | 1][k])
            dp2[h + 1][i][j | 1][k] -= modulo;
          if(modulo <= dp2[h + 1][i ^ 1][j][k | 1])
            dp2[h + 1][i ^ 1][j][k | 1] -= modulo;
        }
  }
  dp[node][1] = (dp2[g[node].size()][0][0][0] + dp2[g[node].size()][0][0][1] * 2LL +
                 dp2[g[node].size()][0][1][0] + dp2[g[node].size()][0][1][1] * 2LL
                  ) % modulo;
  dp[node][0] = (dp2[g[node].size()][1][0][1] + dp2[g[node].size()][1][1][1] * 2LL + 1) % modulo;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 2;i <= n; i++){
    int parent;
    cin >> parent;
    g[parent].push_back(i);
  }
  dfs(1, 0);
  cout << (-1LL + modulo + dp[1][0] + dp[1][1]) % modulo;
  return 0;
}