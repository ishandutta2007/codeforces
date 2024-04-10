#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  vector<int> a(n, h);
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int i = l-1; i <= r-1; i++) {
      a[i] = min(a[i], x);
    }
  }
  int ans = 0;
  for (int& x: a) ans += x*x;
  cout << ans << '\n';
}