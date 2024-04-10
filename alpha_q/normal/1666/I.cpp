#include <bits/stdc++.h>

using namespace std;

int t, n, m;

inline int scan (int x, int y) {
  cout << "SCAN " << x << " " << y << endl;
  int rep; cin >> rep; return rep;
}

inline int dig (int x, int y) {
  cout << "DIG " << x << " " << y << endl;
  int rep; cin >> rep; return rep;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    // rows a <= c; cols b <= d
    int one = scan(1, 1) + 4; // a + b + c + d
    int two = scan(1, m) + 2 - 2 * m; // a - b + c - d
    int row_sum = (one + two) / 2; // a + c
    int col_sum = one - row_sum; // b + d
    int three = scan(1, col_sum / 2) + 2; // a - b + c + d
    int b = (one - three) / 2, d = col_sum - b;
    int four = scan(row_sum / 2, 1) + 2; // -a + b + c + d
    int a = (one - four) / 2, c = row_sum - a;
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    if (dig(a, b)) assert(dig(c, d));
    else assert(dig(a, d)), assert(dig(c, b));
  }
  return 0;
}