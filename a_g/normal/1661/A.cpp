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
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    long long ans = 0;
    for (int i = 0; i < n-1; i++) {
      ans += min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]), abs(a[i]-b[i+1])+abs(b[i]-a[i+1]));
    }
    cout << ans << '\n';
  }
}