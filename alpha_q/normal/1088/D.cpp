#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int LG = 30;

int tot, aa, bb;

int ans (int c, int d) {
  int x = aa ^ c, y = bb ^ d;
  if (x < y) return -1;
  if (x > y) return +1;
  return 0;
}

int ask (int c, int d) {
  ++tot; if (tot > 62) assert(false);
  cout << "? " << c << " " << d << endl;
  int res;
  // res = ans(c, d);
  cin >> res;
  return res;
}

int main() {
  // srand(time(0));
  // aa = rand() * 1LL * rand() % (1 << LG);
  // bb = rand() * 1LL * rand() % (1 << LG);
  // cout << aa << " " << bb << endl;

  int a = 0, b = 0, cmp = -69;
  for (int i = LG - 1; i >= 0; --i) {
    if (cmp == -69) {
      cmp = ask(a, b);
    }
    if (cmp < 0) {
      // 00, 01, 11
      int tmp = ask(a | 1 << i, b | 1 << i);
      if (tmp < 0) {
        // same bits
        int cur = ask(a, b | 1 << i);
        if (cur >= 0) {
          a |= 1 << i;
          b |= 1 << i;
        }
      } else {
        // 01
        b |= 1 << i;
        cmp = -69;
      }
    } else {
      // 00, 10, 11
      int tmp = ask(a | 1 << i, b | 1 << i);
      if (tmp >= 0) {
        // same bits
        int cur = ask(a, b | 1 << i);
        if (cur >= 0) {
          a |= 1 << i;
          b |= 1 << i;
        }
      } else {
        // 10
        a |= 1 << i;
        cmp = -69;
      }
    }
  }
  cout << "! " << a << " " << b << endl;
  // assert(a == aa and b == bb);
  return 0;
}