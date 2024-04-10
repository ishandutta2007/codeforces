#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    a %= b;
    if (a) a = b - a;
    cout << a << '\n';
  }
  return 0;
}