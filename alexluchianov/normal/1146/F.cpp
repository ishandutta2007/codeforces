#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 200000;
int const modulo = 998244353;
vector<int> g[1 + nmax];
int dp[1 + nmax], dp2[1 + nmax];

int temp[1 + nmax][3];

void dfs(int node){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to);
  }
  if(g[node].size() == 0) {
    dp[node] = dp2[node] = 1;
    return ;
  }

  temp[0][0] = 1;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    temp[h + 1][0] = 1LL * temp[h][0] * dp[to] % modulo;
    temp[h + 1][1] = (1LL * temp[h][0] * dp2[to] + 1LL * temp[h][1] * dp[to]) % modulo;
    temp[h + 1][2] = (1LL * temp[h][1] * dp2[to] + 1LL * temp[h][2] * (dp[to] + dp2[to])) % modulo;
  }
  dp[node] = (temp[g[node].size()][0] + temp[g[node].size()][2]) % modulo;
  dp2[node] = (temp[g[node].size()][1] + temp[g[node].size()][2]) % modulo;
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
  dfs(1);
  cout << dp[1];
  return 0;
}