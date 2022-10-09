#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 3000;

int v[1 + nmax], sz[1 + nmax];

pair<int,ll> combine(pair<int,ll> dpfather, pair<int,ll> dpson, int edge){
  if(edge == 1)
    return {dpfather.first + dpson.first, dpfather.second + dpson.second};
  else
    return {dpfather.first + dpson.first + (0 < dpson.second), dpfather.second};
}

pair<int,ll> dp[1 + nmax][1 + nmax];
pair<int,ll> dp2[1 + nmax];
vector<int> g[1 + nmax];

void computedp(int node, int parent){
  sz[node] = 1;
  dp[node][1] = {0, v[node]};

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      computedp(to, node);
      for(int i = 1;i <= sz[node] + sz[to]; i++)
        dp2[i] = {-1, 0};

      for(int i = sz[node]; 1 <= i; i--)
        for(int j = 1;j <= sz[to]; j++) {
          dp2[i + j] = max(dp2[i + j], combine(dp[node][i], dp[to][j], 0));
          dp2[i + j - 1] = max(dp2[i + j - 1], combine(dp[node][i], dp[to][j], 1));
        }

      for(int i = 1;i <= sz[node] + sz[to]; i++)
        dp[node][i] = dp2[i];
      sz[node] += sz[to];
    }
  }
}

void solve(){
  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    v[i] = val - v[i];
  }
  for(int i = 1;i <= n; i++)
    g[i].clear();
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  computedp(1, 0);

  cout << dp[1][k].first + (0 < dp[1][k].second) << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}