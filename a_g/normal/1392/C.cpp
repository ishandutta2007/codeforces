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
    int height = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      if (val < prev) ans += prev-val;
      height = max(height, val);
      prev = val;
    }
    cout << ans << endl;
  }
}