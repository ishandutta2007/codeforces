#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> a(n), b(m);
  for (int& x: a) cin >> x;
  for (int& x: b) cin >> x;
  if (k >= min(m, n)) {
    cout << "-1\n";
    return 0;
  }
  int ans = -1;
  for (int i = 0; i <= k; i++) {
    auto it = lower_bound(b.begin(), b.end(), a[i]+ta);
    int j = it-b.begin()+(k-i);
    if (j >= m) {
      cout << "-1\n";
      return 0;
    }
    ans = max(ans, b[j]+tb);
  }
  cout << ans << '\n';
}