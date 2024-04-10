#include <iostream>
#include <vector>
#include <math.h>

const int MAX_VERTEX = 200005;
const int MAX_CLONE = 200005;

using namespace std;

bool vis [MAX_VERTEX];
vector<int> adj [MAX_VERTEX];
vector<int> ans [MAX_CLONE];
int cur_clone, max_len;

void dfs (int vertex) {
  vis[vertex] = true;
  ans[cur_clone].push_back(vertex);
  if ((int) ans[cur_clone].size() == max_len) {
    cur_clone++;
  }

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (!vis[adj[vertex][i]]) {
      dfs(adj[vertex][i]);

      ans[cur_clone].push_back(vertex);
      if ((int) ans[cur_clone].size() == max_len) {
        cur_clone++;
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec, clonec;
  cin >> vertexc >> edgec >> clonec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  max_len = (int) ceil((long double) vertexc * 2 / (long double) clonec);

  dfs(1);

  for (int i = 0; i < clonec; i++) {
    if ((int) ans[i].size() == 0) {
      cout << "1 1" << endl;
    } else {
      cout << (int) ans[i].size();
      for (int j = 0; j < (int) ans[i].size(); j++) {
        cout << " " << ans[i][j];
      }
      cout << "\n";
    }
  }
}