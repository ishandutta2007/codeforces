#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using namespace std;

using ll = long long;

class Graph{
private:
  int const inf = (1 << 30);
  struct Edge{
    int to;
    int flow;
    int cap;
    int rev;
  };
  int n;
  vector<int> dist, rem;
  vector<vector<Edge>> g;
  bool BFS(){
    queue<int> q;
    for(int i = 1;i <= n; i++)
      dist[i] = 0;
    dist[1] = 1;
    q.push(1);
    while(0 < q.size()){
      int node = q.front();
      q.pop();
      for(int h = 0; h < g[node].size(); h++){
        Edge e = g[node][h];
        if(e.flow < e.cap && dist[e.to] == 0){
          dist[e.to] = dist[node] + 1;
          q.push(e.to);
        }
      }
    }
    return 0 < dist[n];
  }

  int DFS(int node, int deltaflow){
    if(node == n)
      return deltaflow;
    else{
      for(int &h = rem[node]; h < g[node].size(); h++){
        Edge &e = g[node][h];
        if(e.flow < e.cap && dist[node] + 1 == dist[e.to]){
          int fl = DFS(e.to, min(deltaflow, e.cap - e.flow));
          if(0 < fl){
            e.flow += fl;
            g[e.to][e.rev].flow -= fl;
            return fl;
          }
        }
      }
      return 0;
    }
  }
public:
  Graph(int n_){
    n = n_;
    g.resize(1 + n_);
    dist.resize(1 + n);
    rem.resize(1 + n);
  }

  void _addedge(int x, int y, int cap){
    g[x].push_back({y, 0, cap, g[y].size()});
    g[y].push_back({x, 0, 0, g[x].size() - 1});
  }

  ll maxflow(){
    ll result = 0;
    while(BFS()){
      for(int i = 1;i <= n; i++)
        rem[i] = 0;
      int deltaflow = 0;
      do {
        result += deltaflow;
        deltaflow = DFS(1, inf);
      } while(0 < deltaflow);
    }
    return result;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  Graph graph(1 + n + m + 1);

  for(int i = 1; i <= n; i++){
    int val;
    cin >> val;
    graph._addedge(1, i + 1, val);
  }
  ll result = 0;
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    result += cost;
    graph._addedge(x + 1, 1 + n + i, cost);
    graph._addedge(y + 1, 1 + n + i, cost);
    graph._addedge(1 + n + i, 1 + n + m + 1, cost);
  }
  cout << result - graph.maxflow();
  return 0;
}