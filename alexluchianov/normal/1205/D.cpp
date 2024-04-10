#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>

using namespace std;

using ll= long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;

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

int findcentroid(int node, int parent, int target){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(parent != to && target < sz[to])
      return findcentroid(to, node, target);
  }
  return node;
}

int side[1 + nmax];
struct Edge{
  int x;
  int y;
  int cost;
};
vector<Edge> sol;

int level[1 + nmax], ptr = 0;

void dfs2(int node, int parent, int coef){
  ptr++;
  level[node] = ptr;
  sol.push_back({parent, node, (level[node] - level[parent]) * coef} );
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs2(to, node, coef);
  }
}

int ind[1 + nmax];
bool compare(int x, int y){
  return sz[x] < sz[y];
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
  dfs(1, 0);
  int centroid = findcentroid(1, 0, sz[1] / 2);
  int sum1 = 0, sum2 = 0;

  dfs(centroid, 0);

  sort(g[centroid].begin(), g[centroid].end(), compare);

  for(int h = g[centroid].size() - 1; 0 <= h; h--){
    int to = g[centroid][h];
    if(sum1 < sum2){
      sum1 += sz[to];
      side[to] = 1;
    } else {
      sum2 += sz[to];
      side[to] = 2;
    }
  }
  assert(n * n * 2 / 9 <= ((sum1 + 1) * (sum2 + 1) - 1) );

  ptr = 0;
  for(int h = 0;h < g[centroid].size(); h++){
    int to = g[centroid][h];
    if(side[to] == 1)
      dfs2(to, centroid, 1);
  }
  ptr = 0;
  for(int h = 0; h < g[centroid].size(); h++){
    int to = g[centroid][h];
    if(side[to] == 2)
      dfs2(to, centroid, sum1 + 1);
  }

  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].x << " " << sol[i].y << " " << sol[i].cost << '\n';
  return 0;
}