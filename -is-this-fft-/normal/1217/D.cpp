#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e3 + 5;

vector<int> adj [MAX_N];
bool cycle;
int vis [MAX_N];

void dfs (int u) {
  vis[u] = 1;
  for (int nxt : adj[u]) {
    if (vis[nxt] == 0) dfs(nxt);
    else if (vis[nxt] == 1) cycle = 1;
  }
  vis[u] = 2;
}

int ans [MAX_N];

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);

    if (u < v) ans[i] = 1;
    else ans[i] = 2;
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) dfs(i);
  }

  if (!cycle) {
    cout << 1 << endl;
    for (int i = 0; i < m; i++) {
      cout << 1 << " ";
    }
    cout << endl;
  } else {
    cout << 2 << endl;
    for (int i = 0; i < m; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}