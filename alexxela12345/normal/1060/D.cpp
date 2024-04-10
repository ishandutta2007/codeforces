#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

#define endl '\n'

void solve() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += max(l[i], r[i]);
  }
  cout << ans + n << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}