#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, k;

ll get (ll x) {
  ll ret = 0;
  while (x) ret += x % 10, x /= 10;
  return ret;
}

bool check (ll x) {
  ll tot = 0;
  for (int i = 0; i <= k; ++i) tot += get(x + i);
  return tot == n;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ll ans = LLONG_MAX;
    for (int d = 0; d < 10; ++d) {
      if (d + k < 10) {
        int rhs = n - k * (k + 1) / 2;
        if (rhs % (k + 1)) continue;
        rhs /= k + 1, rhs -= d;
        if (rhs < 0) continue;
        ll dig = rhs / 9, cur = rhs % 9;
        while (dig--) cur = 10 * cur + 9;
        ans = min(ans, 10 * cur + d);
      } else {
        int rhs = n - (9 - d) * (10 - d) / 2 - (d + k - 9) * (d + k - 10) / 2 - (10 - d) * d;
        if (rhs < 0) continue;
        ll a = 10 - d, b = d + k - 9;
        // a f(A) + b f(A + 1) = rhs
        for (ll q = 0, pwr = 1; q < 18; ++q, pwr *= 10) {
          // A = p * 10^q - 1
          int yo = rhs - 9 * a * q - b;
          if (yo >= 0 and yo % (a + b) == 0) {
            ll sum = yo / (a + b);
            ll cur = 1 + sum % 9, dig = sum / 9;
            while (dig--) cur = 10 * cur + 9; --cur;
            ans = min(ans, 10 * ((cur + 1) * pwr - 1) + d);
          }
        }
      }
    }
    if (ans == LLONG_MAX) ans = -1;
    if (ans != -1) assert(check(ans));
    cout << ans << '\n';
  }
  return 0;
}

// 6 f(A) + f(A+1) = 

// 10A + d 

// d + k < 10
// f(A) + d + f(A) + d+1 + ... + f(A) + d+k
// (k+1) (f(A) + d) + k(k+1)/2 = n 

// d + k >= 10
// f(A) + d + f(A) + d+1 + ... + f(A) + 9 + f(A+1) + 0 + f(A+1) + 1 + ... + f(A+1) + d+k-10

// sf(A) + (k-s)f(A+1) = n
// s[f(A) - f(A+1)] + k f(A+1) = n


// (a+b) f(A) = rhs - b
// A = p * 10^q - 1
//