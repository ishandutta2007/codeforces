#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);
    s.emplace(a, b);
  }
  int _n = n;
  auto check = [&] (int r) {
    for (auto& [a, b]: s) {
      int u = (a+r)%n;
      int v = (b+r)%n;
      if (u > v) swap(u, v);
      if (!s.count(make_pair(u, v))) return false;
    }
    return true;
  };
  for (int p = 2; p <= _n; p++) {
    if (_n%p == 0) {
      if (check(n/p)) {
        cout << "Yes\n";
        return 0;
      }
      while (_n%p == 0) _n /= p;
    }
  }
  cout << "No\n";
}