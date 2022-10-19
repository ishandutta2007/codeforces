#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (char c: "abcde") {
      vector<int> b(n);
      for (int i = 0; i < n; i++) {
        b[i] = 2*count(a[i].begin(), a[i].end(), c)-a[i].size();
      }
      sort(b.begin(), b.end(), greater<int>());
      if (b[0] < 0) continue;
      int diff = 0;
      for (int i = 0; i < n; i++) {
        diff += b[i];
        if (diff > 0) ans = max(ans, i+1);
        else break;
      }
    }
    cout << ans << endl;
  }
}