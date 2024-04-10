#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
ll cost[1 + nmax], seen[1 + nmax];
struct Edge{
  int to;
  int id;
};
vector<Edge> g[1 + nmax];
ll sol[1 + nmax], level[1 + nmax];
int far[1 + nmax], faredge[1 + nmax];

void dfs(int node, pair<int,Edge> &backup){
  for(int h = 0; h < g[node].size(); h++){
    Edge e = g[node][h];
    if(level[e.to] == 0) {
      level[e.to] = level[node] + 1;
      far[e.to] = node;
      faredge[e.to] = e.id;

      dfs(e.to, backup);
      sol[e.id] = -cost[e.to];
      cost[e.to] += sol[e.id];
      cost[node] += sol[e.id];
    } else if(level[e.to] < level[node] && (level[node] - level[e.to]) % 2 == 0){
      backup = {node, e};
    }
  }
}

int coef(int l){
  if(level[l] % 2 == 0)
    return -1;
  else
    return 1;
}

void solve(int node){
  level[node] = 1;
  pair<int,Edge> backup(0, {0, 0});
  dfs(node, backup);

  if(0 != cost[node]){
    ll surplus = cost[node];

    if(backup.first == 0)
      return ;
    else {
      int stop = backup.second.to;
      while(stop != node){
        sol[faredge[stop]] += surplus * coef(stop);
        cost[stop] += surplus * coef(stop);
        cost[far[stop]] += surplus * coef(stop);
        stop = far[stop];
      }
      stop = backup.second.to;

      surplus /= 2;
      int start = backup.first;
      sol[backup.second.id] -= surplus * coef(start);
      cost[start] -= surplus * coef(start);
      cost[stop] -= surplus * coef(start);

      while(start != stop){
        sol[faredge[start]] += surplus * coef(start);
        cost[start] += surplus * coef(start);
        cost[far[start]] += surplus * coef(start);
        start = far[start];
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> cost[i];

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }
  for(int i = 1;i <= n; i++)
    if(level[i] == 0)
      solve(i);

  for(int i = 1;i <= n; i++)
    if(cost[i] != 0) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  for(int i = 1;i <= m; i++)
    cout << -sol[i] << '\n';
  return 0;
}