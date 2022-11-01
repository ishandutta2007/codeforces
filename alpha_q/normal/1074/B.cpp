#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1010;

bitset <N> good, bad;
vector <int> g[N];
int t, n, k_1, k_2, a[N], b[N], par[N];

inline int ask (int who, int x) {
  if (who) {
    printf("B %d\n", x);
  } else {
    printf("A %d\n", x);
  }
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

void dfs (int u, int from = -1) {
  par[u] = from;
  for (int v : g[u]) {
    if (v != from) dfs(v, u);
  }
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      par[i] = -1;
    }
    good.reset();
    bad.reset();
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    scanf("%d", &k_1);
    for (int i = 1; i <= k_1; ++i) {
      scanf("%d", a + i);
      good[a[i]] = 1;
    }
    dfs(a[1]);
    scanf("%d", &k_2);
    for (int i = 1; i <= k_2; ++i) {
      scanf("%d", b + i);
      bad[b[i]] = 1;
    }
    int from = ask(1, b[1]);
    int u = from;
    if (good[u]) {
      printf("C %d\n", u);
      fflush(stdout);
      continue;
    }
    while (!good[u]) {
      u = par[u];
    }
    int now = ask(0, u);
    if (bad[now]) {
      printf("C %d\n", u);
      fflush(stdout);
      continue;
    }
    printf("C -1\n");
    fflush(stdout);
  }
  return 0;
}