#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
vector<int> g[1 + nmax];
int dp[1 + nmax], sz[1 + nmax];

void dfs(int node, int parent, int level){
  sz[node] = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node, !level);
      sz[node] += sz[to];
    }
  }

  if(sz[node] == 0) {
    dp[node] = 1;
    sz[node] = 1;
  } else{
    if(level == 1)
      dp[node] = 1;
    else
      dp[node] = 0;
    for(int h = 0;h < g[node].size(); h++){
      int to = g[node][h];
      if(to != parent){
        if(level == 0)
          dp[node] = MAX(dp[node], sz[node] - sz[to] + dp[to]);
        else
          dp[node] += dp[to] - 1;
      }
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
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0, 0);
  cout << dp[1] << " ";
  dfs(1, 0, 1);
  cout << sz[1] + 1 - dp[1] << '\n';
  return 0;
}