#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax], g2[1 + nmax];
int seen[1 + nmax];

void dfs(int node, vector<int> &fset, int color){
  seen[node] = color;
  fset.push_back(node);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(seen[to] == 0)
      dfs(to, fset, color);
  }
}

int solve(int node){
  vector<int> fset;
  int color = node;
  dfs(node, fset, color);

  for(int i = 0; i < fset.size(); i++){
    node = fset[i];
    for(int h = 0; h < g2[node].size(); h++){
      int to = g2[node][h];
      if(seen[to] == color)
        return 0;
    }
  }
  return fset.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k, m;
  cin >> n >> k;
  for(int i = 1;i <= k; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cin >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g2[x].push_back(y);
    g2[y].push_back(x);
  }
  int result = 0;
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0){
      int result2 = solve(i);
      result = MAX(result, result2);
    }
  cout << result;
  return 0;
}