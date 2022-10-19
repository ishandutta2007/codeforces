#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int p[N], d[N];
bool vis[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      d[u]++;
      d[v]++;
    }

    for (int i = 1; i <= n; i++) cin >> p[i];
    int cycles = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        int v = i;
        cycles++;
        while (!vis[v]) {
          vis[v] = 1;
          v = p[v];
        }
      }
    }

    int center = -1;
    for (int i = 1; i <= n; i++) {
      if (d[i] == n-1) {
        center = i;
      }
    }

    bool win = 0;

    if (center != -1) {
      bool a = x == center;
      bool b = p[center] == center;
      if (a && b) win = (n+cycles)&1;
      if (a && !b) win = 0;
      if (!a) win = 1-(n+cycles)&1;
      if (!a && !b && p[center] == x) win = 0;
    }
    else {
      win = 1;
    }
    vector<int> z;
    for (int i = 1; i <= n; i++) {
      if (p[i] != i) z.push_back(i);
    }
    if (z.size() == 0) win = 1;
    if (z.size() == 2 && x != z[0] && x != z[1]) win = 1;

    cout << (win ? "Alice" : "Bob") << '\n';

    fill(d+1, d+n+1, 0);
    fill(vis+1, vis+n+1, 0);
  }
}