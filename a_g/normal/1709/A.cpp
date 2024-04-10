#include <bits/stdc++.h>
using namespace std;

int a[4];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x >> a[1] >> a[2] >> a[3];
    bool ok = 0;
    if (a[x] != 0 && a[a[x]] != 0) ok = 1;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}