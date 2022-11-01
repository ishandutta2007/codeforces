#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

bool good[N];
int t, n, a[N], bad[N], pf[N], sf[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    ll od = 0, ev = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (i & 1) od += a[i];
      else ev += a[i];
    }
    a[0] = a[n + 1] = pf[0] = sf[n + 1] = 0;
    for (int i = 1; i <= n; ++i) {
      bad[i] = (a[i - 1] + a[i + 1] < a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      pf[i] = pf[i - 1] + bad[i];
    }
    for (int i = n; i >= 1; --i) {
      sf[i] = sf[i + 1] + bad[i];
    }
    if (od == ev and pf[n] == 0) {
      puts("YES");
      continue;
    }
    bool yes = 0;
    for (int i = 1; i < n; ++i) {
      if (i > 2 and pf[i - 2]) continue;
      if (i + 3 <= n and sf[i + 3]) continue;
      if (i & 1) {
        ll new_od = od - a[i] + a[i + 1];
        ll new_ev = ev - a[i + 1] + a[i];
        if (new_od != new_ev) continue;
      } else {
        ll new_ev = ev - a[i] + a[i + 1];
        ll new_od = od - a[i + 1] + a[i];
        if (new_od != new_ev) continue;
      }
      swap(a[i], a[i + 1]);
      bool ok = 1;
      for (int j = max(1, i - 1); j <= min(n, i + 2); ++j) {
        if (a[j - 1] + a[j + 1] < a[j]) {
          ok = 0;
          break;
        }
      }
      swap(a[i], a[i + 1]);
      if (ok) {
        yes = 1;
        break;
      }
    }
    puts(yes ? "YES" : "NO");
  }
  return 0;
}