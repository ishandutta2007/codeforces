#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int n, a[500];

int main() {
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n + n; ++i) cin >> a[i];
  for (int i = 1; i <= n + n; i += 2) {
    if (a[i] == a[i + 1]) continue;
    int x = a[i], j = i + 1;
    while (a[j] != x) ++j;
    while (j > i + 1) {
      swap(a[j], a[j - 1]);
      --j, ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}