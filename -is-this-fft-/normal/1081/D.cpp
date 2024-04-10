#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int root [maxn];
int weight [maxn];

int find (int v) {
  if (root[v] != v) {
    root[v] = find(root[v]);
  }
  return root[v];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (u != v) {
    root[u] = v;
    weight[v] += weight[u];
  }
}

typedef pair<int, int> edge;

int main () {
  for (int i = 0; i < maxn; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);

  int vertexc, edgec, specc;
  cin >> vertexc >> edgec >> specc;

  for (int i = 0; i < specc; i++) {
    int spec;
    cin >> spec;
    weight[spec]++;
  }

  vector<pair<int, edge>> edges (edgec);
  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
  }

  sort(edges.begin(), edges.end());

  for (pair<int, edge> pr : edges) {
    edge e = pr.second;

    merge(e.first, e.second);

    if (weight[find(e.first)] == specc) {
      for (int i = 0; i < specc; i++) {
        cout << pr.first << " ";
      }
      cout << endl;
      return 0;
    }
  }
}