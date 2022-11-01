#include <bits/stdc++.h>

using namespace std;

const int A = 26;
const int N = 2000010;

char s[N], a[N];
int t, n, pal[N], z[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    int at = -1;
    while (at < n - 1 and s[at + 1] == s[n - 1 - at - 1]) ++at;
    if (at == n - 1) {
      puts(s);
      continue;
    }
    for (int i = 0; i <= n + n + 2; ++i) {
      pal[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      a[i + i + 1] = '#', a[i + i + 2] = s[i];
    }
    a[n + n + 1] = '#', a[0] = '@', a[n + n + 2] = '&';
    int c = 0, r = 0;
    for (int i = 1; i <= n + n + 1; ++i) {
      int mir = c + c - i;
      if (r > i) pal[i] = min(r - i, pal[mir]);
      while (a[i + 1 + pal[i]] == a[i - 1 - pal[i]]) ++pal[i];
      if (i + pal[i] > r) c = i, r = i + pal[i];
    }
    int ans = 0, x, y;
    for (int i = 2; i <= n + n; ++i) {
      int rad = pal[i], lt, rt;
      if (i & 1) {
        if (!rad) continue;
        lt = (i - rad + 1) / 2 - 1, rt = (i + rad - 1) / 2 - 1;
      } else {
        int pos = i / 2 - 1;
        lt = pos - rad / 2, rt = pos + rad / 2;
      }
      if (lt < n - 1 - rt) {
        if (at >= lt - 1) {
          int len = lt + rt + 1;
          if (len > ans) {
            ans = len, x = rt, y = n - lt;
          }
        }
      } else {
        if (n - 1 - at <= rt + 1) {
          int len = n - lt + n - 1 - rt;
          if (len > ans) {
            ans = len, x = n - 1 - rt - 1, y = lt;
          }
        }
      }
    }
    for (int i = 0; i <= x; ++i) putchar(s[i]);
    for (int i = y; i < n; ++i) putchar(s[i]); puts("");
  }
  return 0;
}