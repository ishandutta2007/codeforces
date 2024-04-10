#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;
int const inf = 1000000000;
int const iplus[4] = {0, 0, 1, -1};
int const jplus[4] = {1, -1, 0, 0};

struct Point{
  int x, y;
  bool operator < (Point const &a) const{
    if(x != a.x)
      return x < a.x;
    else
      return y < a.y;
  }
};

Point v[1 + nmax];

struct Edge{
  int to;
  double cost;
  bool operator < (Edge const &a) const{
    return cost > a.cost;
  }
};

vector<Edge> g[1 + nmax * 5];
map<Point, int> frec;

double dp[1 + nmax * 5];

void addEdge(int x, int y, double cost){
  g[x].push_back({y, cost});
  g[y].push_back({x, cost});
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1;i <= k; i++)
    cin >> v[i].x >> v[i].y;
  sort(v + 1, v + k + 1);

  int id = n + m;
  for(int i = 1; i <= k; i++)
    frec[v[i]] = ++id;

  for(int i = 1; i <= k; i++) {
    if(1 < v[i].x)
      addEdge(v[i].x - 1, frec[v[i]], 0.5);
    if(v[i].x < n)
      addEdge(v[i].x + 1, frec[v[i]], 0.5);

    addEdge(v[i].x, frec[v[i]], 0.5);

    if(1 < v[i].y)
      addEdge(n + v[i].y - 1, frec[v[i]], 0.5);
    if(v[i].y < m)
      addEdge(n + v[i].y + 1, frec[v[i]], 0.5);

    addEdge(n + v[i].y, frec[v[i]], 0.5);

    for(int h = 0; h < 4; h++){
      int newx = v[i].x + iplus[h];
      int newy = v[i].y + jplus[h];
      if(0 < frec[{newx, newy}]){
        addEdge(frec[v[i]], frec[{newx, newy}], 0);
      }
    }
  }

  id++;

  addEdge(n, id, 0.5);
  addEdge(n + m, id, 0.5);
  for(int i = 1;i <= k; i++)
    if(v[i].x == n && v[i].y == m)
      addEdge(frec[v[i]], id, 0);

  for(int i = 1;i <= id; i++)
    dp[i] = inf;
  dp[frec[v[1]]] = 0;

  priority_queue<Edge> pq;
  pq.push({frec[v[1]], 0});

  while(0 < pq.size()){
    Edge pqtop = pq.top();
    int node = pqtop.to;
    pq.pop();
    if(dp[node] == pqtop.cost)
      for(int h = 0; h < g[node].size(); h++){
        Edge e = g[node][h];
        if(dp[node] + e.cost < dp[e.to]) {
          dp[e.to] = dp[node] + e.cost;
          pq.push({e.to, dp[e.to]});
        }
      }
  }

  if(dp[id] != inf)
    cout << dp[id];
  else
    cout << -1;
  return 0;
}