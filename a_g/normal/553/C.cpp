#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+5;
vector<int> G[N];
int parity[N];

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

void dfs(int v, int b) {
  if (parity[v] != -1) {
    if (parity[v] != b) {
      cout << "0\n";
      exit(0);
    }
    return;
  }
  parity[v] = b;
  for (int u: G[v]) {
    dfs(u, 1-b);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu D(n);
  vector<pair<int, int>> hate;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if (c == 1) {
      D.join(a, b);
    }
    else {
      hate.emplace_back(a, b);
    }
  }
  for (auto& [a, b]: hate) {
    int u = D.root(a);
    int v = D.root(b);
    if (D.root(a) == D.root(b)) {
      cout << "0\n";
      return 0;
    }
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  for (int i = 0; i < n; i++) {
    parity[i] = -1;
  }

  int components = 0;
  for (int i = 0; i < n; i++) {
    if (D.parents[i] == i) {
      if (parity[i] == -1) {
        components++;
        dfs(i, 0);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < components-1; i++) {
    ans = 2*ans % MOD;
  }
  cout << ans << '\n';
}