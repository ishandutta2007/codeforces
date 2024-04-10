#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int c = 0;
    int cur = -1;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a != cur) {
        c++;
        cur = a;
      }
    }
    if (k == 1) {
      if (c > 1) cout << "-1\n";
      else cout << "1\n";
      continue;
    }
    cout << max(1, (c+k-3)/(k-1)) << '\n';
  }
}