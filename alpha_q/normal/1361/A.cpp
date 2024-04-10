#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

bitset <N> done;
vector <int> g[N], yo[N];
int n, m, t[N], p[N], ans[N];

int main() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", t + i);
    yo[t[i]].emplace_back(i);
  }
  int ptr = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j : yo[i]) p[++ptr] = j;
  }
  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= n; ++i) {
    int u = p[i];
    for (int v : g[u]) if (~ans[v]) done[ans[v]] = 1;
    ans[u] = 1; 
    while (done[ans[u]]) ++ans[u];
    for (int v : g[u]) if (~ans[v]) done[ans[v]] = 0;
  }
  for (int i = 1; i <= n; ++i) if (ans[i] != t[i]) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]); cout << '\n';
  return 0;
}