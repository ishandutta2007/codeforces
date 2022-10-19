#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l2 <= r1 && l1 <= r2) {
      cout << max(l1, l2) << '\n';
      continue;
    }
    cout << l1+l2 << '\n';
  }
}