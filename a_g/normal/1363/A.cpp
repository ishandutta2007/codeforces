#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, n;
    cin >> n >> x;
    int odds = 0;
    int evens = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a&1) odds++;
      else evens++;
    }
    bool ok = 1;
    if (odds == 0) ok = 0;
    if (x == n) ok = (odds&1);
    if (odds == n) ok = (x&1);
    cout << (ok ? "YES" : "NO") << '\n';
  }
}