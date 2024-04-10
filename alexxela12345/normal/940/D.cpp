#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  int r = 1e9;
  int l = -r;
  for (int i = 4; i < n; i++) {
    if (s[i] != s[i - 1]) {
      if (s[i] == '1') {
        l = max(l, arr[i - 4] + 1);
        l = max(l, arr[i - 3] + 1);
        l = max(l, arr[i - 2] + 1);
        l = max(l, arr[i - 1] + 1);
        l = max(l, arr[i] + 1);
      } else {
        r = min(r, arr[i - 4] - 1);
        r = min(r, arr[i - 3] - 1);
        r = min(r, arr[i - 2] - 1);
        r = min(r, arr[i - 1] - 1);
        r = min(r, arr[i] - 1);
      }
    }
  }
  r = max(l, r);
  l = min(l, r);
  r = max(l, r);
  cout << l << " " << r << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}