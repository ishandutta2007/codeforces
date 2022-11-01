#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, a, b;

int main() {
  cin >> n >> k >> a >> b;
  ll mul = n * k, mn = mul, mx = 0;
  for (ll t = 0; t < n; ++t) {
    ll val, step;
    val = (t * k + a + b) % mul;
    if (val < 0) val += mul;
    step = mul / __gcd(val, mul);
    mn = min(mn, step);
    mx = max(mx, step);
    val = (t * k + a - b) % mul;
    if (val < 0) val += mul;
    step = mul / __gcd(val, mul);
    mn = min(mn, step);
    mx = max(mx, step);
    val = (t * k - a + b) % mul;
    if (val < 0) val += mul;
    step = mul / __gcd(val, mul);
    mn = min(mn, step);
    mx = max(mx, step);
    val = (t * k - a - b) % mul;
    if (val < 0) val += mul;
    step = mul / __gcd(val, mul);
    mn = min(mn, step);
    mx = max(mx, step);
  }
  cout << mn << " " << mx << endl;
  return 0;
}