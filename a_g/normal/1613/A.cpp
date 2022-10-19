#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    if (p1 > p2) {
      if (p1 - p2 > 6) cout << ">\n";
      else {
        for (int i = 0; i < p1-p2; i++) {
          x1 *= 10;
        }
        if (x1 > x2) cout << ">\n";
        else if (x1 < x2) cout << "<\n";
        else cout << "=\n";
      }
    }
    else if (p1 < p2) {
      if (p2 - p1 > 6) cout << "<\n";
      else {
        for (int i = 0; i < p2-p1; i++) {
          x2 *= 10;
        }
        if (x1 > x2) cout << ">\n";
        else if (x1 < x2) cout << "<\n";
        else cout << "=\n";
      }
    }
    else {
      if (x1 > x2) cout << ">\n";
      else if (x1 < x2) cout << "<\n";
      else cout << "=\n";
    }
  }
}