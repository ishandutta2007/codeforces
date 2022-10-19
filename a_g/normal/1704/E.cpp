#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1005;
vector<int> G[N];
int a[N], indeg[N];
bool b[N];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

bool check(int n) {
  for (int v = 1; v <= n; v++) {
    if (a[v]) {
      for (int u: G[v]) {
        if (!a[u]) return 0;
      }
    }
  }
  return 1;
}

void work(int n) {
  for (int v = 1; v <= n; v++) {
    b[v] = (a[v] > 0);
  }
  for (int v = 1; v <= n; v++) {
    if (b[v]) {
      a[v]--;
      for (int u: G[v]) a[u]++;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      indeg[v]++;
    }
    vector<int> topo;
    for (int i = 1; i <= n; i++) {
      if (indeg[i] == 0) topo.push_back(i);
    }
    for (int i = 0; i < (int)topo.size(); i++) {
      int v = topo[i];
      for (int u: G[v]) {
        indeg[u]--;
        if (indeg[u] == 0) {
          topo.push_back(u);
        }
      }
    }

    long long s = accumulate(a+1, a+n+1, 0LL);
    int steps = 0;
    while (!check(n) && s != 0) {
      steps++;
      work(n);
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] >= MOD) a[i] -= MOD;
    }
    for (int v: topo) {
      for (int u: G[v]) {
        add(a[u], a[v]);
      }
    }
    add(steps, a[topo.back()]);
    cout << steps << '\n';

    for (int i = 1; i <= n; i++) {
      G[i].clear();
      indeg[i] = 0;
    }
  }
}