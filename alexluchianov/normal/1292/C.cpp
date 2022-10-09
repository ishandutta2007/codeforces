#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 3000;
vector<int> g[1 + nmax];
int dist[1 + nmax][1 + nmax];
int cost[1 + nmax][1 + nmax];
int sz[1 + nmax];

void dfs(int node, int parent, int original){
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dist[original][to] = dist[original][node] + 1;
      dfs(to, node, original);
      sz[node] += sz[to];
    }
  }
}

void putcosts(int node, int parent, int original, int coef){
  cost[original][node] = coef * sz[node];
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      putcosts(to, node, original, coef);
  }
}

void processnode(int node, int n){
  for(int i = 1;i <= n; i++)
    sz[i] = 0;
  dfs(node, 0, node);
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    putcosts(to, node, node, sz[node] - sz[to]);
  }
}

struct Lant{
  int x;
  int y;
  int l;
  bool operator < (Lant const &a) const{
    return l < a.l;
  }
};
ll dp[1 + nmax][1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for(int i = 1;i <= n; i++)
    processnode(i, n);

  vector<Lant> v;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      if(i != j) {
        v.push_back({i, j, dist[i][j]});
      }
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++){
    int x = v[i].x;
    int y = v[i].y;
    if(v[i].l == 1)
      dp[x][y] = cost[x][y];
    for(int h = 0; h < g[x].size(); h++){
      int x2 = g[x][h];
      if(dist[x2][y] == dist[x][y] + 1)
        dp[x2][y] = MAX(dp[x2][y], dp[x][y] + cost[x2][y]);
    }
    for(int h = 0; h < g[y].size(); h++){
      int y2 = g[y][h];
      if(dist[x][y2] == dist[x][y] + 1)
        dp[x][y2] = MAX(dp[x][y2], dp[x][y] + cost[x][y2]);
    }
  }

  ll result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      result = MAX(result, dp[i][j]);
  cout << result;
  return 0;
}