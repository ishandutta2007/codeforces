#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;

vector<int> adj [MAX_N];
int cls [MAX_N];

vector<int> subof [MAX_N];
void dfs (int u) {
  for (int nxt : adj[u]) {
    dfs(nxt);
  }

  bool ok = false;
  if (cls[u] == 0) {
    subof[u].push_back(u);
    ok = true;
  }
  for (int nxt : adj[u]) {
    for (int v : subof[nxt]) {
      subof[u].push_back(v);
      if (subof[u].size() == cls[u]) {
        subof[u].push_back(u);
        ok = true;
      }
    }
  }

  if (!ok) {
    cout << "NO" << endl;
    exit(0);
  }
}

int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;

  int root = -1;
  for (int i = 1; i <= vertexc; i++) {
    int p;
    cin >> p >> cls[i];
    if (p == 0) {
      root = i;
    } else {
      adj[p].push_back(i);
    }
  }

  dfs(root);
  for (int i = 0; i < (int) subof[root].size(); i++) {
    ans[subof[root][i]] = i + 1;
  }

  cout << "YES" << '\n';
  for (int i = 1; i <= vertexc; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}