#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 500500;

ll n, a[M], k;

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
}

ll funup(ll x) {
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += max<ll>(0, a[i] - x);
  return ans;
}

ll fundown(ll x) {
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += max<ll>(0, x - a[i]);
  return ans;
}

ll binup(ll l, ll r) {
  ll m;
  while (l < r) {
    m = (l + r) / 2;
    if (funup(m) > k)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

ll bindown(ll l, ll r) {
  ll m;
  while (l < r) {
    m = (l + r) / 2;
    if (fundown(m + 1) > k)
      r = m;
    else
      l = m + 1;
  }
  return l;
}

void kill() {
  ll sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i];

  ll lup = (sum + n - 1) / n;
  ll rdown = sum / n;

  ll mx = binup(lup, 1e9);
  ll mn = bindown(0, rdown);

  cout << mx - mn << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}