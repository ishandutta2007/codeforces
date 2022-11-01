#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector <int> g[N], ans;
int t, cs, n, k, p[N], h[N], rem;

void go (int u = 1, int far = 0) {
  h[u] = far;
  for (int v : g[u]) go(v, far + 1);
}

void dfs (int u) {
  if (!rem) return;
  ans.emplace_back(u), --rem;
  for (int v : g[u]) if (rem) {
    dfs(v); ans.emplace_back(u);
  }
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
      scanf("%d", p + i);
      g[p[i]].emplace_back(i);
    }
    int leaf = 1; go();
    for (int i = 1; i <= n; ++i) {
      if (h[i] > h[leaf]) leaf = i;
    }
    vector <int> path({leaf});
    while (leaf > 1) leaf = p[leaf], path.emplace_back(leaf);
    reverse(path.begin(), path.end());
    // for (int x : path) cerr << x << " "; cerr << '\n';
    if (path.size() >= k) {
      printf("%d\n", k - 1);
      for (int i = 0; i < k; ++i) printf("%d ", path[i]);
      puts(""); continue;
    }
    rem = k - path.size(); ans.clear();
    for (int i = 0; i < path.size(); ++i) {
      int u = path[i];
      ans.emplace_back(u);
      for (int v : g[u]) if (rem and v != path[i + 1]) {
        dfs(v);
        ans.emplace_back(u);
      }
    }
    cout << int(ans.size()) - 1 << '\n';
    for (int x : ans) printf("%d ", x); puts("");
  }
  return 0;
}