#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

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

map<pair<int, int>, int> idx;

set<int> adj [MAX_N];
ll arr [MAX_N];
ll ans [MAX_N];
ll cur [MAX_N];

void add_edge (int u, int v) {
  adj[u].insert(v);
  adj[v].insert(u);
}

int color [MAX_N];
void dfs (int u, int c) {
  color[u] = c;
  for (int nxt : adj[u]) {
    if (color[nxt] == 0) {
      dfs(nxt, -c);
    }
  }
}

vector<int> Q;
void del (int v) {
  int u = *adj[v].begin();
  ans[idx[{u, v}]] = cur[v];
  cur[u] -= cur[v];
  cur[v] -= cur[v];
  adj[v].erase(u);
  adj[u].erase(v);
  if ((int) adj[u].size() == 1) {
    Q.push_back(u);
  }
}

vector<int> cycle;
void find_cycle (int u, int p) {
  cycle.push_back(u);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (nxt == cycle[0]) return;
      find_cycle(nxt, u);
      return;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cur[i] = arr[i];
    root[i] = i;
  }

  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    edges.push_back({u, v});

    idx[make_pair(u, v)] = i;
    idx[make_pair(v, u)] = i;

    if (find(u) != find(v)) {
      merge(u, v);
      add_edge(u, v);
    }
  }

  dfs(1, 1);
  bool oddc = false;
  for (auto e : edges) {
    if (color[e.first] == color[e.second]) {
      add_edge(e.first, e.second);
      oddc = true;
      break;
    }
  }

  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() == 1) {
      Q.push_back(i);
    }
  }

  while (!Q.empty()) {
    int u = Q.back();
    Q.pop_back();

    if ((int) adj[u].size() == 1) {
      del(u);
    }
  }

  if (oddc) {
    int root = -1;
    for (int i = 1; i <= n; i++) {
      if (!adj[i].empty()) {
        root = i;
      }
    }

    find_cycle(root, root);

    ll last = 0;
    for (int i = 0; i < (int) cycle.size(); i++) {
      if (i % 2 == 0) last += cur[cycle[i]];
      else last -= cur[cycle[i]];
    }
    last /= 2;

    ans[idx[{cycle[0], cycle.back()}]] = last;
    for (int i = (int) cycle.size() - 1; i >= 1; i--) {
      ll diff = cur[cycle[i]] - last;
      ans[idx[{cycle[i - 1], cycle[i]}]] = diff;
      last = diff;
    }
  }

  for (auto e : edges) {
    arr[e.first] -= ans[idx[e]];
    arr[e.second] -= ans[idx[e]];
  }
  
  for (int i = 1; i <= n; i++) {
    if (arr[i] != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}