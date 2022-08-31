#include <iostream>
#include <vector>

typedef long long llong;

const int MAX_VERT = 32;

using namespace std;

llong x [MAX_VERT], y [MAX_VERT];
llong nx [4] = {1, 0, -1, 0};
llong ny [4] = {0, 1, 0, -1};
vector<int> adj [MAX_VERT];

void dfs (int vertex, int parent, int blocked_dir, int depth) {
  int orient = (blocked_dir + 1) % 4;
  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      x[adj[vertex][i]] = x[vertex] + nx[orient] * (1LL << depth);
      y[adj[vertex][i]] = y[vertex] + ny[orient] * (1LL << depth);
      dfs(adj[vertex][i], vertex, (orient + 2) % 4, depth - 1);
      orient++;
      orient %= 4;
    }
  }
}

int main () {
  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= vertexc; i++) {
    if (adj[i].size() > 4) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  dfs(1, 0, 0, 32);
  for (int i = 1; i <= vertexc; i++) {
    cout << x[i] << " " << y[i] << endl;
  }
}