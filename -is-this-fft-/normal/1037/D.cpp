#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxv = 200005;

vector<int> adj [maxv];
vector<int> children [maxv];

void dfs (int vertex, int parent) {
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      children[vertex].push_back(nxt);
      dfs(nxt, vertex);
    }
  }
}

int pos [maxv];
bool bypos (int p, int q) {
  return pos[p] < pos[q];
}

int main () {
  ios::sync_with_stdio(false);
  
  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> perm (vertexc);
  for (int i = 0; i < vertexc; i++) {
    cin >> perm[i];
    pos[perm[i]] = i;
  }

  dfs(perm[0], 0);

  for (int i = 1; i <= vertexc; i++) {
    sort(children[i].begin(), children[i].end(), bypos);
  }

  if (perm[0] != 1) {
    cout << "No" << endl;
    return 0;
  }
  
  vector<int> seq;
  queue<int> Q;
  Q.push(perm[0]);
  while (!Q.empty()) {
    int qtop = Q.front();
    Q.pop();
    seq.push_back(qtop);
    
    for (int nxt : children[qtop]) {
      Q.push(nxt);
    }
  }

  for (int i = 0; i < vertexc; i++) {
    if (seq[i] != perm[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}