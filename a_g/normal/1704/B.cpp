#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& z: a) cin >> z;
    int ans = 0;
    int mn = 1e9;
    int mx = -1e9;
    for (int z: a) {
      mn = min(mn, z);
      mx = max(mx, z);
      if (mx-mn > 2*x) {
        ans++;
        mn = z;
        mx = z;
      }
    }
    cout << ans << '\n';
  }
}