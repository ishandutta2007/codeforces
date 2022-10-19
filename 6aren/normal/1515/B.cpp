#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    int x;
    cin >> x;
    int foo = sqrt(x);
    bool ok = 0;
    for (int i = foo - 1; i <= foo + 1; i++) {
      if (i * i == x) ok = 1;
    }
    ok &= (x % 4 == 0);
    if (x % 2 == 0) {
      x /= 2;
      int foo = sqrt(x);
      for (int i = foo - 1; i <= foo + 1; i++) {
        if (i * i == x) ok = 1;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}