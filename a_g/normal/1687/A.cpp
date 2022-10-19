#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    vector<long long> pref(n+1);
    for (int i = 0; i < n; i++) {
      pref[i+1] = pref[i] + a[i];
    }
    if (k >= n) {
      cout << pref[n] + 1LL*k*n - 1LL*n*(n+1)/2 << '\n';
    }
    else {
      long long ans = 0;
      for (int i = 0; i+k <= n; i++) {
        ans = max(ans, pref[i+k]-pref[i]);
      }
      ans += 1LL*k*k-1LL*k*(k+1)/2;
      cout << ans << '\n';
    }
  }
}