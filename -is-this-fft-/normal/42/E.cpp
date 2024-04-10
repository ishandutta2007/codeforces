#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define x first
#define y second

class DSU {
  vector<int> root;
  vector<int> subsz;

public:
  DSU (int _vertexc) {
    root = vector<int> (_vertexc);
    subsz = vector<int> (_vertexc, 1);
    for (int i = 0; i < _vertexc; i++) {
      root[i] = i;
    }
  }

  int find (int u) {
    if (root[u] != u) {
      root[u] = find(root[u]);
    }
    return root[u];
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
      root[u] = v;
      subsz[v] += subsz[u];
    }
  }

  int size (int u) {
    return subsz[find(u)];
  }
};

const int MAX_N = 1e5 + 5;

vector<pair<int, int>> adj [MAX_N]; // <idx, weight>
void add_edge (int u, int v, int w) {
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
}

const int MAX_LG = 18;
int lvl [MAX_N];
int jmp [MAX_N][MAX_LG];
int jmpmax [MAX_N][MAX_LG];
void build (int u, int par, int upw) {
  lvl[u] = lvl[par] + 1;
  jmp[u][0] = par;
  jmpmax[u][0] = upw;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
    jmpmax[u][i] = max(jmpmax[u][i - 1], jmpmax[jmp[u][i - 1]][i - 1]);
  }

  for (auto nxt : adj[u]) {
    if (nxt.x != par) {
      build(nxt.x, u, nxt.y);
    }
  }
}

int maxup (int u, int diff) {
  int ans = 0;
  for (int i = 0; i < MAX_LG; i++) {
    if (diff & 1 << i) {
      ans = max(ans, jmpmax[u][i]);
      u = jmp[u][i];
    }
  }
  return ans;
}

int lca (int u, int v) {
  if (lvl[u] < lvl[v]) {
    swap(u, v);
  }

  int diff = lvl[u] - lvl[v];
  for (int i = 0; i < MAX_LG; i++) {
    if (diff & 1 << i) {
      u = jmp[u][i];
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (jmp[u][i] != jmp[v][i]) {
      u = jmp[u][i];
      v = jmp[v][i];
    }
  }

  return jmp[u][0];
}

int max_on_path (int u, int v) {
  int lc = lca(u, v);
  return max(maxup(u, lvl[u] - lvl[lc]), maxup(v, lvl[v] - lvl[lc]));
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  vector<pair<int, pair<int, int>>> edges (edgec);
  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].y.x >> edges[i].y.y >> edges[i].x;
  }

  sort(edges.begin(), edges.end());

  DSU dsu (vertexc + 5);
  ll mst_cost = 0;
  for (auto e : edges) {
    int w = e.x;
    int u = e.y.x;
    int v = e.y.y;
    if (dsu.find(u) != dsu.find(v)) {
      dsu.merge(u, v);
      add_edge(u, v, w);
      mst_cost += w;
    }
  }

  bool all_mode = dsu.size(1) == vertexc;
  if (all_mode) {
    build(1, 1, 0);
  }

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    if (all_mode) {
      cout << mst_cost - max_on_path(u, v) << '\n';
    } else {
      if (dsu.find(u) != dsu.find(v) && dsu.size(u) + dsu.size(v) == vertexc) {
        cout << mst_cost << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
}