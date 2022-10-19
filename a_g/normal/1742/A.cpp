#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = (a+b == c || b+c == a || c+a == b);
    cout << (ok ? "YES" : "NO") << '\n';
  }
}