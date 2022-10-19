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
    for (int& x: a) cin >> x;
    int ans = 0;
    for (int i = n-2; i >= 0; i--) {
      if (a[i+1] == 0) {
        ans = -1;
        break;
      }
      while (a[i+1] <= a[i]) {
        ans++;
        a[i] /= 2;
      }
    }

    cout << ans << '\n';
  }
}