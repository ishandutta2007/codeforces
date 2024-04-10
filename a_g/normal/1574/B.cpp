#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int maximum = a+b+c-3;
    int d = max(a, max(b, c));
    int s = a+b+c;
    int minimum = max(0, 2*d-s-1);
    if (minimum <= m && m <= maximum) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}