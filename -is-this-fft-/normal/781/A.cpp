#include <iostream>
#include <vector>

const int MAX_VERTEX = 200005;

using namespace std;

vector<int> adj [MAX_VERTEX];
int color [MAX_VERTEX];

void dfs (int vertex, int parent) {
  int cur_color = 1;
  while (cur_color == color[vertex] ||
         cur_color == color[parent]) {
    cur_color++;
  }

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      color[adj[vertex][i]] = cur_color;
      cur_color++;
      while (cur_color == color[vertex] ||
             cur_color == color[parent]) {
        cur_color++;
      }
      dfs(adj[vertex][i], vertex);
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

  color[1] = 1;
  dfs(1, 1);

  int ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    ans = max(ans, color[i]);
  }
  
  cout << ans << endl;
  for (int i = 1; i <= vertexc; i++) {
    cout << color[i] << " ";
  }
  cout << endl;
}