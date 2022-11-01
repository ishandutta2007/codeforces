#include <bits/stdc++.h>

using namespace std;

int main() {
  int x; cin >> x;
  x %= 9; if (!x) x = 9;
  cout << x << '\n';
  return 0;
}