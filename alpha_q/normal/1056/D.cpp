#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;

vector <int> g[N];
int n, p[N], tot[N], ans[N];

void go (int u = 1) {
  if (g[u].empty()) {
    tot[u] = 1;
    return;
  }
  for (int v : g[u]) {
    go(v);
    tot[u] += tot[v];
  }
}

int main() {
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    scanf("%d", p + i);
    g[p[i]].push_back(i);
  }
  go();
  sort(tot + 1, tot + n + 1);
  for (int i = 1, j = 0; i <= n; ++i) {
    int cnt = upper_bound(tot + 1, tot + n + 1, i) - tot - 1;
    while (j < cnt) ans[++j] = i;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}