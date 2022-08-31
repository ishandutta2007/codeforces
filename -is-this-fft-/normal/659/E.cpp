#include <iostream>
#include <stdlib.h>
#include <vector>

const int MAX_V = 100005;

using namespace std;

vector<int> adj [MAX_V];
int color [MAX_V];
bool cycle [MAX_V];

void traverse (int vertex, int parent, int source) {
  color[vertex] = source;
  for (int i = 0; i < adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      if (color[adj[vertex][i]] != 0) {
        cycle[source] = true;
      } else {
        traverse(adj[vertex][i], vertex, source);
      }
    }
  }
}
  

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    if (color[i] == 0) {
      traverse(i, 0, i);
      if (!cycle[i]) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}