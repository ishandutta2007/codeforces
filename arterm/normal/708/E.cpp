#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int M = 1600;
const int N = 100100;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0)
    x += mod;
  return x;
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int f[N];
int r[N];

void pre() {
  r[1] = 1;
  for (int i = 2; i < N; ++i) {
    int bon = sub(0, mod / i);
    bon = mul(bon, r[mod % i]);
    assert(mul(bon, i) == 1);

    r[i] = bon;
  }

  r[0] = 1;
  f[0] = 1;

  for (int i = 1; i < N; ++i) {
    f[i] = mul(i, f[i - 1]);
    r[i] = mul(r[i], r[i - 1]);
  }
}

int bin(int x, int a) {
  int y = 1;
  while (a) {
    if (a & 1)
      y = mul(x, y);
    x = mul(x, x);
    a >>= 1;
  }
  return y;
}

int inv(int x) {
  assert(x != 0);
  return bin(x, mod - 2);
}

int binom(int n, int k) {
  if (n < 0 || k < 0 || n < k)
    return 0;

  int ans = f[n];
  ans = mul(ans, r[k]);
  ans = mul(ans, r[n - k]);

  return ans;
}

int n, m, x, k;
int p[M], s[M][M], q[M];
int sp[M];
int P[M], A[M], B[M];

void read() {
  cin >> n >> m;

  int a, b;
  cin >> a >> b;
  x = mul(a, inv(b));

  cin >> k;
}

void kill() {
  for (int i = 0; i <= m && i <= k; ++i) {
    int bon = 1;
    bon = mul(bon, bin(x, i));
    bon = mul(bon, bin(sub(1, x), k - i));
    bon = mul(bon, binom(k, i));
    p[i] = bon;
  }

  sp[0] = p[0];
  for (int i = 1; i <= m; ++i)
    sp[i] = add(sp[i - 1], p[i]);

  q[0] = 0;
  for (int i = 1; i <= m; ++i) {
    int bon = q[i - 1];
    bon = add(bon, mul(p[m - i], sp[i - 1]));
    q[i] = bon;
  }
    

  s[0][m] = 1;

  for (int i = 1; i <= n; ++i) {

    for (int r = 1; r <= m; ++r) {
      int bon = P[r - 1];
      bon = add(bon, mul(s[i - 1][r], p[r]));
      P[r] = bon;
    }

    int A = 0, B = 0;

    for (int r = 1; r <= m; ++r) {
      A = add(A, mul(p[m - r], P[r - 1]));
      B = add(B, mul(mul(p[m - r], s[i - 1][m - r]), sp[r - 1]));

      int bon = 0;

      bon = add(bon, mul(s[i - 1][m], q[r]));
      bon = sub(bon, A);
      bon = sub(bon, B);

      s[i][r] = bon;
    }
  }

  int ans = s[n][m];
  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  pre();
  read();
  kill();
}