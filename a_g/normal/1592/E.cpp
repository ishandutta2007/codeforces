#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int k = 0; k < 20; k++) {
    int pow = 1 << k;
    int read = -1;
    while (read < n) {
      int l = read;
      while (l < n && !(a[l] & pow)) l++;
      int r = l;
      while (r+1 < n && a[r+1] & pow) r++;
      if (l < r) {
        // on [l, r], a[i] && pow is true
        map<int, int> oddfirst;
        map<int, int> evenfirst;
        int prefix = 0;
        evenfirst[0] = 0;
        for (int i = 0; i < r-l+1; i++) {
          prefix = prefix ^ (a[l+i] >> k);
          if (i & 1) {
            if (evenfirst.count(prefix)) {
              ans = max(ans, i+1-evenfirst[prefix]);
            }
            else {
              evenfirst[prefix] = i+1;
            }
          }
          else {
            if (oddfirst.count(prefix)) {
              ans = max(ans, i+1-oddfirst[prefix]);
            }
            else {
              oddfirst[prefix] = i+1;
            }
          }
        }
      }
      read = r+1;
    }
  }
  cout << ans << endl;
}