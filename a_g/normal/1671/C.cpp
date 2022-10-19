#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
      a[i] += a[i-1];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > x) break;
      ans += (x-a[i])/(i+1)+1;
    }
    cout << ans << '\n';
  }
}