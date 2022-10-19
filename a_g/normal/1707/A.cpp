#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    string ans(n, '0');
    int s = 0;
    for (int i = n-1; i >= 0; i--) {
      if (a[i] > s && s < q) {
        ans[i] = '1';
        s++;
      }
      else if (a[i] <= s) {
        ans[i] = '1';
      }
    }
    cout << ans << '\n';
  }
}