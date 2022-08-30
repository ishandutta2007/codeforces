#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;

char c[maxN];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", c + 1);
    n = strlen(c + 1);
    int vis[2] = {0, 0};
    int l = n, r = 0;
    for (int i = 1; i <= n; i++) {
      vis[c[i] - '0'] = 1;
      if (c[i] == '0') {
        l = min(l, i);
        r = max(r, i);
      }
    }
    if (!vis[0]) {
      puts("0");
      continue;
    }
    if (!vis[1]) {
      puts("1");
      continue;
    }
    int ok = 1;
    for (int i = l; i <= r; i++) {
      if (c[i] == '1') {
        ok = 0;
      }
    }
    if (ok) puts("1");
    else puts("2");
  }
  return 0;
}