#include <iostream>
#include <vector>

using namespace std;

int dist (int u) {
  cout << "d " << u << '\n';

  int ans;
  cin >> ans;
  if (ans == -1) {
    exit(0);
  }

  return ans;
}

int dir (int u) {
  cout << "s " << u << '\n';

  int ans;
  cin >> ans;
  if (ans == -1) {
    exit(0);
  }

  return ans;
}

void report (int x) {
  cout << "! " << x << '\n';
  exit(0);
}

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
vector<int> chain [MAX_N];
int lvl [MAX_N];
int sz [MAX_N];

void build_sz (int u, int p) {
  sz[u] = 1;
  lvl[u] = lvl[p] + 1;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      build_sz(nxt, u);
      sz[u] += sz[nxt];
    }
  }
}

void build_hld (int u, int src, int p) {
  chain[src].push_back(u);

  pair<int, int> bigch = {0, 0}; // <subsz, id>
  for (int nxt : adj[u]) {
    if (nxt != p) {
      bigch = max(bigch, {sz[nxt], nxt});
    }
  }

  int bigchild = bigch.second;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (nxt == bigchild) {
        build_hld(nxt, src, u);
      } else {
        build_hld(nxt, nxt, u);
      }
    }
  }
}

int lvlof;
void solve_chain (int src) {
  if (chain[src].size() == 1) {
    report(src);
  }

  int v = chain[src].back();
  int d = dist(v);
  int lvll = (lvl[v] + lvlof - d) / 2;
  int lca = chain[src][lvll - lvl[src]];

  if (lvlof == lvl[lca]) {
    report(lca);
  }

  int nxt = dir(lca);
  solve_chain(nxt);
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

  build_sz(1, 1);
  build_hld(1, 1, 1);
  lvlof = dist(1) + 1;
  solve_chain(1);
}