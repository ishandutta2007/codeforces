#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100005;

int comp [MAX_N];
int compsz [MAX_N];
vector<int> adj [MAX_N];
void dfs (int vertex, int _comp) {
  comp[vertex] = _comp;
  compsz[_comp]++;
  for (int nxt : adj[vertex]) {
    if (comp[nxt] == 0) {
      dfs(nxt, _comp);
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

  for (int i = 1; i <= vertexc; i++) {
    if (comp[i] == 0) {
      dfs(i, i);
    }
  }

  int sadc = edgec;
  for (int i = 1; i <= vertexc; i++) {
    sadc -= max(compsz[i] - 1, 0);
  }
  cout << sadc << endl;
}