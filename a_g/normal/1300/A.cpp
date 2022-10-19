#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int num_zeros = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (!a[i]) num_zeros++;
      s += a[i];
    }
    int ans = num_zeros;
    if (s + num_zeros == 0) ans++;
    cout << ans << '\n';
  }
}