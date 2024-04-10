#include <bits/stdc++.h>

using namespace std;

const int N = 200010; 

bitset <N> vis;
int n, a[N], mn[N], sec[N], cnt[N];

int main() {
  memset(sec, -1, sizeof sec);
  cin >> n;
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    g = __gcd(g, a[i]);
  }
  for (int i = 2; i <= g; ++i) {
    if (g % i) continue;
    while (g % i == 0) g /= i;
    mn[i] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    for (int p = 2; p * p <= x; ++p) {
      if (x % p) continue;
      int e = 0; vis[p] = 1, ++cnt[p];
      while (x % p == 0) ++e, x /= p;
      if (mn[p] == -1) mn[p] = e;
      else {
        if (e < mn[p]) sec[p] = mn[p], mn[p] = e;
        else if (sec[p] == -1) sec[p] = e;
        else sec[p] = min(sec[p], e);
      }
    }
    if (x > 1) {
      int p = x, e = 1; vis[p] = 1, ++cnt[p];
      if (mn[p] == -1) mn[p] = e;
      else if (sec[p] == -1) sec[p] = e;
      else {
        if (e < mn[p]) sec[p] = mn[p], mn[p] = e;
        else sec[p] = min(sec[p], e);
      } 
    }
  }
  long long ans = 1;
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) continue;
    if (cnt[i] < n - 1) continue;
    int p = i, e = sec[i];
    // cout << p << " " << e << endl;
    while (e--) ans *= p;
  }
  cout << ans << '\n';
  return 0;
}