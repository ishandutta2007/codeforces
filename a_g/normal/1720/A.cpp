#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (1LL*a*d == 1LL*b*c) {
      cout << "0\n";
      continue;
    }
    if (a == 0 || c == 0) {
      cout << "1\n";
      continue;
    }
    if ((1LL*a*d)%(1LL*b*c) == 0 || (1LL*b*c)%(1LL*a*d) == 0) {
      cout << "1\n";
      continue;
    }
    cout << "2\n";
  }
}