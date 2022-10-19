#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#pragma GCC optimize ("unroll-loops")
using namespace std;

unordered_map<ll, int> cache;
unordered_set<ll> combos;
int n, m;

ll conv(pii p) {
  return (2e5+1)*(ll)p.first + p.second;
}

int search(int x, int y) {
  if (cache.count(conv({x, y}))) return cache[conv({x, y})];
  if (x == n && y == m) return 0;
  int hit = combos.count(conv({x, y}));
  int tx = min(x+y+hit, n);
  int ty = min(x+y+hit, m);

  int u = x;
  int v = y;
  if (x == n) v = ty;
  else if (y == m) u = tx;
  else if (tx == n) u = tx;
  else if (ty == m) v = ty;
  else if (ty-y >= tx-x) v = ty;
  else u = tx;
  cache[conv({x, y})] = search(u, v)+1;
  return cache[conv({x, y})];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> m >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    combos.insert(conv({a, b}));
  }

  int ans = 1e9;
  for (int i = 0; i < 4; i++) {
    // fix the first 2 steps
    int x = 1;
    int y = 1;
    int iters = 0;
    for (int j = 0; j < 2; j++) {
      if (x == n && y == m) break;
      int hit = combos.count(conv({x, y}));
      if ((i>>j)&1) {
        x = min(x+y+hit, n);
      }
      else {
        y = min(x+y+hit, m);
      }
      iters++;
    }
    if (x < n || y < m) {
      iters += search(x, y);
    }
    ans = min(ans, iters);
  }
  cout << ans << endl;
}