#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    int mn = 1e9;
    int mx = -1e9;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }
    if (k & 1) {
      for (int val: a) cout << mx-val << " ";
      cout << endl;
    }
    else {
      for (int val: a) cout << val-mn << " ";
      cout << endl;
    }
  }
}