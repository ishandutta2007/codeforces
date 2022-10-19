#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) ans++;
    }
    int ca = count(a.begin(), a.end(), 1);
    int cb = count(b.begin(), b.end(), 1);
    ans = min(ans, abs(ca-cb)+1);
    cout << ans << '\n';
  }
}