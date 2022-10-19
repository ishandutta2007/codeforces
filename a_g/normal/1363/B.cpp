#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
      a[i+1] = a[i] + s[i]-'0';
    }
    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
      ans = min(ans, a[i]+(n-i)-(a[n]-a[i]));
      ans = min(ans, (i-a[i])+(a[n]-a[i]));
    }
    cout << ans << '\n';
  }
}