#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

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
pair<int, int> edges [MAX_N];

bool is_triangle (const vector<int> &es) {
  set<int> ends;
  for (int e : es) {
    ends.insert(edges[e].first);
    ends.insert(edges[e].second);
  }

  return (int) ends.size() == 3;
}

int dfs (int u, int p, int tar) {
  for (int e : adj[u]) {
    if (e == p) continue;
    int oth = u ^ edges[e].first ^ edges[e].second;
    if (oth == tar) {
      return e;
    }

    int found = dfs(oth, e, tar);
    if (found != -1) {
      return e;
    }
  }

  return -1;
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    adj[i].clear();
    root[i] = i;
  }

  vector<int> ans (m, 0);
  vector<int> extra;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    edges[i] = {u, v};
    if (find(u) != find(v)) {
      merge(u, v);
      ans[i] = 0;
      adj[u].push_back(i);
      adj[v].push_back(i);
    } else {
      extra.push_back(i);
      ans[i] = 1;
    }
  }

  if ((int) extra.size() == 3 && is_triangle(extra)) {
    int a = edges[extra[0]].first;
    int b = edges[extra[0]].second;
    int e = dfs(a, -1, b);
    ans[e] = 1;
    ans[extra[0]] = 0;
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i];
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