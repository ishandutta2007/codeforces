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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] - b[i] > 1) {
        int d = a[i]-b[i]-1;
        ans += a[i]-b[i]-1;
        b[i] = a[i]-1;
      }
      else if (i < n-1) {
        b[i+1] += b[i]-a[i]+1;
      }
      for (int j = i+2; j <= min(n-1, i+a[i]); j++) {
        b[j]++;
      }
    }
    cout << ans << '\n';
  }
}