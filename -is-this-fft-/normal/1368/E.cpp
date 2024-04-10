#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> in_adj [MAX_N];
int vis [MAX_N];
int state [MAX_N]; // 1 - delete, 2 - enter, 3 - exit

void dfs (int u) {
  vis[u] = 1;

  int exex = 0, exen = 0;
  for (int prv : in_adj[u]) {
    if (!vis[prv]) {
      dfs(prv);
    }

    if (state[prv] == 3) exex = 1;
    if (state[prv] == 2) exen = 1;
  }

  if (exex) {
    state[u] = 1;
  } else if (exen) {
    state[u] = 3;
  } else {
    state[u] = 2;
  }
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    in_adj[i].clear();
    state[i] = 0;
    vis[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    in_adj[v].push_back(u);
  }
  
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (state[i] == 1) {
      ans.push_back(i);
    }
  }

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}