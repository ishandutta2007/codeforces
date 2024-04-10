#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char s[N], t[N], p[N];
int n, m, a[N], tmp[N];

int main() {
  scanf("%d %s %s", &n, s + 1, t + 1);
  int zero = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == t[i]) continue; 
    p[++m] = s[i], zero += (s[i] == '0');
  }
  if ((m & 1) or (zero != (m >> 1))) {
    puts("-1");
    return 0;
  }
  if (!m) {
    puts("0");
    return 0;
  }
  n = 0;
  for (int i = 1; i <= m;) {
    int j = i, cur = 0;
    while (j <= m and p[j] == p[i]) ++j, ++cur;
    i = j, a[++n] = cur;
  }
  int ans = 0;
  while (n) {
    int mn = a[1];
    for (int i = 1; i <= n; ++i) mn = min(mn, a[i]);
    ans += mn, m = 0;
    int last = -1;
    for (int i = 1; i <= n; ++i) {
      a[i] -= mn;
      if (a[i] == 0) continue;
      if (last == -1 or (i & 1) != last) {
        tmp[++m] = a[i], last = (i & 1);
      } else {
        tmp[m] += a[i];
      }
    }
    for (int i = 1; i <= m; ++i) a[i] = tmp[i];
    n = m;
  }
  cout << ans << '\n';
  return 0;
}