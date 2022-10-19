#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pref(n+1);
    for (int i = 0; i < n; i++) {
      pref[i+1] = pref[i] + (s[i] == 'B');
    }
    int ans = k;
    for (int i = 0; i+k <= n; i++) {
      ans = min(ans, k-pref[i+k]+pref[i]);
    }
    cout << ans << '\n';
  }
}