#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using ld = long double;
using ll = long long;

int const nmax = 100000;
int dist[1 + nmax];

struct Edge{
  int x, y;
  int l;
};

vector<pair<int,int>> g[1 + nmax];

int getdist(int x, int y, int l, int pos){
  return min(dist[x] + pos, dist[y] + l - pos);
}

int contrib(Edge e, int target){
  if(dist[e.y] < dist[e.x])
    swap(e.x, e.y);
  int pos1 = -1, pos2 = -1;

  pos1 = target - dist[e.x];
  pos2 = e.l - (target - dist[e.y]);
  if(pos1 < 0)
    pos1 = 0;
  if(pos2 < 0)
    pos2 = 0;

  if(pos1 == pos2)
    return (0 < pos1 && pos1 < e.l) * (getdist(e.x, e.y, e.l, pos1) == target);

  return (0 < pos1 && pos1 < e.l) * (getdist(e.x, e.y, e.l, pos1) == target) +
          (0 < pos2 && pos2 < e.l) * (getdist(e.x, e.y, e.l, pos2) == target);
}

int main()
{
  int n, m, s;
  cin >> n >> m >> s;
  vector<Edge> edge;
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
    edge.push_back({x, y, cost});
  }
  for(int i = 1;i <= n; i++)
    dist[i] = -1;
  dist[s] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
  pq.push({0, s});
  while(0 < pq.size()){
    int node = pq.top().second, cost = pq.top().first;
    pq.pop();
    if(dist[node] == cost){
      for(int h = 0; h < g[node].size(); h++){
        int to = g[node][h].first;
        if(dist[to] == -1 || dist[node] + g[node][h].second < dist[to]){
          dist[to] = dist[node] + g[node][h].second;
          pq.push({dist[to], to});
        }
      }
    }
  }
  int target, result = 0;
  cin >> target;
  for(int i = 1;i <= n; i++){
    if(dist[i] == target)
      result ++;
  }
  for(int i = 0; i < edge.size(); i++)
    result += contrib(edge[i], target);
  cout << result;
  return 0;
}
/*
3 3 1
1 2 4
1 3 4
2 3 5
6

*/