#include <bits/stdc++.h>

using namespace std;

int k, x, mx = 0;

int main() {
  cin >> k;
  while (k--) {
    cin >> x;
    mx = max(mx, x);
  }
  mx = max(mx, 25);
  cout << mx - 25 << endl;
  return 0;
}