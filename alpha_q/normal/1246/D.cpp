#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 100010;

vector <int> ans, h[N];
set <pair <int, int>> g[N];
int n, p[N], sz[N], dep[N];

void go (int u = 0) {
  dep[u] = 0;
  for (int v : h[u]) {
    go(v);
    dep[u] = max(dep[u], dep[v] + 1);
    g[u].emplace(-dep[v], v);
  }
}

void dfs (int u = 0) {
  // cout << u << endl;
  if (g[u].empty()) return;
  if (g[u].size() == 1) return dfs(g[u].begin() -> second);
  int at = g[u].begin() -> second, v = g[u].rbegin() -> second;
  ans.emplace_back(at);
  g[u].erase(make_pair(-dep[at], at));
  g[v].emplace(-dep[at], at);
  g[u].erase(make_pair(-dep[v], v));
  dep[v] = max(dep[v], 1 + dep[at]);
  g[u].emplace(-dep[v], v);
  return dfs(u);
}

int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    scanf("%d", p + i);
    h[p[i]].emplace_back(i);
  }
  go(); dfs();
  reverse(ans.begin(), ans.end());
  printf("0");
  int u = 0;
  while (!g[u].empty()) {
    u = g[u].begin() -> second;
    printf(" %d", u);
  }
  puts("");
  assert(ans.size() <= 1000000);
  printf("%d\n", (int) ans.size());
  // cerr << ans.size() << '\n';
  for (auto it : ans) printf("%d ", it);
  puts("");
  return 0;
}