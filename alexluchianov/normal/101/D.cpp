#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const nmax = 100000;
ll sz[1 + nmax], path[1 + nmax];
struct Edge{
  int to;
  int cost;
};;
vector<Edge> g[1 + nmax];

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++)
    if(g[node][h].to == parent)
      g[node].erase(g[node].begin() + h);
  sz[node] = 1;
  for(int h = 0; h < g[node].size();h++){
    Edge e = g[node][h];
    if(e.to != parent) {
      path[e.to] += e.cost * 2;
      dfs(e.to, node);
      sz[node] += sz[e.to];
      path[node] += path[e.to];
    }
  }
}

bool compare(Edge x, Edge y){
  return path[x.to] * sz[y.to] < path[y.to] * sz[x.to];
}
ll dp[1 + nmax], curr = 0;

void solve(int node){
  sort(g[node].begin(), g[node].end(), compare);

  dp[node] = curr;
  for(int h = 0; h < g[node].size(); h++){
    Edge e = g[node][h];
    curr += e.cost;
    solve(e.to);
    curr += e.cost;
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
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  dfs(1, 0);
  solve(1);
  ld result = 0;
  for(int i = 1;i <= n; i++)
    result += dp[i];
  cout << setprecision(6) << fixed << result / (n - 1);
  return 0;
}