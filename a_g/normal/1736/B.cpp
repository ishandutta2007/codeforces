#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    bool ok = 1;
    for (int i = 1; i+1 < n; i++) {
      if (a[i]%__gcd(a[i-1], a[i+1]) != 0) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}