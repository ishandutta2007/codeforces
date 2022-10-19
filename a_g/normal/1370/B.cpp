#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int& x: a) cin >> x, x &= 1;
    int b[2] = {-1, -1};
    for (int i = 0; i < 2*n-1; i++) {
      if (b[a[i]] != -1) {
        cout << b[a[i]]+1 << ' ' << i+1 << '\n';
        b[a[i]] = -1;
      }
      else {
        b[a[i]] = i;
      }
    }
  }
}