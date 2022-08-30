#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;

int a[maxN], cnt[maxN], nxt[maxN], seq[maxN];
int T, n, e;

int main() {
  for (int i = 2; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) {
      ++cnt[j];
      cnt[j] = min(cnt[j], 2);
    }
  }
  scanf("%d", &T);
  while (T--) {
    long long ans = 0;
    scanf("%d%d", &n, &e);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= e; i++) {
      int len = 0;
      for (int j = i; j <= n; j += e) seq[++len] = cnt[a[j]];
      for (int j = 1; j <= len; j++) {
        nxt[j] = nxt[j - 1];
        if (seq[j]) nxt[j] = j;
        if (!nxt[j]) continue;
        else {
          if (seq[nxt[j]] == 2) continue;
          else {
            int x = nxt[j] - 1;
            if (!nxt[x]) ans += min(nxt[j], j - 1);
            else ans += min(nxt[j], j - 1) - nxt[x];
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}