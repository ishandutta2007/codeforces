#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int u, v;
    cin >> u >> v;
    if (__builtin_popcount(v) > __builtin_popcount(u) || u > v) {
      cout << "NO\n";
      continue;
    }
    bool fail = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 30; i++) {
      int z = 1<<i;
      if (v&z) y++;
      if (u&z) x++;
      if (y > x) {
        fail = 1;
        break;
      }
    }
    cout << (fail ? "NO" : "YES") << '\n';
  }
}