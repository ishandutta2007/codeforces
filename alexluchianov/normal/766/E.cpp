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
int const lgmax = 20;
vector<int> g[1 + nmax];
int v[1 + nmax];

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  for(int h = 0; h < g[node].size(); h++)
    dfs(g[node][h], node);
}

pair<int,int> dfsbit(int node, int key, ll &result){
  int sum0 = 0, sum1 = 0;
  int active = (0 < (v[node] & (1 << key)));
  if(active == 0)
    sum0 = 1;
  else
    sum1 = 1;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    pair<int,int> sol = dfsbit(to, key, result);
    result += (1LL<<key) * sol.first * sum1;
    result += (1LL<<key) * sol.second * sum0;
    if(active == 1)
      swap(sol.first, sol.second);
    sum0 += sol.first;
    sum1 += sol.second;
  }
  return {sum0, sum1};
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  ll result = 0;
  for(int i = 1;i <= n; i++)
    result += v[i];
  for(int i = 0; i < lgmax; i++)
    dfsbit(1, i, result);
  cout << result;
  return 0;
}