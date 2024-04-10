#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 400000;
vector<int> g[1 + nmax];
int sz[1 + nmax];

void dfs(int node, int parent){
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      sz[node] += sz[to];
    }
  }
}

int extract(int node, int parent, int target){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(parent != to && target < sz[to])
      return extract(to, node, target);
  }
  return node;
}

int sol[1 + nmax];
int n;

void solve(int node, int parent, int above){
  if(n - sz[node]  - above <= n / 2)
    sol[node] |= 1;
  else
    sol[node] = 0;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      solve(to, node, above);
  }
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int centroid = extract(1, 0, n / 2);

  dfs(centroid, 0);
  sol[centroid] = 1;
  int smax1 = 0, smax2 = 0;


  for(int h = 0; h < g[centroid].size(); h++){
    int to = g[centroid][h];
    if(sz[to] == n / 2 && (n - sz[to]) == n / 2)
      smax1 = smax2 = n / 2;

    if(smax1 < sz[to]){
      smax2 = smax1;
      smax1 = sz[to];
    } else
      smax2 = max(smax2, sz[to]);
  }

  for(int h = 0; h < g[centroid].size(); h++){
    int to = g[centroid][h];
    if(smax1 == sz[to])
      solve(to, centroid, smax2);
    else
      solve(to, centroid, smax1);
  }

  for(int i = 1;i <= n; i++)
    cout << sol[i] << " " ;
  return 0;
}