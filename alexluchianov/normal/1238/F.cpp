#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
vector<int> g[1 + nmax];

int v[1 + nmax];
int dp[1 + nmax];

int result = -1;

void dfs(int node, int parent){
  v[node] = g[node].size() - 1;
  dp[node] = v[node];
  int smax = dp[node];

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      dp[node] = MAX(dp[node], dp[to] + v[node]);
      result = MAX(result, smax + dp[to]);
      if(smax < dp[to] + v[node])
        smax = dp[to] + v[node];
    }
  }
}

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    g[i].clear();
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  result = -1;
  dfs(1, 0);
  cout << result + 2 << '\n';
}

void fast_IO(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main()
{
  fast_IO();
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}