#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const lgmax = 20;
vector<int> g[1 + nmax];
int level[1 + nmax], far[1 + lgmax][1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  far[0][node] = parent;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

void computefar(int n){
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}

int getlca(int x, int y){
  if(level[x] < level[y])
    swap(x, y);
  for(int h = lgmax; 0 <= h; h--)
    if(level[y] <= level[x] - (1 << h))
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax; 0 <= h; h--)
    if(far[h][x] != far[h][y]){
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}
int sum[1 + nmax];
vector<pair<int,int>> edge;

void cleardfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      cleardfs(to, node);
      sum[node] += sum[to];
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
    edge.push_back({x, y});
  }
  dfs(1, 0);
  computefar(n);
  int m;
  cin >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    int lca = getlca(x, y);
    sum[x]++;
    sum[y]++;
    sum[lca] -= 2;
  }
  cleardfs(1, 0);
  for(int i = 0;i < n - 1; i++){
    int x = edge[i].first, y = edge[i].second;
    if(level[x] < level[y])
      swap(x, y);
    cout << sum[x] << " ";
  }

  return 0;
}