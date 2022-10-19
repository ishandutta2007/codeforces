#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int n = abs(a-b);
    if (max({a, b, c}) > 2*n) {
      cout << -1 << endl;
    }
    else {
      cout << (c+n-1) % (2*n) + 1 << endl;
    }
  }
}