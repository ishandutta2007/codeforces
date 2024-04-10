#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50000;
int const threshold = sqrt(nmax);
int on[1 + nmax], degree[1 + nmax], special[1 + nmax];
int sol[1 + nmax];

struct Update{
  char type;
  int u;
  int v;
};

vector<pair<int,int>> g[1 + nmax][2];

void addedge(int node, int to, int sign){
  g[node][special[to]].push_back({to, sign});
  g[to][special[node]].push_back({node, sign});
  if(special[to] == 1)
    sol[to] += on[node] * sign;
  if(special[node] == 1)
    sol[node] += on[to] * sign;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q, k;
  cin >> n >> m >> q;
  cin >> k;
  for(int i = 1;i <= k; i++) {
    int x;
    cin >> x;
    on[x] = 1;
  }
  vector<pair<int,int>> edges;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
    degree[x]++;
    degree[y]++;
  }
  vector<Update> updates;
  for(int i = 1;i <= q; i++){
    char op;
    int u, v;
    cin >> op;
    if(op == 'A' || op == 'D') {
      cin >> u >> v;
      degree[u]++;
      degree[v]++;
    } else
      cin >> u;
    updates.push_back({op, u, v});
  }

  for(int i = 1;i <= n; i++)
    if(threshold <= degree[i])
      special[i] = 1;
  for(int i = 0; i < edges.size(); i++)
    addedge(edges[i].first, edges[i].second, 1);

  for(int i = 0;i < updates.size(); i++){
    if(updates[i].type == 'O'){
      int node = updates[i].u;
      on[node] = 1;
      for(int h = 0; h < g[node][1].size(); h++)
        sol[g[node][1][h].first] += 1 * g[node][1][h].second;
    } else if(updates[i].type == 'F'){
      int node = updates[i].u;
      on[node] = 0;
      for(int h = 0; h < g[node][1].size(); h++)
        sol[g[node][1][h].first] -= 1 * g[node][1][h].second;
    } else if(updates[i].type == 'A'){
      int u = updates[i].u;
      int v = updates[i].v;
      addedge(u, v, 1);
    } else if(updates[i].type == 'D'){
      int u = updates[i].u;
      int v = updates[i].v;
      addedge(u, v, -1);
    } else {
      int node = updates[i].u;
      if(special[node] == 1)
        cout << sol[node] << '\n';
      else {
        int result = 0;
        for(int h = 0; h < g[node][0].size(); h++)
          result += on[g[node][0][h].first] * g[node][0][h].second;
        for(int h = 0; h < g[node][1].size(); h++)
          result += on[g[node][1][h].first] * g[node][1][h].second;
        cout << result << '\n';
      }
    }
  }
  return 0;
}