#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n), done(n), vis(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      if (c) done[c-1] = 1;
    }
    for (int i = 0; i < n; i++) {
      p[a[i]-1] = b[i]-1;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      bool d = 0;
      int len = 0;
      while (!vis[i]) {
        len++;
        if (done[i]) d = 1;
        vis[i] = 1;
        i = p[i];
      }
      if (!d && len > 1) {
        ans = 2*ans % MOD;
      }
    }
    cout << ans << '\n';
  }
}