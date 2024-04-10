#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    int res = 0;
    for (int i = 1; i < n; i++) {
      int mx = max(a[i], a[i - 1]), mn = min(a[i], a[i - 1]);
      while (mn * 2 < mx) mn *= 2, res++;
    }
    cout << res << '\n';
  }

  return 0;
}