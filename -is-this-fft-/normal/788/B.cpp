#include <iostream>

const int MAX_VERTEX = 1000005;

using namespace std;

int root [MAX_VERTEX];

int find (int vertex) {
  if (root[vertex] == vertex) {
    return root[vertex];
  } else {
    root[vertex] = find(root[vertex]);
    return root[vertex];
  }
}

void merge (int u, int v) {
  if (find(u) != find(v)) {
    root[find(u)] = find(v);
  }
}

pair<int, int> edges [MAX_VERTEX];
int degree [MAX_VERTEX];

int main () {
  for (int i = 0; i < MAX_VERTEX; i++) {
    root[i] = i;
  }

  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].first >> edges[i].second;
    merge(edges[i].first, edges[i].second);
  }

  for (int i = 0; i < edgec; i++) {
    if (find(edges[i].first) != find(edges[0].first)) {
      cout << 0 << endl;
      return 0;
    }

    if (find(edges[i].second) != find(edges[0].first)) {
      cout << 0 << endl;
      return 0;
    }
  }

  int slc = 0;
  long long ans = 0;
  for (int i = 0; i < edgec; i++) {
    if (edges[i].first == edges[i].second) {
      ans += i;
      slc++;
    } else {
      ans += degree[edges[i].first] + degree[edges[i].second];
      ans += slc;
      degree[edges[i].first]++;
      degree[edges[i].second]++;
    }
  }

  cout << ans << endl;
}