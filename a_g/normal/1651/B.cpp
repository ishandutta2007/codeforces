#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
      a[i] = 3 * a[i-1];
      if (a[i] > 1e9) break;
    }
    if (a[n-1] > 0 && a[n-1] <= 1e9) {
      cout << "YES\n";
      for (long long x: a) {
        cout << x << ' ';
      }
      cout << '\n';
    }
    else {
      cout << "NO\n";
    }
  }
}