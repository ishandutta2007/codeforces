#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

set <int> g[N];
int n, d[N], par[N];

void go (int u, int pr = 0, int far = 0) {
  d[u] = far, par[u] = pr;
  for (int v : g[u]) if (v ^ pr) {
    go(v, u, far + 1);
  }
}

inline int ask (int u, int v) {
  cout << "? " << u << " " << v << endl;
  int rep; cin >> rep; return rep;
}

inline void answer (int u) {
  cout << "! " << u << endl;
  exit(0);
}

set <int> activeNodes;

void remove (int u, int pr) {
  activeNodes.erase(u);
  for (int v : g[u]) if (v ^ pr) remove(v, u);
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace(v);
    g[v].emplace(u);
  }
  for (int i = 1; i <= n; ++i) activeNodes.emplace(i);
  while (true) {
    if (activeNodes.size() == 1) {
      answer(*activeNodes.begin());
    }
    vector <int> leaves;
    for (int u : activeNodes) {
      if (g[u].size() == 1) {
        leaves.emplace_back(u);
      }
    }
    int lca = ask(leaves[0], leaves[1]);
    if (leaves.size() == 2 or lca == leaves[0] or lca == leaves[1]) {
      answer(lca);
    }
    go(lca);
    int at = leaves[0], yo = d[at] - 1;
    while (yo--) at = par[at];
    remove(at, lca), g[lca].erase(at), g[at].erase(lca);
    at = leaves[1], yo = d[at] - 1;
    while (yo--) at = par[at];
    remove(at, lca), g[lca].erase(at), g[at].erase(lca);
  }
  assert(false);
  return 0;
}