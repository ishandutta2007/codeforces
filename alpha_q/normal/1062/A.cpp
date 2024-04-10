#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1234;

int n, a[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[n + 1] = 1001;
  for (int i = 0; i <= n + 1; ++i) {
    a[i] -= i;
  }
  int ans = 0;
  for (int i = 0; i <= n + 1;) {
    int j = i;
    while (j <= n + 1 and a[j] == a[i]) ++j;
    ans = max(ans, j - i - 2);
    i = j;
  }
  cout << ans << '\n';
  return 0;
}