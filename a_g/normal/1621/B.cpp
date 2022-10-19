#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int mn = 1e9+1;
    int mx = 0;
    int mncost = 1e9;
    int mxcost = 1e9;
    int lonecost = 2e9+1;
    for (int i = 0; i < n; i++) {
      int l, r, c;
      cin >> l >> r >> c;
      bool mn_change = 0;
      bool mx_change = 0;
      if (l < mn) {
        mn = l;
        mncost = c;
        mn_change = 1;
      }
      else if (l == mn) {
        if (c < mncost) {
          mncost = c;
        }
      }

      if (r > mx) {
        mx = r;
        mxcost = c;
        mx_change = 1;
      }
      else if (r == mx) {
        if (c < mxcost) {
          mxcost = c;
        }
      }
      if (mn_change || mx_change) lonecost = 2e9+1;
      if (l == mn && r == mx) {
        lonecost = min(lonecost, c);
      }
      cout << (min(lonecost, mncost+mxcost)) << '\n';
      //cout << mn << " " << mx << " " << mncost << " " << mxcost << " " << lonecost << '\n';
    }
  }
}