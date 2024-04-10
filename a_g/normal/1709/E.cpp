#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N];
int a[N], as[N];
set<int> B[N];
// B[v] = set of all xor values of paths from 1 to something in subtree of v

int ans = 0;

void dfs(int v, int p) {
  as[v] = as[p]^a[v];
  bool bad = 0; // a[v] != 0
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    if (B[u].count(as[p])) bad = 1;
    if (B[u].size() > B[v].size()) {
      swap(B[u], B[v]);
    }
    for (int x: B[u]) {
      if (B[v].count(x^a[v])) {
        bad = 1;
        break;
      }
    }
    for (int x: B[u]) B[v].insert(x);
  }
  B[v].insert(as[v]);

  if (bad) {
    B[v].clear();
    ans++;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << '\n';
}