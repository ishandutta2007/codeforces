#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int M = 200200;

ll n, m;
ll A, B;
ll g, len;

ll gcd(ll a, ll b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll g = gcd(b % a, a, x1, y1);
    x = y1 - x1 * (b / a);
    y = x1;
    assert(a * x + b * y == g);
    return g;
}

ll Find(ll x, ll y) {
  if ((x - y) % g != 0)
    return -1;

  ll d = (x - y) / g;
  ll mm = 2 * m / g;
  ll nn = 2 * n / g;
  ll a = -d * A;
  ll b = d * B;

  assert(x + a * 2 * n == y + b * 2 * m);

  if (x + a * 2 * n < 0) {
    ll cur = x + 2 * a * n;
    ll need = (-cur + mm * 2 * n - 1) / (mm * 2 * n);
    a += need * mm;
    b += need * nn;
  }

  ll cur = x + 2 * a * n;
  ll need = cur / (mm * 2 * n);
  a -= need * mm;
  b -= need * nn;

  assert(x + a * 2 * n == y + b * 2 * m);

  return x + a * 2 * n;
}

int k;
int x[M], y[M];

void read() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
  }
  g = gcd(2 * n, 2 * m, A, B);
  len = n * m / (g / 2);
  //cout << "g = " << g << " A = " << A << " B = " << B << endl;
}

ll mmin(ll x, ll y) {
  if (y == -1)
    return x;
  return min(x, y);
}

ll solve(ll x, ll y) {
  ll ans = 1e18;

  ans = mmin(ans, Find(x, y));
  ans = mmin(ans, Find(2 * n - x, y));
  ans = mmin(ans, Find(x, 2 * m - y));
  ans = mmin(ans, Find(2 * n - x, 2 * m - y));
  if (ans >= len)
    ans = -1;
  return ans;
}

void kill() {
  for (int i = 0; i < k; ++i) {
    cout << solve(x[i], y[i]) << "\n";
  }
}

signed main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}