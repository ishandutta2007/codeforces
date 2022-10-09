#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 200000;
int level[1 + nmax];
vector<int> g[1 + nmax];

struct Path{
  int x;
  int y;
  int z;
};
vector<Path> overallsol;

bool dfs(int node, int parent){
  vector<int> sol;
  level[node] = level[parent] + 1;
  int result = 0;

  for(int h = 0;h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      if(level[to] == 0) {
        if(dfs(to, node) == 0)
          sol.push_back(to);
      } else if(level[to] < level[node])
        sol.push_back(to);
    }
  }
  while(2 <= sol.size()){
    overallsol.push_back({sol[sol.size() - 1], node, sol[sol.size() - 2]});
    sol.pop_back();
    sol.pop_back();
  }

  if(sol.size() == 0 || parent == 0)
    return 0;
  else {
    overallsol.push_back({sol[0], node, parent});
    sol.pop_back();
    return 1;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n;i++)
    if(level[i] == 0) {
      dfs(i, 0);
    }

  cout << overallsol.size() << '\n';
  for(int i = 0; i < overallsol.size(); i++)
    cout << overallsol[i].x << " " << overallsol[i].y << " " << overallsol[i].z << '\n';
  return 0;
}