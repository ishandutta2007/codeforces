#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 3e5 + 5;

int par [MAX_N];
vector<int> adj [MAX_N];
int lvl [MAX_N];

void dfs (int u, int p) {
  par[u] = p;
  lvl[u] = lvl[p] + 1;
  for (int nxt : adj[u]) {
    if (!par[nxt]) {
      dfs(nxt, u);
    }
  }
}

int qdeg [MAX_N];
pair<int, int> qs [MAX_N];

vector<int> path (int u, int v) {
  bool flipped = false;
  if (lvl[u] < lvl[v]) {
    swap(u, v);
    flipped = true;
  }

  vector<int> upath;
  while (lvl[u] > lvl[v]) {
    upath.push_back(u);
    u = par[u];
  }

  vector<int> vpath;
  while (u != v) {
    upath.push_back(u);
    u = par[u];

    vpath.push_back(v);
    v = par[v];
  }

  upath.push_back(u);
  upath.insert(upath.end(), vpath.rbegin(), vpath.rend());
  if (flipped) {
    reverse(upath.begin(), upath.end());
  }
  return upath;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    cin >> qs[i].first >> qs[i].second;
    qdeg[qs[i].first]++;
    qdeg[qs[i].second]++;
  }

  int oddc = 0;
  for (int i = 1; i <= n; i++) {
    if (qdeg[i] % 2 == 1) {
      oddc++;
    }
  }

  if (oddc != 0) {
    cout << "NO" << endl;
    cout << oddc / 2 << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < qc; i++) {
    auto ans = path(qs[i].first, qs[i].second);
    cout << (int) ans.size() << '\n';
    for (int u : ans) {
      cout << u << " ";
    }
    cout << '\n';
  }
}