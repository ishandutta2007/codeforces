#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector <int> g[N];
int n, d[N], par[N];

void go (int u, int pr = -1, int far = 0) {
  d[u] = far, par[u] = pr;
  for (int v : g[u]) if (v ^ pr) {
    go(v, u, far + 1);
  }
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  int root;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 1) {
      root = i; break;
    }
  }
  go(root);
  int ev = 0, od = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == root) continue;
    if (g[i].size() > 1) continue;
    if (d[i] & 1) ++od; else ++ev;
  }
  int one, two = n - 1;
  if (od == 0) one = 1; else one = 3;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 1) continue;
    int leaf = 0;
    for (int j : g[i]) if (g[j].size() == 1) ++leaf;
    if (leaf > 0) two -= (leaf - 1);
  }
  cout << one << " " << two << '\n';
  return 0;
}