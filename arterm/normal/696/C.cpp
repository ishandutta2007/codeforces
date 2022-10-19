#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int bin(ll x, ll a) {
  ll y = 1;
  while (a) {
    if (a & 1)
      y = mul(y, x);
    x = mul(x, x);
    a >>= 1;
  }
  return y;
}


void kill() {
  ll pw = 2;
  ll a = mod - 1;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    pw = bin(pw, x);
    a = bin(a, x);
  }

  ll p = add(mul(pw, bin(2, mod - 2)), a);
  p = mul(p, bin(3, mod - 2));
  ll q = mul(pw, bin(2, mod - 2));

  cout << p << "/" << q << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  kill();
}