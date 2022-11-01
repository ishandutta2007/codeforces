#include <bits/stdc++.h>

using namespace std;

int t, n, a, b;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> n;
    n %= 3;
    if (n == 0) cout << a << '\n';
    else if (n == 1) cout << b << '\n';
    else cout << (a ^ b) << '\n';
  }
  return 0;
}