// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define int long long
#define SZ(x) ((int)(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

int k, t;

int sol(vector<vector<int>> a, vector<pii> op) {
  int n = SZ(a);
  if (n == 1) return a[0][0] > 0;
  for (auto &[x, y]: op) {
    x &= n - 1;
    y &= n - 1;
  }
  vector<vector<int>> b(n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto [x, y]: op) {
        b[i][j] ^= a[(i - x + n) % n][(j - y + n) % n];
      }
    }
  }
  vector<vector<int>> go[2][2];
  for (auto i: {0, 1}) {
    for (auto j: {0, 1}) {
      go[i][j].resize(n / 2);
      for (int k = 0; k < n / 2; k++)
        go[i][j][k].resize(n / 2);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      go[i & 1][j & 1][i / 2][j / 2] = b[i][j];
    }
  }
  return sol(go[0][0], op) + sol(go[0][1], op) + sol(go[1][0], op) + sol(go[1][1], op);
}

signed main() {
  k = read();
  vector<vector<int>> a(1 << k, vector<int> (1 << k));
  for (int i = 0; i < 1 << k; i++)
    for (int j = 0; j < 1 << k; j++)
      a[i][j] = read();
  t = read();
  vector<pii> op;
  for (int i = 0; i < t; i++) {
    int x = read() - 1, y = read() - 1;
    op.pb({x, y});
  }
  cout << sol(a, op) << '\n';
  return 0;
}