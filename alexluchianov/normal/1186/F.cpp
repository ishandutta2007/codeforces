#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;

vector<int> g[1 + nmax];

struct Edge{
  int x;
  int y;
  int active;
};

Edge edge[1 + nmax];
vector<int> sol;

vector<int> lant1, lant2;

bool dfs(int node, vector<int> &lant){
  while(0 < g[node].size() && edge[g[node].back()].active == 0)
    g[node].pop_back();
  if(g[node].size() == 0)
    return 0;

  int pos = g[node].back();
  edge[pos].active = 0;
  lant.push_back(pos);
  dfs(edge[pos].x + edge[pos].y - node, lant);
  return 1;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(i);
    g[y].push_back(i);
    edge[i] = {x, y, 1};
  }

  for(int i = 1;i <= n; i++){
    while(true) {
      int color = 1;
      lant1.clear();
      lant2.clear();
      dfs(i, lant1);
      dfs(i, lant2);
      reverse(lant1.begin(), lant1.end());
      lant1.insert(lant1.end(), lant2.begin(), lant2.end());

      if(lant1.size() == 0)
        break;
      for(int i = 0; i < lant1.size(); i++){
        if(color == 1 || i == (lant1.size() - 1))
          sol.push_back(lant1[i]);
        color = !color;
      }
    }
  }

  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << edge[sol[i]].x << " " << edge[sol[i]].y << '\n';
  return 0;
}