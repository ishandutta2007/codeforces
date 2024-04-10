#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 7;
const int M = 200100;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int udd(int &x, int y) {
  return x = add(x, y);
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int bin(ll x, ll to) {
  ll y = 1;
  while (to) {
    if (to & 1)
      y = mul(x, y);
    x = mul(x, x);
    to >>= 1;
  }
  return y;
}

int inv(int x) {
  assert(x != 0);
  return bin(x, mod - 2);
}

int fact[M], ifact[M];

void pre() {
  fact[0] = 1;
  for (int i = 1; i < M; ++i)
    fact[i] = mul(i, fact[i - 1]);
  
  for (int i = 0; i < M; ++i)
    ifact[i] = inv(fact[i]);
}

int binom(int n, int k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  int ans = fact[n];
  ans = mul(ans, ifact[k]);
  ans = mul(ans, ifact[n - k]);
  return ans;
}

int ways(int n, int k) {
  if (k == 0)
    return n == 0;

  return binom(n + k - 1, k - 1);
}

int f, w, H;

void read() {
  cin >> f >> w >> H;
  ++H;
}

int calc(int a, int b, int h) {
  if ((f == 0) != (a == 0))
    return 0;

  if ((w == 0) != (b == 0))
    return 0;

  if (w < 1ll * h * b)
    return 0;

  if (f < a)
    return 0;

  int ans = mul(ways(f - a, a), ways(w - h * b, b));
  return ans;
}

int fun(int h) {
  int ans = 0;
  for (int len = 1; len < M; ++len) {
    int a = len / 2;
    int b = len - a;
    udd(ans, calc(a, b, h));
    udd(ans, calc(b, a, h));
  }
  return ans;
}

void kill() {
  int p = fun(H);
  int q = fun(1);
  int ans = mul(p, inv(q));
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  pre();
  read();
  kill();
}