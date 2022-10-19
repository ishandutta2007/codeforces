#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), right(n), nex(n), pre(n, -1);
    iota(right.begin(), right.end(), 0);

    for (int& x: a) cin >> x;
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end())-b.begin());
    for (int& x: a) {
      x = lower_bound(b.begin(), b.end(), x)-b.begin();
    }

    vector<int> id(n, n);
    vector<vector<int>> indices(n);
    for (int i = 0; i < n; i++) {
      indices[a[i]].push_back(i);
    }
    for (int i = n-1; i >= 0; i--) {
      int z = id[a[i]];
      nex[i] = z;
      if (z != n) {
        pre[z] = i;
      }
      id[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      indices[i].push_back(n);
    }

    while (m--) {
      int l, r;
      cin >> l >> r;
      right[l-1] = max(right[l-1], r-1);
    }
    for (int i = 1; i < n; i++) {
      right[i] = max(right[i], right[i-1]);
    }

    int r = -1;
    for (int i = 0; i < n; i++) {
      if (nex[i] <= right[i]) {
        r = i;
      }
    }
    if (r == -1) {
      cout << "0\n";
      continue;
    }
    int ans = n;
    for (int l = 0; l < n; l++) {
      ans = min(ans, r-l+1);
      // remove l as an endpoint
      if (pre[l] != -1 && right[pre[l]] >= l) break;
      int j = *lower_bound(indices[a[l]].begin(), indices[a[l]].end(), r+1);
      if (j <= right[l]) r = j;
    }
    cout << ans << '\n';
  }
}