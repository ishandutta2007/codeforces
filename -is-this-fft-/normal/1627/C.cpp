// bad problem
 
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<pair<int, int>> adj [MAX_N];
int ans [MAX_N];
int pri [2] = {2, 3};

void dfs (int u, int p, int c) {
  for (auto e : adj[u]) {
    int nxt = e.first;
    if (nxt == p) continue;
    ans[e.second] = pri[c];
    dfs(nxt, u, !c);
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

    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }

  int sta = -1;
  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() > 2) {
      cout << -1 << '\n';
      return;
    }

    if ((int) adj[i].size() == 1) {
      sta = i;
    }
  }

  dfs(sta, 0, 0);

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i] << " ";
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