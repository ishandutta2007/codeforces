#include <iostream>
#include <vector>

using namespace std;

int query (int u, int v) {
  cout << "? " << u << " " << v << endl;

  int ans;
  cin >> ans;

  if (ans == -1) exit(0);
  return ans;
}

void report (int r) {
  cout << "! " << r << endl;
  exit(0);
}

const int MAX_N = 1e3 + 5;

int in_dir [MAX_N][MAX_N];
vector<int> adj [MAX_N];
int del [MAX_N];

void build (int u, int p, int src, int br) {
  if (u == src) {
    for (int nxt : adj[u]) {
      build(nxt, u, src, nxt);
    }
  } else {
    in_dir[src][u] = br;
    for (int nxt : adj[u]) {
      if (nxt != p) {
        build(nxt, u, src, br);
      }
    }
  }
}

void del_sub (int u, int p) {
  del[u] = 1;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      del_sub(nxt, u);
    }
  }
}

bool is_leaf (int u) {
  if (del[u]) return 0;
  int nbs = 0;
  for (int nxt : adj[u]) {
    if (!del[nxt]) nbs++;
  }
  return nbs == 1;
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

  for (int i = 1; i <= n; i++) {
    build(i, 0, i, 0);
  }

  while (true) {
    vector<int> leaves;
    for (int i = 1; i <= n; i++) {
      if (is_leaf(i)) {
        leaves.push_back(i);
      }
    }

    if (leaves.empty()) {
      int ans;
      for (int i = 1; i <= n; i++) {
        if (!del[i]) ans = i;
      }
      report(ans);
    }

    int u = leaves[0];
    int v = leaves[1];

    int lca = query(u, v);

    if (lca == u) report(u);
    if (lca == v) report(v);

    del_sub(in_dir[lca][u], lca);
    del_sub(in_dir[lca][v], lca);
  }
}