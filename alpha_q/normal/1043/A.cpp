#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int main() {
  int n, sum = 0, k = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; k = max(k, x); sum += x;
  }
  k = max(k, (sum + sum + n) / n);
  cout << k << '\n';
  return 0;
}