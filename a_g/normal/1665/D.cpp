#include <bits/stdc++.h>
using namespace std;

const bool testing = 0;
const int tx = 5;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  if (testing) {
    return __gcd(tx+a, tx+b);
  }
  int v;
  cin >> v;
  return v;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int p = 1;
    for (int i = 0; i < 30; i++) {
      if (__builtin_ctz(query(p, p+(1<<(i+1)))) <= i) {
        p += 1<<i;
      }
    }
    cout << "! " << (1<<30)-p << endl;
  }
}