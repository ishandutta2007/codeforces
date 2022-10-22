#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 10;
int n, m, k, ans, out[N];
vector<pair<int, int>> g[N];
unsigned long long w[N], s[K][K], all;
inline unsigned long long rnd() {
  return (1ll * rand() << 31) | rand();
}
void dfs(int x, unsigned long long cur) {
  if (x == k + 1) {
    ans += (cur == all);
    return;
  }
  for (int i = 1; i <= x; ++i) {
    dfs(x + 1, cur + s[x][i]);
  }
}
int main() {
  srand(time(0));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    g[u].push_back(make_pair(w, v));
    ++out[u];
  }
  for (int i = 1; i <= n; ++i) {
    w[i] = rnd();
    all += w[i]; 
  }
  for (int i = 1; i <= n; ++i) {
    sort(g[i].begin(), g[i].end());
    int cnt = 0;
    for (auto p : g[i]) {
      s[out[i]][++cnt] += w[p.second];
    }
  }
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}