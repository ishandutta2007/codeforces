#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k%4 == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i < n; i += 2) {
      if (i%4 == 3 || k%2 == 1) {
        cout << i << ' ' << i+1 << '\n';
      }
      else {
        cout << i+1 << ' ' << i << '\n';
      }
    }
  }
}