#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

bool check(int a, int b, int c) {
  if (a > 0 && b > 0 && c > 0) {
    cout << a << " " << b << " " << c << endl;
    return true;
  }
  return false;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r, m;
    cin >> l >> r >> m;
    bool found = 0;
    for (int a = l; a <= r; a++) {
      int x = m % a;
      if (x <= r - l) {
	int b = r;
	int c = b - x;
	int n = (m - (b - c)) / a;
	assert((m - (b - c)) % a == 0);
	if (n > 0 && check(a, b, c)) {
	  found = 1;
	  break;
	}
      }
      if (x - a >= l - r) {
	int c = r;
	int b = (x - a) + r;
	int n = (m - (b - c)) / a;
	assert((m - (b - c)) % a == 0);
	if (n > 0 && check(a, b, c)) {
	  found = 1;
	  break;
	}
      }
    }
    assert(found);
  }
}