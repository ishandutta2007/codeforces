#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  int n, l, r;
  cin >> n >> l >> r;

  ll mn = 0;
  ll cur = 1LL << (l - 1);
  for (int i = 0; i < n; i++) {
    mn += cur;
    if (cur != 1) cur /= 2;
  }

  ll mx = 0;
  cur = 1;
  for (int i = 0; i < n; i++) {
    mx += cur;
    if (i < r - 1) {
      cur *= 2;
    }
  }

  cout << mn << " " << mx << '\n';
}