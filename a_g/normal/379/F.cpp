#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;
const int K = 21;
int up[N][K], dep[N];

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = K-1; i >= 0; i--) {
    if (dep[u] <= dep[v]-(1<<i)) {
      v = up[v][i];
    }
  }
  if (u == v) return u;
  for (int i = K-1; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

void make_child(int p, int v) {
  up[v][0] = p;
  dep[v] = dep[p]+1;
  for (int i = 1; i < K; i++) {
    up[v][i] = up[up[v][i-1]][i-1];
  }
}

int dist(int u, int v) {
  return dep[u]+dep[v]-2*dep[lca(u, v)];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  for (int v: {2, 3, 4}) {
    make_child(1, v);
  }
  int x = 2;
  int y = 3;
  int ans = 2;
  int n = 4;
  while (q--) {
    int v;
    cin >> v;
    make_child(v, n+1);
    make_child(v, n+2);
    int dx = dist(x, n+1);
    int dy = dist(y, n+1);
    if (dx > ans) {
      y = n+1;
      ans = dx;
    }
    else if (dy > ans) {
      x = n+1;
      ans = dy;
    }
    n += 2;
    cout << ans << '\n';
  }
}