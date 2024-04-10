#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

ll m, a[N];
int t, n, b[N]; 

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %lld", &n, &m);
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      tot += a[i];
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", b + i);
    }
    if (tot < m) {
      puts("-1");
      continue;
    }
    vector <ll> one, two;
    for (int i = 1; i <= n; ++i) {
      if (b[i] == 1) one.emplace_back(a[i]);
      else two.emplace_back(a[i]);
    }
    sort(one.begin(), one.end(), greater <ll> ());
    sort(two.begin(), two.end(), greater <ll> ());
    ll cur = 0;
    int ans = 69696969, at = 0, cost = 0;
    while (at < two.size() and cur < m) cur += two[at++], cost += 2;
    if (cur >= m) ans = min(ans, cost);
    for (ll &x : one) {
      ++cost; cur += x;
      while (at and cur - two[at - 1] >= m) cur -= two[--at], cost -= 2;
      if (cur >= m) ans = min(ans, cost);
    }
    printf("%d\n", ans);
  }
  return 0;
}