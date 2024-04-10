#include <bits/stdc++.h>

using namespace std;

int t, pf[6969], zr[6969]; char s[6969];

int main() {
  cin >> t;
  while (t--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int od = 0, ev = 0;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '1') ++od;
      else ++ev;
      pf[i] = pf[i - 1] + (s[i] == '1');
      zr[i] = zr[i - 1] + (s[i] == '0');
    }
    int ans = min(od, ev);
    for (int i = 1; i < n; ++i) {
      int cur = pf[i] + zr[n] - zr[i];
      ans = min(ans, cur);
      cur = zr[i] + pf[n] - pf[i];
      ans = min(ans, cur);
    }
    printf("%d\n", ans);
  }
  return 0;
}