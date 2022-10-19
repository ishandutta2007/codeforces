#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int ans[N];
bool is_odyssey[N];
pair<int, int> nbr[N][2]; // nbr[v][w-1] -> {u, index of edge};
vector<tuple<int, int, int>> edges;
bool done[N];
int n, m;
int ptr;

void debug() {
  for (tuple<int, int, int> x: edges) {
    int u, v, w;
    tie(u, v, w) = x;
    cout << u << " " << v << " " << w << endl;
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << nbr[i][0].first << " " << nbr[i][0].second << " " << nbr[i][1].first << " " << nbr[i][1].second << endl;
  }
}

void orient_edge(int u, int v) {
  //cout << u << " " << v << endl;
  if (!u || !v) return;
  for (int w = 0; w < 2; w++) {
    if (nbr[u][w].first == v) {
      int i = nbr[u][w].second;
      if (get<0>(edges[i]) == u) {
        ans[i] = 1;
      }
      else {
        assert(get<1>(edges[i]) == u);
      }
      return;
    }
  }
  assert(0);
}

void orient_edge2(int u, int v, int i) {
  //cout << u << " " << v << " " << i << endl;
  //debug();
  if (get<0>(edges[i]) == u) {
    assert(get<1>(edges[i]) == v);
    ans[i] = 1;
  }
  else {
    assert(get<0>(edges[i]) == v && get<1>(edges[i]) == u);
  }
}

void dfs(int v, int p) {
  // orient all edges from v not going into p
  if (!v) return;
  if (done[v]) return;
  done[v] = 1;
  for (int i = 0; i < 2; i++) {
    int u = nbr[v][i].first;
    if (u != p) {
      if (done[u]) return;
      orient_edge(u, v);
      dfs(u, v);
    }
  }
}

void solve() {
  if (ptr >= edges.size()) {
    for (int i = 1; i <= n; i++) {
      if (!!nbr[i][0].first + !!nbr[i][1].first == 1) dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
      dfs(i, i);
    }
    return;
  }
  int u, v, w;
  tie(u, v, w) = edges[ptr];
  bool s = 0;
  if (!nbr[u][w-1].first) {
    swap(u, v);
    s = 1;
  }
  if (nbr[u][w-1].first) {
    int x = nbr[u][w-1].first;
    int i = nbr[u][w-1].second;
    nbr[u][w-1] = {0, 0};
    nbr[x][w-1] = {0, 0};
    int j = ptr++;
    int k = edges.size();
    edges.push_back(make_tuple(x, v, w));
    solve();
    if (ans[k]) {
      // x to u to v
      orient_edge2(x, u, i);
      orient_edge2(u, v, j);
    }
    else {
      orient_edge2(u, x, i);
      orient_edge2(v, u, j);
    }
    return;
  }

  nbr[u][w-1] = {v, ptr};
  nbr[v][w-1] = {u, ptr};
  ptr++;
  solve();
}

// USA TST 2011 Problem 2
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_tuple(u, v, w));
    if (w == 1) {
      is_odyssey[u] ^= 1;
      is_odyssey[v] ^= 1;
    }
  }
  solve();

  cout << accumulate(is_odyssey+1, is_odyssey+n+1, 0) << '\n';
  for (int i = 0; i < m; i++) {
    cout << (ans[i] ? '1' : '2');
  }
  cout << '\n';
}