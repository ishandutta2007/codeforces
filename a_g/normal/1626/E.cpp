#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;

int c[N];
int csum[N];
vector<int> nbrs[N];
vector<int> nbrs2[N];
int tot_black;
int ans[N];

void dfs1(int v, int p) {
  csum[v] = c[v];
  for (int u: nbrs[v]) {
    if (u != p) {
      dfs1(u, v);
      csum[v] += csum[u];
      if (c[u] || csum[u] > 1) nbrs2[u].push_back(v);
      if (c[v] || tot_black-csum[u] > 1) nbrs2[v].push_back(u);
    }
  }
}

void dfs2(int v) {
  if (ans[v]) return;
  ans[v] = 1;
  for (int u: nbrs2[v]) dfs2(u);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];
  tot_black = accumulate(c+1, c+n+1, 0);

  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    nbrs[u].push_back(v);
    nbrs[v].push_back(u);
  }

  dfs1(1, 1);
  for (int v = 1; v <= n; v++) {
    if (c[v]) dfs2(v);
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
}