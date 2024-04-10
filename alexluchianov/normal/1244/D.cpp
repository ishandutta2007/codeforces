#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int const nmax = 100000;

vector<int> g[1 + nmax];
int v[1 + nmax][4];
int linear[1 + nmax];

void dfs(int node, int parent, int level){
  linear[level] = node;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node, level + 1);
  }
}
int sol[1 + nmax];

ll tryit(int n, int color1, int color2){
  sol[linear[1]] = color1;
  sol[linear[2]] = color2;
  for(int i = 3;i <= n; i++)
    sol[linear[i]] = 6 - sol[linear[i - 1]] - sol[linear[i - 2]];
  ll cost = 0;
  for(int i = 1;i <= n; i++)
    cost += v[i][sol[i]];
  return cost;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i][1];
  for(int i = 1;i <= n; i++)
    cin >> v[i][2];
  for(int i = 1; i <= n; i++)
    cin >> v[i][3];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = 1;
  for(int i = 1;i <= n; i++)
    if(g[i].size() == 1)
      root = i;

  for(int i = 1;i <= n; i++)
    if(2 < g[i].size()){
      cout << -1;
      return 0;
    }
  dfs(root, 0, 1);
  ll smin = tryit(n, 1, 2);
  for(int i = 1;i <= 3; i++)
    for(int j = 1; j <= 3; j++)
      if(i != j){
        ll val = tryit(n, i, j);
        if(val < smin)
          smin = val;
      }

  for(int i = 1;i <= 3; i++)
    for(int j = 1;j <= 3; j++)
      if(i != j){
        ll val = tryit(n, i, j);
        if(val == smin){
          cout << smin << '\n';
          for(int k = 1;k <= n; k++)
            cout << sol[k] << " ";
          cout << '\n';
          return 0;
        }
      }

  return 0;
}