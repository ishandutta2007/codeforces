#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int lvl [MAX_N];

void dfs (int u, int p) {
  lvl[u] = lvl[p] + 1;
  for (int nxt : adj[u]) {
    if (nxt == p) continue;
    dfs(nxt, u);
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  lvl[0] = -1;
  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    int cur, nxt, deg;
    if (lvl[i] == 0) {
      cur = 0;
      nxt = 1;
      deg = (int) adj[i].size();
    } else if (lvl[i] % 2 == 1) {
      cur = 1;
      nxt = -1;
      deg = (int) adj[i].size() - 1;
    } else {
      cur = -1;
      nxt = 1;
      deg = (int) adj[i].size() - 1;
    }

    cout << cur - deg * nxt << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}