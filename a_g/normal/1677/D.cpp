#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& x: v) cin >> x;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      // pick the original sequence
      if (i < k || v[i-k] == -1) {
        ans = 1LL * ans * (i+1) % MOD;
      }
      else {
        // could be anything from 0 to i
        if (v[i-k] == 0) {
          ans = 1LL * ans * (k+1) % MOD;
        }
      }
    }
    for (int i = n-k; i < n; i++) {
      if (v[i] > 0) ans = 0;
    }
    cout << ans << '\n';
  }
}