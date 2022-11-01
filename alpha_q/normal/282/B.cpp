#include <bits/stdc++.h>

using namespace std;

int n;
long long x, y, sa, sb;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &x, &y);
    if (abs((sa + x) - sb) <= 500) {
      sa += x; putchar('A');
    } else {
      assert(abs(sa - (sb + y)) <= 500);
      sb += y; putchar('G');
    }
  }
  cout << '\n';
  return 0;
}