#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
ll cost[5 + nmax];
int seen[5 + nmax];
vector<int> g[5 + nmax];
int outedge[5 + nmax];

int n, m, start;
vector<int> g2[5 + nmax];
vector<pair<int,int>> edges;

void normalize(){
  queue<int> q;
  for(int i = 1;i <= n; i++)
    if(outedge[i] == 1) {
      seen[i] = 1;
      q.push(i);
    }

  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      outedge[to]--;
      outedge[node]--;
      if(outedge[to] == 1) {
        q.push(to);
        seen[to] = 1;
      }
    }
  }

  for(int i = 1;i <= n; i++) {
    if(seen[i] == 0) {
      cost[n + 1] += cost[i];
      cost[i] = 0;
    }
  }

  for(int h = 0; h < edges.size(); h++){
    int x = edges[h].first, y = edges[h].second;
    if(seen[x] == 0)
      x = n + 1;
    if(seen[y] == 0)
      y = n + 1;
    if(x != y) {
      g2[x].push_back(y);
      g2[y].push_back(x);
    }
  }

  if(seen[start] == 0)
    start = n + 1;
}

ll dfs(int node, int parent){
  ll result = cost[node];
  for(int h = 0; h < g2[node].size(); h++){
    int to = g2[node][h];
    if(to != parent){
      ll result2 = dfs(to, node);
      if(result < result2 + cost[node])
        result = result2 + cost[node];
    }
  }
  return result;
}

int main()
{
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> cost[i];

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    outedge[x]++;
    outedge[y]++;
    g[x].push_back(y);
    g[y].push_back(x);
    edges.push_back({x, y});
  }

  cin >> start;
  normalize();
  cout << MAX(dfs(start, 0), dfs(n + 1, 0));
  return 0;
}