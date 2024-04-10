#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    vector<long long> as(n+1);
    for (int i = 0; i < n; i++) {
      as[i+1] = as[i] + a[i];
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
      // use good keys on the first i chests
      long long z = as[i]-1LL*k*i;
      for (int j = i; j < min(n, i+31); j++) {
        z += a[j]>>(j-i+1);
      }
      ans = max(ans, z);
    }
    cout << ans << '\n';
  }
}