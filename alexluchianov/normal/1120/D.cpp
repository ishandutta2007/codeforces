#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const inf = 1000000000;

int v[1 + nmax];
ll dp[1 + nmax][2];

vector<int> g[1 + nmax];
vector<int> sol;

void dfs(int node, int parent){
  ll sum = 0;
  bool sons = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      sum += dp[to][1];
      sons = 1;
    }
  }

  dp[node][0] = sum;
  if(sons == 0)
    dp[node][1] = v[node];
  else
    dp[node][1] = sum;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      if(sum - dp[to][1] + dp[to][0] < dp[node][0])
        dp[node][0] = sum - dp[to][1] + dp[to][0];
  }

  if(dp[node][0] + v[node] < dp[node][1])
    dp[node][1] = dp[node][0] + v[node];
}

int used[1 + nmax], seen[1 + nmax][2];

void touch(int node, int parent, int h){
  if(seen[node][h] == 1)
    return ;
  seen[node][h] = 1;
  ll sum = 0;

  bool sons = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      sum += dp[to][1];
      sons = 1;
    }
  }


  if(h == 1){
    if(dp[node][0] + v[node] == dp[node][1]) {
      used[node] = 1;
      touch(node, parent, 0);
    }

    if(sum == dp[node][1])
      for(int h = 0; h < g[node].size(); h++){
        int to = g[node][h];
        if(to != parent)
          touch(to, node, 1);
      }
  } else {
    int edges = 0;
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(to != parent)
        if(dp[node][0] == sum - dp[to][1] + dp[to][0]) {
          touch(to, node, 0);
          edges++;
        }
    }

    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(to != parent)
        if(1 < edges)
          touch(to, node, 1);
        else if(dp[node][0] != sum - dp[to][1] + dp[to][0])
          touch(to, node, 1);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  touch(1, 0, 1);

  int sol = 0;
  for(int i = 1; i <= n; i++)
    if(used[i] == 1)
      sol++;

  cout << dp[1][1] << " " << sol << '\n';
  for(int i = 1;i <= n; i++)
    if(used[i] == 1)
      cout << i << " ";
  cout << '\n';
  return 0;
}