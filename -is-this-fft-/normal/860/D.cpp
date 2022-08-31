#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_V = 200005;

typedef pair<int, int> edge;

edge make_edge (int u, int v) {
  return make_pair(min(u, v), max(u, v));
}

vector<vector<int> > ans;
vector<int> adj [MAX_V];
int ord [MAX_V];
int cur;
set<edge> used;

void dfs (int vertex, int parent) {
  cur++;
  ord[vertex] = cur;

  for (int child : adj[vertex]) {
    if (ord[child] == 0) {
      dfs(child, vertex);
    }
  }

  vector<int> priority;

  /* back-edges */
  for (int child : adj[vertex]) {
    if (ord[child] < ord[vertex] &&
        child != parent &&
        used.count(make_edge(vertex, child)) == 0) {
      priority.push_back(child);
    }
  }

  /* child-edges */
  for (int child : adj[vertex]) {
    if (ord[child] > ord[vertex] &&
        used.count(make_edge(vertex, child)) == 0) {
      priority.push_back(child);
    }
  }

  /* parent-edge */
  if (used.count(make_edge(vertex, parent)) == 0 &&
      parent != 0) {
    priority.push_back(parent);
  }

  /* form the edge-pairs */
  for (int i = 0; i + 1 < (int) priority.size(); i += 2) {
    ans.push_back(vector<int> (3));
    ans.back()[0] = priority[i];
    ans.back()[1] = vertex;
    ans.back()[2] = priority[i + 1];

    used.insert(make_edge(priority[i], vertex));
    used.insert(make_edge(priority[i + 1], vertex));
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

  for (int i = 1; i <= vertexc; i++) {
    if (ord[i] == 0) {
      dfs(i, 0);
    }
  }

  cout << (int) ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    for (int j = 0; j < 3; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}