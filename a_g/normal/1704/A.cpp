#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    if (m == n) {
      cout << (a == b ? "YES" : "NO") << '\n';
      continue;
    }
    bool ok = 1;
    for (int i = 0; i < m-1; i++) {
      if (b[m-1-i] != a[n-1-i]) ok = 0;
    }
    bool found = 0;
    for (int i = 0; i < n-m+1; i++) {
      if (a[i] == b[0]) found = 1;
    }
    if (!found) ok = 0;
    cout << (ok ? "YES" : "NO") << '\n';;
  }
}