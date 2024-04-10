#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(1);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for (int& x: a) cin >> x;
    for (int& x: t) cin >> x;
    int L = -1e9;
    int R = -1e9;
    for (int i = 0; i < n; i++) {
      L = max(L, t[i]-a[i]);
      R = max(R, a[i]+t[i]);
    }
    cout << (double)(R-L)/2 << '\n';
  }
}