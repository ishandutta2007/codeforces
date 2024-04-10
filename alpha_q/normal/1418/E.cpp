#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int n, m;
ll d[N], p[N];

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", d + i);
  }
  sort(d + 1, d + n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + d[i], p[i] %= MOD;
  }
  while (m--) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    int pos = lower_bound(d + 1, d + n + 1, b) - d;
    ll one = p[pos - 1], two = p[n] - p[pos - 1];
//    cout << one << " " << two << '\n';
    one *= (1 - min(a, n - pos + 2LL) * bigMod(n - pos + 2, -1) % MOD);
    two *= (1 - min(a, n - pos + 1LL) * bigMod(n - pos + 1, -1) % MOD);
    one %= MOD, two %= MOD;
//    cout << one << " " << two << '\n';
    ll ans = one + two;
    ans %= MOD, ans += MOD, ans %= MOD;
    printf("%lld\n", ans);
  }
  return 0;
}