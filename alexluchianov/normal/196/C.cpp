#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1500;
struct Point{
  ll x;
  ll y;
};
Point v[1 + nmax];
vector<int> g[1 + nmax];

ll det3(Point a, Point b, Point c){
  ll splus = a.x * b.y + a.y * c.x + b.x * c.y;
  ll sminus = a.x * c.y + a.y * b.x + b.y * c.x;
  return splus - sminus;
}
Point orig;
bool compare(int x, int y){
  return 0 < det3(orig, v[x], v[y]);
}
int id[1 + nmax], sol[1 + nmax];
int sz[1 + nmax];

void dfs(int node, int parent){
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
    sz[node] += sz[to];
  }
}

int ptr = 0;

void solve(int node, int parent){
  sol[id[++ptr]] = node;
  orig = v[id[ptr]];
  sort(id + ptr + 1, id + ptr + sz[node], compare);
  for(int h = 0; h < g[node].size(); h++)
    solve(g[node][h], node);
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
  for(int i = 1;i <= n; i++) {
    cin >> v[i].x >> v[i].y;
    id[i] = i;
    if(v[id[i]].x < v[id[1]].x)
      swap(id[1], id[i]);
    else if(v[id[i]].x == v[id[1]].x && v[id[i]].x < v[id[1]].x)
      swap(id[1], id[i]);
  }
  dfs(1, 0);
  solve(1, 0);
  for(int i = 1;i <= n; i++)
    cout << sol[i] << " ";
  return 0;
}