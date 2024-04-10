#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define x first
#define y second

const int M = 200100;
const int N = 2020;
const int A = 25;

const int mod = 1e9 + 7;

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

int bin(int x, int to) {
  int y = 1;
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

int f[M], rf[M];

void pre() {
  f[0] = 1;
  for (int i = 1; i < M; ++i)
    f[i] = mul(i, f[i - 1]);

  for (int i = 0; i < M; ++i)
    rf[i] = inv(f[i]);
}

int ways(int n, int m) {
  if (n < 0 || m < 0)
    return 0;

  int ans = f[n + m];
  ans = mul(ans, rf[n]);
  ans = mul(ans, rf[m]);
  return ans;
}

int n, m, k, s;
int d[N][A];
pair<int, int> p[N];

int cnt(int i, int j) {
  return ways(p[j].x - p[i].x, p[j].y - p[i].y);
}

void read() {
  cin >> n >> m >> k >> s;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    p[i + 1] = make_pair(x, y);
  }
  sort(p + 1, p + (k + 1));
  p[0] = make_pair(0, 0);
  p[k + 1] = make_pair(n - 1, m - 1);
}

void kill() {
  d[0][0] = 1;
  for (int i = 1; i <= k + 1; ++i) {
    int b = i <= k ? 1 : 0;

    int prev = 0;
    for (int t = b; t + 1 - b < A; ++t) {
      int cur = cnt(0, i);
      for (int j = 0; j < i; ++j)
        cur = sub(cur, mul(cnt(j, i), d[j][t - b + 1]));
      d[i][t] = sub(cur, prev);
      prev = cur;
    }
  }

  int ans = 0;
  int tot = cnt(0, k + 1);
  for (int i = 0; i < A; ++i) {
    int w = d[k + 1][i];
    //cout << i << " -> " << w << endl;
    ans = add(ans, mul(s, w));
    s = (s + 1) / 2;
    tot = sub(tot, w);
  }
  ans = add(ans, tot);
  ans = mul(ans, inv(cnt(0, k + 1)));
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