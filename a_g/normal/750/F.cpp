#include <bits/stdc++.h>
using namespace std;

const int N = 128;
int ans = -1, queries = 0;
vector<int> G[N];
vector<int> path;

void query(int v) {
  queries++;
  cout << "? " << v << endl;
  int k;
  cin >> k;
  G[v].resize(k);
  if (k == 2) ans = v;
  for (int& x: G[v]) cin >> x;
}

void dfs() {
  if (ans != -1) return;
  for (int u: G[path.back()]) {
    if (G[u].empty()) {
      path.push_back(u);
      query(u);
      dfs();
      return;
    }
  }
}

void solve(int h) {
  path.push_back(1);
  query(1);
  if ((int)G[1].size() == 3) {
    dfs();
    reverse(path.begin(), path.end());
    dfs();
  }
  while (1) {
    if (ans != -1) return;
    int k = ((int)path.size()+1)/2;
    if (k >= h-3) break;
    path.resize(k);
    dfs();
  }
  int k = ((int)path.size()+1)/2;
  int v = path[k-1];
  if (k == h-1) {
    for (int u: G[v]) {
      if (G[u].empty()) {
        ans = u;
        return;
      }
    }
    assert(0);
  }
  else if (k == h-2) {
    assert(queries <= 12);
    for (int u: G[v]) {
      if (G[u].empty()) {
        query(u);
        for (int w: G[u]) {
          if (G[w].empty()) {
            query(w);
          }
        }
      }
    }
    assert(ans != -1);
    return;
  }
  assert(queries <= 10);
  int t = -1;
  for (int u: G[v]) {
    if (G[u].empty()) {
      t = u;
      break;
    }
  }
  assert(t != -1);
  query(t);
  G[t].erase(find(G[t].begin(), G[t].end(), v));
  assert((int)G[t].size() == 2);
  for (int i = 0; i < 2; i++) {
    query(G[t][i]);
    G[G[t][i]].erase(find(G[G[t][i]].begin(), G[G[t][i]].end(), t));
    if ((int)G[G[t][i]].size() != 2) continue;
    for (int j = 0; j < 2; j++) {
      if (i+j < 2) {
        query(G[G[t][i]][j]);
      }
    }
  }
  if (ans == -1) ans = G[G[t][1]][1];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int h;
    cin >> h;
    solve(h);
    cout << "! " << ans << endl;
    for (int v = 1; v < (1<<h); v++) {
      G[v].clear();
    }
    ans = -1;
    path.clear();
    queries = 0;
  }
}