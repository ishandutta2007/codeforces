#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int t, n, x, y;
char s[N], a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%s", s + 1);
    n = strlen(s + 1), x = y = 0;
    for (int i = 1; i <= n; ++i) {
      if ((s[i] - '0') & 1) a[++x] = s[i];
      else b[++y] = s[i];
    }
    for (int i = 1, j = 1; i <= x or j <= y;) {
      if (i <= x and j <= y) {
        if (a[i] < b[j]) putchar(a[i++]);
        else putchar(b[j++]);
      } else if (i <= x) {
        putchar(a[i++]);
      } else {
        putchar(b[j++]);
      }
    }
    puts("");
  }
  return 0;
}