#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 4e5 + 10;
const int MAX_LG = 20;
const int EDGE = 2e5 + 5;

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

vector<int> adj [MAX_N];

int lvl [MAX_N];
int jmp [MAX_N][MAX_LG];

void build (int u, int p) {
  lvl[u] = lvl[p] + 1;
  
  jmp[u][0] = p;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      build(nxt, u);
    }
  }
}

int anc_at (int u, int k) {
  int diff = lvl[u] - k;
  for (int i = 0; i < MAX_LG; i++) {
    if (diff & 1 << i) {
      u = jmp[u][i];
    }
  }
  return u;
}

int lca (int u, int v) {
  if (u == v) return u;

  if (lvl[u] < lvl[v]) swap(u, v);
  u = anc_at(u, lvl[v]);

  if (u == v) return u;

  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (jmp[u][i] != jmp[v][i]) {
      u = jmp[u][i];
      v = jmp[v][i];
    }
  }

  return jmp[u][0];
}

int distuv (int u, int v) {
  int l = lca(u, v);
  return lvl[u] - lvl[l] + lvl[v] - lvl[l];
}

int towards (int u, int v, int k) {
  int l = lca(u, v);
  if (k <= lvl[u] - lvl[l]) {
    return anc_at(u, lvl[u] - k);
  } else {
    return anc_at(v, lvl[l] + (k - (lvl[u] - lvl[l])));
  }
}

int dist [MAX_N];
int color [MAX_N];

bool query (int u, int v, int k) {
  if (distuv(u, v) <= 2 * k) return true;
  u = towards(u, v, k);
  v = towards(v, u, k);

  return color[u] != 0 && find(color[u]) == find(color[v]);
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
    dist[i] = MAX_N;
  }

  int n, k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    int e = EDGE + i;
    
    adj[u].push_back(e);
    adj[e].push_back(u);

    adj[v].push_back(e);
    adj[e].push_back(v);
  }

  vector<int> spec (r);
  for (int i = 0; i < r; i++) {
    cin >> spec[i];
  }
  
  queue<int> Q;
  for (int u : spec) {
    dist[u] = 0;
    color[u] = u;
    Q.push(u);
  }

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    if (dist[u] < k) {
      for (int nxt : adj[u]) {
        if (dist[nxt] == MAX_N) {
          color[nxt] = color[u];
          dist[nxt] = dist[u] + 1;
          Q.push(nxt);
        } else {
          merge(color[u], color[nxt]);
        }
      }
    }
  }

  build(1, 1);

  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    int u, v;
    cin >> u >> v;

    cout << (query(u, v, k) ? "YES" : "NO") << '\n';
  }
}