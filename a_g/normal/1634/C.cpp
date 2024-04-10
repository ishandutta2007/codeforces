#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (n&1 && k > 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int cur = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        cout << cur << ' ';
        if (cur + 2 <= n*k) cur += 2;
        else cur = 2;
      }
      cout << '\n';
    }
  }
}