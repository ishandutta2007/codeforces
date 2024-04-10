#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+6;
vector<int> G[N];
int invfib[N], sz[N], fib[100], par[N];

void fail() {
  cout << "NO\n";
  exit(0);
}

int dfs(int v, int p, int k) {
  sz[v] = 1;
  int ans = 0;
  par[v] = p;
  for (int u: G[v]) {
    if (u != p) {
      int z = dfs(u, v, k);
      if (z) {
        ans = z;
      }
      sz[v] += sz[u];
    }
  }
  if (sz[v] == fib[k-1] || k >= 2 && sz[v] == fib[k-2]) {
    ans = v;
  }
  return ans;
}

void check(int v, int k) {
  if (k <= 1) return;
  int z = dfs(v, v, k);
  if (!z) fail();
  int p = par[z];
  G[p].erase(find(G[p].begin(), G[p].end(), z));
  G[z].erase(find(G[z].begin(), G[z].end(), p));
  if (sz[z] == fib[k-1]) {
    check(z, k-1);
    check(p, k-2);
  }
  else {
    check(z, k-2);
    check(p, k-1);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x = 1, y = 2, z = 1;
  while (x < N) {
    fib[z] = x;
    invfib[x] = z;
    x += y;
    swap(x, y);
    z++;
  }

  int n;
  cin >> n;
  if (!invfib[n]) fail();
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  check(1, invfib[n]);
  cout << "YES\n";
}