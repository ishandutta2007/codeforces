#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500010;

int n; ll a[N], sf[N], x, tot;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= (1 + n >> 1); ++i) scanf("%lld", a + i), tot += a[i];
  cin >> x, tot += x * (n >> 1);
  if (tot > 0) {
    cout << n << '\n';
    return 0;
  }
  if (x >= 0) {
    cout << "-1\n";
    return 0;
  }
  for (ll i = (1 + n >> 1); i; --i) sf[i] = sf[i + 1] + a[i];
  ll bound = LLONG_MIN; x = -x;
  for (ll i = 1; i <= (1 + n >> 1); ++i) {
    ll cur = ((n >> 1) + i) * x - sf[i];
    bound = max(bound, cur);
    if (i * x > bound) {
      cout << n - i + 1 << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}