#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int lvl [MAX_N];

int dfs_mx (int u, int p) {
  lvl[u] = !lvl[p];
  int ans = 0;
  int lc = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if ((int) adj[nxt].size() == 1) {
        dfs_mx(nxt, u);
        lc = 1;
      } else {
        ans += 1 + dfs_mx(nxt, u);
      }
    }
  }

  return ans + lc;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int root;
  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() != 1) {
      root = i;
      break;
    }
  }

  int mx = dfs_mx(root, root);

  set<int> par;
  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() == 1) {
      par.insert(lvl[i]);
    }
  }

  int mn;
  if ((int) par.size() == 1) mn = 1;
  else mn = 3;

  cout << mn << " " << mx << endl;
}