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
    ll ans = 0;
    ll prev, val;
    cin >> prev;
    for (int i = 0; i < n-1; i++) {
      cin >> val;
      ans = max(ans, prev*val);
      prev = val;
    }
    cout << ans << endl;
  }
}