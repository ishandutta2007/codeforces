#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  li a, b, c;
  cin >> a >> b >> c;

  // x % y = a
  // y % z = b
  // z % x = c

  // x = ab + a
  // y = b
  // z = c

  // x = yn + a
  // y =

  // c mod a

  // ab + c

  li x = a * b;
  while (x < c) {
    x *= b;
  }
  x += a;
  li y = b;
  li z = c;

  cout << x << " " << y << " " << z << "\n";

  assert(x % y == a);
  assert(y % z == b);
  assert(z % x == c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}