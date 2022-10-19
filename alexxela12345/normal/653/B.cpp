#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  vector<int> dp1(6);
  dp1[0] = 1;
  int n, q;
  cin >> n >> q;
  vector<pair<string, char>> arr(q);
  for (int i = 0; i < q; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  for (int i = 1; i < n; i++) {
    vector<int> dp2(6);
    for (auto &el : arr) {
      dp2[el.first[0] - 'a'] += dp1[el.second - 'a'];
    }
    dp1 = dp2;
  }
  int ans = 0;
  for (int i = 0; i < 6; i++) 
    ans += dp1[i];
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}