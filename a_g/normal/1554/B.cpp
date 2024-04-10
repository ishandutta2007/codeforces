#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    //ans >= n*(n-1)-2*k*n = n*(n-2k-1)
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    ll ans = -1e9;
    int minindex = max(1, n-2*k-1);
    for (ll i = n; i >= minindex; i--) {
      for (ll j = i-1; j >= 1; j--) {
        ans = max<ll>(ans, i*j-k*(a[i]|a[j]));
      }
    }
    cout << ans << endl;
  }
}