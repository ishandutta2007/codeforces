#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int cntZero = 0;
  vector<int> cnt(k);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 0; i < k; i++) {
    if (cnt[i] == 0)
      cntZero++;
  }
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    s.insert({b[i], i});
  }
  int ans = 0;
  while (cntZero) {
    auto pp = *s.begin();
    s.erase(s.begin());
    if (cnt[a[pp.second]] > 1) {
      cntZero--;
      cnt[a[pp.second]]--;
      ans += pp.first;
    }
  }
  cout << ans << endl;
}