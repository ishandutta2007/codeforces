#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long& x: a) cin >> x;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        ans = max(ans, a[i]|a[j]|a[k]);
      }
    }
  }
  cout << ans << '\n';
}