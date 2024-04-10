#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e16 + 5;

char s[N];
int t, n, m, p;
ll ud[N], lr[N];
ll pmn[N], pmx[N];
ll smn[N], smx[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%s", s + 1);
    p = strlen(s + 1), n = m = 0;
    ud[++n] = 0, lr[++m] = 0;
    for (int i = 1; i <= p; ++i) {
      if (s[i] == 'W') ud[++n] = +1;
      else if (s[i] == 'S') ud[++n] = -1;
      else if (s[i] == 'A') lr[++m] = -1;
      else lr[++m] = +1;
    }

    ll umn = INF, umx = -INF;
    ll lmn = INF, lmx = -INF;
    for (int i = 1; i <= n; ++i) {
      ud[i] += ud[i - 1];
      umn = min(umn, ud[i]);
      umx = max(umx, ud[i]);
    }
    for (int i = 1; i <= m; ++i) {
      lr[i] += lr[i - 1];
      lmn = min(lmn, lr[i]);
      lmx = max(lmx, lr[i]);
    }
    ll ans = (umx - umn + 1) * (lmx - lmn + 1);

    pmn[0] = INF, pmx[0] = -INF;
    for (int i = 1; i <= n; ++i) {
      pmn[i] = min(ud[i], pmn[i - 1]);
      pmx[i] = max(ud[i], pmx[i - 1]);
    }
    smn[n + 1] = INF, smx[n + 1] = -INF;
    for (int i = n; i >= 1; --i) {
      smn[i] = min(ud[i], smn[i + 1]);
      smx[i] = max(ud[i], smx[i + 1]);
    }

    { // W
      // ans = min(ans, (max(1LL, umx + 1) - min(1LL, umn + 1) + 1) * (lmx - lmn + 1));
      for (int i = 1; i <= n; ++i) {
        ans = min(ans, (max(ud[i] + 1, max(pmx[i], smx[i + 1] + 1)) - min(ud[i] + 1, min(pmn[i], smn[i + 1] + 1)) + 1) * (lmx - lmn + 1));
      }
    }

    { // S
      // ans = min(ans, (max(-1LL, umx - 1) - min(-1LL, umn - 1) + 1) * (lmx - lmn + 1));
      for (int i = 1; i <= n; ++i) {
        ans = min(ans, (max(ud[i] - 1, max(pmx[i], smx[i + 1] - 1)) - min(ud[i] - 1, min(pmn[i], smn[i + 1] - 1)) + 1) * (lmx - lmn + 1));
      }
    }

    pmn[0] = INF, pmx[0] = -INF;
    for (int i = 1; i <= m; ++i) {
      pmn[i] = min(lr[i], pmn[i - 1]);
      pmx[i] = max(lr[i], pmx[i - 1]);
    }
    smn[m + 1] = INF, smx[m + 1] = -INF;
    for (int i = m; i >= 1; --i) {
      smn[i] = min(lr[i], smn[i + 1]);
      smx[i] = max(lr[i], smx[i + 1]);
    }

    { // D
      // ans = min(ans, (max(1LL, lmx + 1) - min(1LL, lmn + 1) + 1) * (umx - umn + 1));
      for (int i = 1; i <= m; ++i) {
        ans = min(ans, (max(lr[i] + 1, max(pmx[i], smx[i + 1] + 1)) - min(lr[i] + 1, min(pmn[i], smn[i + 1] + 1)) + 1) * (umx - umn + 1));
      }
    }

    { // A
      // ans = min(ans, (max(-1LL, lmx - 1) - min(-1LL, lmn - 1) + 1) * (umx - umn + 1));
      for (int i = 1; i <= m; ++i) {
        ans = min(ans, (max(lr[i] - 1, max(pmx[i], smx[i + 1] - 1)) - min(lr[i] - 1, min(pmn[i], smn[i + 1] - 1)) + 1) * (umx - umn + 1));
      }
    }

    printf("%lld\n", ans);
  }
  return 0;
}