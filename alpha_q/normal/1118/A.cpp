#include <bits/stdc++.h>

using namespace std;

int q; long long n, a, b;

int main() {
  cin >> q;
  while (q--) {
    cin >> n >> a >> b;
    if (a + a <= b) {
      long long ret = n * a;
      cout << ret << '\n';
    } else {
      long long ret = b * (n / 2);
      if (n % 2 == 1) ret += a;
      cout << ret << '\n';
    }
  }
  return 0;
}