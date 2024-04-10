#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <bitset>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 500;
vector<pair<int,int>> g[1 + nmax];
int sol[1 + nmax][1 + nmax];

vector<int> dijkstra(int start, int n){
  vector<int> dist(1 + n);
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  pq.push({1, start});
  dist[start] = 1;
  while(0 < pq.size()){
    int node = pq.top().second, cost = pq.top().first;
    pq.pop();
    if(cost != dist[node])
      continue;
    for(int h = 0; h < g[node].size(); h++){
      pair<int,int> edge = g[node][h];
      if(dist[edge.first] == 0 || dist[node] + edge.second < dist[edge.first]){
        dist[edge.first] = dist[node] + edge.second;
        pq.push({dist[edge.first], edge.first});
      }
    }
  }
  return dist;
}

void solve(int start, int n){
  vector<int> dist = dijkstra(start, n);
  vector<int> weight(1 + n);
  vector<pair<int,int>> v;
  for(int i = 1;i <= n; i++)
    v.push_back({dist[i], i});
  sort(v.begin(), v.end());
  vector<bitset<1 + nmax>> reach(1 + n);

  for(int i = 0; i < v.size(); i++){
    int node = v[i].second;
    reach[node][node] = 1;
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h].first;
      if(dist[to] + g[node][h].second == dist[node]){
        if(reach[node][to] == 0)
          reach[node] |= reach[to];
        weight[node]++;
      }
    }
  }

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      sol[start][i] += reach[i][j] * weight[j];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y, l;
    cin >> x >> y >> l;
    g[x].push_back({y, l});
    g[y].push_back({x, l});
  }
  for(int i = 1;i <= n; i++)
    solve(i, n);
  for(int i = 1;i <= n; i++)
    for(int j = i + 1;j <= n; j++)
      cout << sol[i][j] << " ";
  return 0;
}