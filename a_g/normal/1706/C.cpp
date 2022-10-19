#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int i = 1; i < n-1; i++) {
      b[i] = max({a[i], a[i-1]+1, a[i+1]+1})-a[i];
    }
    long long c = 0;
    for (int i = 1; i < n-1; i += 2) {
      c += b[i];
    }
    long long ans = c;
    if (n&1) {
      cout << ans << '\n';
      continue;
    }
    for (int i = n-2; i >= 2; i -= 2) {
      c += b[i]-b[i-1];
      ans = min(ans, c);
    }
    cout << ans << '\n';
  }
}