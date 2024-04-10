#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 7;
const int M = 5200;
const int A = 26;

int c[M][M];

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int udd(int &x, int y) {
  return x = add(x, y);
}

int sub(int x, int y) {
  return add(x, mod - y);
}

int uub(int &x, int y) {
  return x = sub(x, y);
}

int mul(ll x, ll y) {
  return x * y % mod;
}

void pre() {
  for (int i = 0; i < M; ++i)
    c[i][0] = 1;

  for (int i = 1; i < M; ++i)
    for (int j = 1; j < M; ++j)
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
}

int n;
string s;
int d[A][M];
int mem[A][M];
int sum[M];

void read() {
  cin >> n;
  cin >> s;
}

void kill() {
  for (int pos = 0; pos < n; ++pos) {
    int cur = s[pos] - 'a';

    for (int k = 1; k <= pos + 1; ++k) {
      int& bon = d[cur][k];
      if (k == 1) {
        udd(sum[k], sub(1, bon));
        bon = 1;
      } else if (pos > 0 && k > 1) {
        int diff = 0;
        udd(diff, sub(sum[k - 1], d[cur][k - 1]));
        uub(diff, mem[cur][k]);

        udd(sum[k], diff);
        udd(bon, diff);
      }
    }

    for (int x = 0; x <= n; ++x)
      mem[cur][x] = d[cur][x];
  }

  int ans = 0;
  for (int k = 1; k <= n; ++k) {
    udd(ans, mul(sum[k], c[n - 1][k - 1]));
  }

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  pre();
  read();
  kill();
}