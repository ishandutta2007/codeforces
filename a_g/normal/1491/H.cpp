#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+500;
const int B = 300;
const int INF = 1e9;
int a[N], f[N], lazy[N/B];
bool finish[N/B];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  a[1] = 1;
  for (int i = 2; i <= n; i++) cin >> a[i];

  function<int(int)> par = [&] (int v) {
    return max(a[v]-lazy[v/B], 1);
  };
  function<void(int)> calc = [&] (int u) {
    if (finish[u]) return;
    finish[u] = 1;
    for (int i = u*B; i < (u+1)*B; i++) {
      if (i == 1 || par(i)/B < u) {
        f[i] = i;
      }
      else {
        finish[u] = 0;
        f[i] = f[par(i)];
      }
    }
  };
  for (int u = 0; u <= n/B; u++) {
    calc(u);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      int lower = (l-1)/B+1;
      int upper = (r+1)/B;
      if (lower > upper) {
        for (int j = l; j <= r; j++) {
          a[j] = max(1, a[j]-x);
        }
        calc(l/B);
        continue;
      }
      for (int j = l; j < lower*B; j++) {
        a[j] = max(1, a[j]-x);
      }
      for (int j = upper*B; j <= r; j++) {
        a[j] = max(1, a[j]-x);
      }
      for (int u = lower; u < upper; u++) {
        lazy[u] = min(lazy[u]+x, INF);
        calc(u);
      }
      if (lower) calc(lower-1);
      calc(upper);
    }
    else {
      int u, v;
      cin >> u >> v;
      while (u != v) {
        if (u > v) swap(u, v);
        if (u/B < v/B) {
          v = par(f[v]);
          continue;
        }
        v = par(v);
      }
      cout << u << '\n';
    }
  }
}