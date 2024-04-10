#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    ll h;
    cin >> n >> h;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll low = 0;
    ll high = 1e18;
    while (low+1 < high) {
      ll mid = (low+high)/2;
      ll dmg = mid;
      for (int i = 0; i < n-1; i++) {
        dmg += min(mid, a[i+1]-a[i]);
      }
      if (dmg >= h) high = mid;
      else low = mid;
    }
    cout << high << '\n';
  }
}