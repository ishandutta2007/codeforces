#include <bits/stdc++.h>

using namespace std;

char t[123456], s[123456];

int main() {
  scanf("%s", t + 1);
  int n = strlen(t + 1), m = 0;
  for (int i = 1; i <= n; ++i) {
    if (t[i] != 'a') s[++m] = t[i];
  }
  if (m & 1) {
    cout << ":(\n";
    return 0;
  }
  m >>= 1;
  for (int i = 1; i <= m; ++i) {
    if (s[i] != s[m + i]) {
      cout << ":(\n";
      return 0;
    }
  }
  for (int i = n, j = 1; j <= m; --i, ++j) {
    if (t[i] == 'a') {
      cout << ":(\n";
      return 0;
    }
  }
  for (int i = 1; i <= n - m; ++i) putchar(t[i]);
  puts("");
  return 0;
}