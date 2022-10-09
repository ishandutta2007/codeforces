#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
char color[1 + nmax];
vector<int> g[1 + nmax];
int sz[1 + nmax];

void dfs(int node, int parent){
  sz[node] = 1;
  for(int h = 0;h  < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent && color[to] == 0) {
      dfs(to, node);
      sz[node] += sz[to];
    }
  }
}

int findcentroid(int node, int parent, int targetsz){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent && color[to] == 0){
      if(targetsz / 2 <= sz[to])
        return findcentroid(to, node, targetsz);
    }
  }
  return node;
}

void solve(int node, char level){

  dfs(node, 0);
  int centroid = findcentroid(node, 0, sz[node]);
  color[centroid] = level;

  for(int h = 0; h < g[centroid].size(); h++){
    int to = g[centroid][h];
    if(color[to] == 0)
      solve(to, level + 1);
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  solve(1, 'A');
  for(int i = 1;i <= n; i++)
    cout << color[i] << " ";
  return 0;
}