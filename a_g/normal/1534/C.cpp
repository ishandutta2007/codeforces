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
    vector<int> p(n+1), a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    for (int i = 0; i < n; i++) {
      p[a[i]] = b[i];
    }
    vector<bool> vis(n+1);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      ans = 2LL * ans % MOD;
      int v = i;
      while (!vis[v]) {
        vis[v] = 1;
        v = p[v];
      }
    }
    cout << ans << '\n';
  }
}