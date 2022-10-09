#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
using ll = long long;
int const nmax = 100000;
vector<int> g[1 + nmax];
int t;
vector<pair<int,int>> sol;

void dfs(int node, int parent, int target){
  sol.push_back({node, target});
  int orig = target;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(target == t) {
      sol.push_back({node, orig - 1 - g[node].size() + h});
      target = orig - 1 - g[node].size() + h;
    }
    dfs(to, node, target + 1);
    sol.push_back({node, target + 1});
    target++;
  }

  if(0 < parent) {
    if(orig - 1 < target)
      sol.push_back({node, orig - 1});
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if(n == 1){
    cout << 1 << '\n' << 1 << " " << 0 << '\n';
    return 0;
  }
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  t = 0;
  for(int i = 1;i <= n; i++)
    t = max(t, (int)g[i].size());
  dfs(1, 0, 0);

  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].first << " " << sol[i].second << '\n';

  return 0;
}