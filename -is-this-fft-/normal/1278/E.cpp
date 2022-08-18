#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 5e5 + 5;

vector<int> ord;
vector<int> adj [MAX_N];

void dfs (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      ord.push_back(nxt);
    }
  }

  ord.push_back(u);
  reverse(adj[u].begin(), adj[u].end());

  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);
    }
  }
}

int seen [MAX_N];
int l [MAX_N];
int r [MAX_N];

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

  ord.push_back(1);
  dfs(1, 1);

  for (int i = 0; i < (int) ord.size(); i++) {
    if (!seen[ord[i]]) {
      seen[ord[i]] = 1;
      l[ord[i]] = i + 1;
    } else {
      r[ord[i]] = i + 1;
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    cout << l[i] << " " << r[i] << '\n';
  }
}