#include <iostream>
#include <stdlib.h>
#include <vector>

const int MAX_VERTEX = 200005;

using namespace std;

int group [MAX_VERTEX], vcolour [MAX_VERTEX], exists [MAX_VERTEX];

int find (int u) {
  if (group[u] != u) {
    group[u] = find(group[u]);
    return group[u];
  }
  return u;
}

void merge (int u, int v) {
  int uroot = find(u), vroot = find(v);

  if (uroot != vroot) {
    if (rand() % 2 == 1) {
      group[uroot] = vroot;
    } else {
      group[vroot] = uroot;
    }
  }
}

vector<int> adj [MAX_VERTEX];
int dist [MAX_VERTEX][2];

void dfs (int cur, int par, int id) {
  for (int i = 0; i < (int) adj[cur].size(); i++) {
    if (adj[cur][i] != par) {
      dist[adj[cur][i]][id] = dist[cur][id] + 1;
      dfs(adj[cur][i], cur, id);
    }
  }
}

int main () {
  srand(5318008);

  int verticec;
  cin >> verticec;

  for (int i = 1; i <= verticec; i++) {
    group[i] = i;
    cin >> vcolour[i];
  }

  vector<pair<int, int> > ingraph;
  for (int i = 1; i < verticec; i++) {
    int u, v;
    cin >> u >> v;
    ingraph.push_back(make_pair(u, v));
    if (vcolour[u] == vcolour[v]) {
      merge(u, v);
    }
  }

  for (int i = 1; i <= verticec; i++) {
    exists[find(i)] = 1;
  }

  for (int i = 0; i < verticec - 1; i++) {
    if (vcolour[ingraph[i].first] != vcolour[ingraph[i].second]) {
      adj[find(ingraph[i].first)].push_back(find(ingraph[i].second));
      adj[find(ingraph[i].second)].push_back(find(ingraph[i].first));
    }
  }

  dfs(find(1), find(1), 0);

  int maxd = -1, maxv;
  for (int i = 1; i <= verticec; i++) {
    if (exists[i] && dist[i][0] > maxd) {
      maxd = dist[i][0];
      maxv = i;
    }
  }

  dfs(maxv, maxv, 1);
  
  int ans = 0;
  for (int i = 1; i <= verticec; i++) {
    if (exists[i] && dist[i][1] > ans) {
      ans = dist[i][1];
    }
  }

  cout << (ans + 1) / 2 << endl;
}