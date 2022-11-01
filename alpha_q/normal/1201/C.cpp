#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e11 + 5;

int n; ll k, a[N];

bool ok (ll x) {
  int lim = n >> 1, smol = 0, big = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < x) ++smol;
    if (a[i] > x) ++big;
  }
  ll cost = 0;
  if (smol > lim) {
    int rem = smol - lim;
    for (int i = n; i >= 1 and rem > 0; --i) {
      if (a[i] < x) {
        cost += x - a[i];
        --rem;
      }
    }
  }
  if (big > lim) {
    int rem = big - lim;
    for (int i = 1; i <= n and rem > 0; ++i) {
      if (a[i] > x) {
        cost += a[i] - x;
        --rem;
      }
    }
  }
  return cost <= k;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  sort(a + 1, a + n + 1);
  ll lo = a[1 + n >> 1], hi = INF;
  while (lo < hi) {
    ll mid = lo + hi + 1 >> 1;
    if (ok(mid)) lo = mid;
    else hi = mid - 1;
  }
  cout << lo << '\n';
  return 0;
}