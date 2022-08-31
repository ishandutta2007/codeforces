#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 300;

vector<int> adj [MAX_N];
int vis [MAX_N];

void dfs (int u) {
  vis[u] = 1;
  for (int nxt : adj[u]) {
    if (!vis[nxt]) {
      dfs(nxt);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  bool allz = true;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    if (k != 0) {
      allz = false;
    }

    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;

      adj[i].push_back(n + v);
      adj[n + v].push_back(i);
    }
  }

  int compc = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      compc++;
    }
  }

  if (allz) {
    cout << n << endl;
  } else {
    cout << compc - 1 << endl;
  }
}