#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> w(n), b(m);
  for (int& x: w) cin >> x;
  for (int& x: b) cin >> x, x--;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    set<int> seen;
    for (int j = i-1; j >= 0; j--) {
      if (b[j] == b[i]) break;
      if (!seen.count(b[j])) {
        ans += w[b[j]];
        seen.insert(b[j]);
      }
    }
  }
  cout << ans << '\n';
}