#include <bits/stdc++.h>

using namespace std;

int main() {
  int _n, h = 0, s = 0;
  string a, b;
  cin >> _n;
  while (_n--) {
    cin >> a >> b;
    if (b[0] == 'h') {
      ++h;
    } else {
      ++s;
    }
  }
  int n = 1;
  while ((n * n) / 2 < h) {
    ++n;
  }
  int m = 1;
  while ((m * m + 1) / 2 < s) {
    ++m;
  }
  int nn = 1;
  while ((nn * nn) / 2 < s) {
    ++nn;
  }
  int mm = 1;
  while ((mm * mm + 1) / 2 < h) {
    ++mm;
  }
  cout << min(max(n, m), max(nn, mm)) << endl;
  return 0;
}