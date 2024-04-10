#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int n, pwr, ans = 1;
vector <int> v;

int main() {
  cin >> n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      int e = 0;
      while (n % i == 0) {
        n /= i, ++e;
      }
      ans *= i;
      pwr = max(pwr, e);
      v.push_back(e);
    }
  }
  if (n > 1) {
    ans *= n;
    pwr = max(pwr, 1);
    v.push_back(1);
  }
  int moves = 0;
  while ((1 << moves) < pwr) ++moves;
  for (int x : v) if (x != (1 << moves)) {
    ++moves; break;
  }
  cout << ans << " " << moves << '\n';
  return 0;
}