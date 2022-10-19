#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    ll current = q*x-p*y;
    if (p == 0 || p == q) {
      if (current != 0) cout << -1 << endl;
      else cout << 0 << endl;
    }
    else {
      if (current < 0) {
        ll minlosses = (q-p)*(((y-x)-1)/(q-p)+1);
        ll total = minlosses*q/(q-p);
        cout << total - y << endl;
      }
      else {
        ll minwins = p*((x-1)/p+1);
        ll total = minwins*q/p;
        cout << total - y << endl;
      }
    }
  }
}