#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r, a;
    cin >> l >> r >> a;
    int x = l/a;
    int y = (r+1)/a;
    if (x < y) {
      cout << (y-1)+ a-1 << '\n';
      continue;
    }
    cout << r/a + r%a << '\n';
  }
}