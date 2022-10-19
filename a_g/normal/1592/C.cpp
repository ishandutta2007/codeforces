#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int xors[N];
int a[N];
vector<int> nbrs[N];
bool mark[N];
int target;
bool win2;

void dfs(int v, int p) {
  xors[v] = a[v];
  int c = 0;
  for (int u: nbrs[v]) {
    if (u != p) {
      dfs(u, v);
      xors[v] ^= xors[u];
      c += mark[u];
    }
  }
  if (c > 1) win2 = 1;
  if (c && !xors[v]) win2 = 1;
  if (c || xors[v] == target) mark[v] = 1;
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
      mark[i] = 0;
      nbrs[i].clear();
    }
    target = 0;
    win2 = 0;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      target ^= a[i];
    }

    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }

    dfs(1, 1);
    if (!xors[1]) {
      cout << "YES\n";
      continue;
    }
    if (k == 2) {
      cout << "NO\n";
      continue;
    }
    cout << (win2 ? "YES" : "NO") << '\n';
  }
}