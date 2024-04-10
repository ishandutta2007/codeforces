#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n;
  vector<ll> a(n);
  ll totalstrength = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    totalstrength += a[i];
  }
  sort(a.begin(), a.end());
  cin >> m;
  for (int i = 0; i < m; i++) {
    ll x, y;
    ll ans=0;
    cin >> x >> y;
    int low = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (low == n) low = n-1;
    ans = max<ll>(0, x - a[low]) + max<ll>(0, y+a[low] - totalstrength);
    if (low > 0) {
      ans = min<ll>(ans, x - a[low-1] + max<ll>(0, y+a[low-1] - totalstrength));
    }
    cout << ans << '\n';
  }
}