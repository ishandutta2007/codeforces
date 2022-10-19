#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    ll s = accumulate(a.begin(), a.end(), 0LL);
    int m = a.back();
    ll p = 0;
    ll ans = max(0LL, s-k);
    for (int i = 0; i < n-1; i++) {
      p += a[i];
      ll x = max((s-p + 1LL*(i+1)*m - k+i+1)/(i+2), 0LL);
      ans = min(ans, max(0LL, x+i+1));
    }
    cout << ans << '\n';
  }
}