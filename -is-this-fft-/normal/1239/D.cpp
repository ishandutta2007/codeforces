#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 5;

vector<int> in_adj [MAX_N];
vector<int> out_adj [MAX_N];

int topvis [MAX_N];
int flipvis [MAX_N];

void top_dfs (int u, vector<int> &top) {
  topvis[u] = 1;
  for (int prv : in_adj[u]) {
    if (!topvis[prv]) {
      top_dfs(prv, top);
    }
  }
  top.push_back(u);
}

void flip_dfs (int u) {
  flipvis[u] = 1;
  for (int nxt : out_adj[u]) {
    if (!flipvis[nxt]) {
      flip_dfs(nxt);
    }
  }
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    in_adj[i].clear();
    out_adj[i].clear();
    topvis[i] = 0;
    flipvis[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    if (u != v) {
      out_adj[v].push_back(u);
      in_adj[u].push_back(v);
    }
  }

  vector<int> top;
  for (int i = 1; i <= n; i++) {
    if (!topvis[i]) {
      top_dfs(i, top);
    }
  }

  int src = top.back();
  flip_dfs(src);

  vector<int> lft, rgt;
  for (int i = 1; i <= n; i++) {
    if (!flipvis[i]) {
      lft.push_back(i);
    } else {
      rgt.push_back(i);
    }
  }

  if (lft.empty() || rgt.empty()) {
    cout << "No" << '\n';
    return;
  }

  cout << "Yes" << '\n';
  cout << lft.size() << " " << rgt.size() << '\n';
  for (int u : lft) {
    cout << u << " ";
  }
  cout << '\n';
  for (int u : rgt) {
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