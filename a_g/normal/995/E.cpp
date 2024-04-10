#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> ops;

int dist(int x, int y) {
  int g = __gcd(x, y);
  x /= g;
  y /= g;
  if (!x) return 0;
  if (x < y) return 1 + dist(y, x);
  return x/y + dist(x%y, y);
}

void construct_path(int u, int p) {
  ops.clear();
  if (!u) return;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while (1) {
    int y = rng() % p;
    if (!y) continue;
    int x = 1LL * u * y % p;
    if (dist(x, y) > 99) continue;
    while (1) {
      for (int i = 0; i < x/y; i++) {
        ops.push_back(1);
      }
      x -= (x/y)*y;
      if (!x) break;
      ops.push_back(3);
      swap(x, y);
    }
    return;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int u, v, p;
  cin >> u >> v >> p;
  construct_path(u, p);
  vector<int> ans;
  for (int i: ops) {
    if (i != 3) i = 3-i;
    ans.push_back(i);
  }
  construct_path(v, p);
  reverse(ops.begin(), ops.end());
  ans.insert(ans.end(), ops.begin(), ops.end());
  cout << ans.size() << '\n';
  for (int i: ans) cout << i << ' ';
  cout << '\n';
}