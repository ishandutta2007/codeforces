#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int n, m, q; 
char g[N][N];
ll p[N][N], rev[N][N];

// 0110100110010110 1001011001101001

int at_aux (ll x, ll y) {
  if (y == 1) return 0; y >>= 1; 
  return x <= y ? at_aux(x, y) : at_aux(x - y, y) ^ 1;
}

int at (ll x) {
  ll y = 1;
  while (y < x) y <<= 1;
  return at_aux(x, y);
}

int zeros_aux (ll x, ll y) {
  if (y == 1) return 1; y >>= 1; 
  return x <= y ? zeros_aux(x, y) : (y == 1 ? 1 : y >> 1) + x - y - zeros_aux(x - y, y);
}

ll zeros (ll x) {
  ll y = 1;
  while (y < x) y <<= 1;
  return zeros_aux(x, y);
}

ll get (int r, int c) {
  if (!r or !c) return 0;
  ll ret = 0, x = r / n, y = c / m;
  if (x and y) {
    ll zero_x = zeros(x), zero_y = zeros(y);
    ll zero = zero_x * zero_y + (x - zero_x) * (y - zero_y);
    ll one = x * y - zero;
    ret += zero * p[n][m] + one * rev[n][m];
  }
  if (y and r % n) {
    int here = at(x + 1);
    ll zero = zeros(y);
    if (here) zero = y - zero;
    ll one = y - zero;
    ret += zero * p[r % n][m];
    ret += one * rev[r % n][m];
  } 
  if (x and c % m) {
    int here = at(y + 1);
    ll zero = zeros(x);
    if (here) zero = x - zero;
    ll one = x - zero;
    ret += zero * p[n][c % m];
    ret += one * rev[n][c % m];
  }
  if (r % n and c % m) {
    int here = at(x + 1) ^ at(y + 1);
    if (here) ret += rev[r % n][c % m];
    else ret += p[r % n][c % m];
  }
  return ret;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
    for (int j = 1; j <= m; ++j) {
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (g[i][j] - '0');
      rev[i][j] = rev[i - 1][j] + rev[i][j - 1] - rev[i - 1][j - 1] + 1 - (g[i][j] - '0');
    }
  }
  // cout << get(1, 3) << endl;
  while (q--) {
    int x_1, y_1, x_2, y_2;
    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
    // cout << get(x_2, y_2) << endl;
    // cout << get(x_1 - 1, y_2) << endl;
    // cout << get(x_2, y_1 - 1) << endl;
    // cout << get(x_1 - 1, y_1 - 1) << endl;
    printf("%lld\n", get(x_2, y_2) - get(x_1 - 1, y_2) - get(x_2, y_1 - 1) + get(x_1 - 1, y_1 - 1));
  }
  return 0;
}