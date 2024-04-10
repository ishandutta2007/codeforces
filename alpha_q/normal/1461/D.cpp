#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

int t, n, q;
set <ll> good;
ll a[N], pf[N];

void fuck (int l = 1, int r = n) {
  if (l > r) return;
  good.emplace(pf[r] - pf[l - 1]);
  ll piv = a[l] + a[r] >> 1;
  int mid = upper_bound(a + l, a + r + 1, piv) - a;
  if (mid > r) return;
  fuck(l, mid - 1), fuck(mid, r);
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      pf[i] = pf[i - 1] + a[i];
    }
    good.clear(); fuck();
    while (q--) {
      ll x; 
      scanf("%lld", &x);
      puts(good.count(x) ? "Yes" : "No");
    }
  }
  return 0;
}