#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s += a;
    }
    cout << ((s+n)&1 ? "errorgorn" : "maomao90") << '\n';
  }
}