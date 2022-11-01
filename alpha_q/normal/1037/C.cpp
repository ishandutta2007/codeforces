#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1000005;

int n, ans;
char a[N], b[N];

int main() {
  scanf("%d %s %s", &n, a + 1, b + 1);
  for (int i = 1; i < n; ++i) {
    if (a[i] == b[i] and a[i + 1] == b[i + 1]) {
      continue;
    }
    if (a[i + 1] == b[i] and a[i] == b[i + 1]) {
      swap(a[i], a[i + 1]);
      ++ans, ++i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) ++ans;
  }
  cout << ans << '\n';
  return 0;
}