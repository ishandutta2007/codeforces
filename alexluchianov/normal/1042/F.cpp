#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
vector<int> g[1 + nmax];
pair<int,int> dp[1 + nmax];

void dfs(int node, int parent, int k){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node, k);
  }
  if(g[node].size() == 0)
    dp[node] = {1, 0};
  else {
    vector<int> sol;
    int result = 1, dist = -nmax;
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      sol.push_back(dp[to].second + 1);
      result += dp[to].first;
    }

    sort(sol.begin(), sol.end());
    for(int i = 0; i < sol.size(); i++){
      if(dist + sol[i] <= k){
        dist = sol[i];
        result--;
      }
    }
    dp[node] = {result, dist};
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for(int i = 1;i <= n; i++)
    if(1 < g[i].size()){
      dfs(i, 0, k);
      cout << dp[i].first << '\n';
      return 0;
    }
  return 0;
}
/*
5 1
1 2
2 3
3 4
4 5

*/