#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int n;
bitset <123> vis, cur;

int main() {
  for (int i = 1; i <= 100; ++i) {
    vis[i] = 1;
  }
  cin >> n;
  while (n--) {
    int sz; cin >> sz;
    cur.reset();
    while (sz--) {
      int x; cin >> x;
      cur[x] = 1;
    }
    vis &= cur;
  }
  for (int i = 1; i <= 100; ++i) {
    if (vis[i]) cout << i << " ";
  }
  cout << '\n';
  return 0;
}