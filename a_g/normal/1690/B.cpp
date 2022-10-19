#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    int d = 0;
    for (int i = 0; i < n; i++) {
      d = max(d, a[i]-b[i]);
    }
    for (int& x: a) x = max(0, x-d);
    bool good = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) good = 0;
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}