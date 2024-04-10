#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
vector<int> G[N];
int parity[N];
bool vis[N];
bool good = 1;

void dfs(int v, int p, int x) {
  vis[v] = 1;
  if (parity[v] != -1) {
    if (parity[v] != x) good = 0;
    return;
  }
  parity[v] = x;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v, 1-x);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    good = 1;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b) good = 0;
      else {
        G[a].push_back(b);
        G[b].push_back(a);
      }
    }
    fill(parity+1, parity+n+1, -1);
    for (int i = 1; i <= n; i++) {
      if (G[i].size() >= 3) {
        good = 0;
        break;
      }
      if (!vis[i]) dfs(i, i, 0);
    }

    cout << (good ? "YES" : "NO") << '\n';

    for (int i = 1; i <= n; i++) {
      G[i].clear();
      vis[i] = 0;
    }
  }
}