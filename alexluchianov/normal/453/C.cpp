#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];

vector<int> path;
int seen[1 + nmax], sol[1 + nmax];

void dfs(int node, int parent){
  seen[node] = 1;
  path.push_back(node);
  sol[node] ^= 1;

  for(int h = 0;h < g[node].size(); h++){
    int to = g[node][h];
    if(seen[to] == 0) {
      dfs(to, node);
      path.push_back(node);
      sol[node] ^= 1;
    }
  }

  if(sol[node] == 1){
    path.push_back(parent);
    sol[parent] ^= 1;
    path.push_back(node);
    sol[node] ^= 1;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    cin >> sol[i];
  for(int i = 1;i <= n; i++)
    if(sol[i] == 1) {
      dfs(i, 0);
      break;
    }

  for(int i = 1;i <= n; i++)
    if(sol[i] == 1) {
      cout << -1;
      return 0;
    }

  if(sol[0] == 1) {
    cout << path.size() - 3 << '\n';
    for(int i = 1;i < path.size() - 2; i++)
      cout << path[i] << " ";
  } else {
    cout << path.size() << '\n';
    for(int i = 0; i < path.size(); i++)
      cout << path[i] << " ";
  }
  return 0;
}