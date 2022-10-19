#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());
    ll ans = d[n-1];
    for (int i = 1; i < n; i++)  {
      ans += (n-1-2*i)*d[i];
    }
    cout << ans << endl;
  }
}