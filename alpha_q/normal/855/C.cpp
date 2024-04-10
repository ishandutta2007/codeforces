#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int X = 13;
const int N = 100010;
const int MOD = 1e9 + 7;

vector <int> g[N];
int n, m, k, x, f[N][X][3], sib[N], child[N];

inline int add (int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

void go (int u, int from = -1) {
  int sz = g[u].size();
  if (sz) {
    if (g[u][0] != from) child[u] = g[u][0];
    else if (sz > 1) child[u] = g[u][1];
  }
  for (int i = 0, j = 0; i < sz; ++i) {
    int v = g[u][i];
    if (v == from) continue;
    if (i + 1 < sz) {
      if (g[u][i + 1] != from) sib[v] = g[u][i + 1];
      else if (i + 2 < sz) sib[v] = g[u][i + 2];
    }
    go(v, u);
  }
}

// up = 0 (less), 1 (equ), 2 (big)
int call (int u, int rem, int up) {
  if (u < 0) return rem == 0;
  if (f[u][rem][up] != -1) return f[u][rem][up];

  int smol = 0, equ = 0, big = 0;
  
  for (int i = 0; i <= rem; ++i) {
    smol = add(smol, call(child[u], i, 0) * 1LL * call(sib[u], rem - i, up) % MOD);
    if (smol >= MOD) smol -= MOD;
  }
  smol = (k - 1) * 1LL * smol % MOD;
  
  if (up == 0 and rem) {
    for (int i = 0; i < rem; ++i) {
      equ = add(equ, call(child[u], i, 1) * 1LL * call(sib[u], rem - 1 - i, up) % MOD);
    }
  }
  
  if (up != 1) {
    for (int i = 0; i <= rem; ++i) {
      big = add(big, call(child[u], i, 2) * 1LL * call(sib[u], rem - i, up) % MOD);
    }
  }
  big = (m - k) * 1LL * big % MOD;

  return f[u][rem][up] = add(equ, add(smol, big));
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d %d", &k, &x);
  memset(f, -1, sizeof f);
  memset(sib, -1, sizeof sib);
  memset(child, -1, sizeof child);
  go(1);
  int ans = 0;
  for (int i = 0; i <= x; ++i) {
    ans += call(1, i, 0);
    if (ans >= MOD) ans -= MOD;
  }
  printf("%d\n", ans);
  return 0;
}