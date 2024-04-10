#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t, n, m;
bitset <N> a, b;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    a.reset(), b.reset();
    while (n--) {
      int x;
      cin >> x;
      a[x] = 1;
    }
    while (m--) {
      int x;
      cin >> x;
      b[x] = 1;
    }
    cout << (a & b).count() << '\n';
  }
  return 0;
}