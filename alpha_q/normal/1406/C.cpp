#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int t, n, sub[N];
vector <int> g[N];

void go (int u = 1, int pr = -1) {
  sub[u] = 1;
  for (int v : g[u]) if (v ^ pr) {
    go(v, u);
    sub[u] += sub[v];
  }
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    if (n & 1) {
      printf("1 %d\n1 %d\n", g[1][0], g[1][0]);
      continue;
    }
    go();
    int u = 1, pr = -1;
    while (true) {
      bool found = 0;
      for (int v : g[u]) if (v ^ pr) {
        if (sub[v] > n / 2) {
          found = 1, pr = u, u = v;
          break;
        }
      }
      if (!found) break;
    }
    bool good = 1;
    for (int v : g[u]) if (v ^ pr) {
      if (sub[v] == n / 2) {
        int leaf = v, par = u;
        while (g[leaf].size() > 1) {
          int nxt = (g[leaf][0] == par ? g[leaf][1] : g[leaf][0]);
          par = leaf, leaf = nxt;
        }
        printf("%d %d\n%d %d\n", par, leaf, u, leaf);
        good = 0;
        break;
      }
    }
    if (good) {
      printf("1 %d\n1 %d\n", g[1][0], g[1][0]);
    }
  }
  return 0;
}