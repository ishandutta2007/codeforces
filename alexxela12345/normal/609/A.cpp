#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> arr(n);
  for (int i= 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.rbegin(), arr.rend());
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += arr[i];
    ans++;
    if (cur >= m)
      break;
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}