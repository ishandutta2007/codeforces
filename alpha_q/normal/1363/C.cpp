#include <bits/stdc++.h>

using namespace std;

int t, n, x, deg[6969];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) deg[i] = 0;
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v;
      ++deg[u], ++deg[v];
    }
    if (deg[x] <= 1) puts("Ayush");
    else puts((n & 1) ? "Ashish" : "Ayush");
  }
  return 0;
}