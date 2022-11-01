#include <bits/stdc++.h>

using namespace std;

int t, n, id[1234];

int get (int l, int r) {
  cout << 1 << " " << r - l + 1 << " 1";
  for (int i = l; i <= r; ++i) cout << " " << i;
  cout << endl; int ret; cin >> ret; return ret;
}

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> t;
  while (t--) {
    cin >> n;
    int mx = get(2, n), lo = 2, hi = n;
    while (lo < hi) {
      int mid = lo + hi >> 1;
      if (get(lo, mid) == mx) hi = mid;
      else lo = mid + 1;
    }
    cout << 1 << " " << n - 1 << " " << lo;
    for (int i = 1; i <= n; ++i) if (i != lo) cout << " " << i;
    cout << endl; int ans; cin >> ans;
    cout << "-1 " << ans << endl;
  }
  return 0;
}