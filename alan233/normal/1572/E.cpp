// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int N = 205;

template<typename T> int sign(T x) {
  if (x < 0) return -1;
  if (x == 0) return 0;
  return 1;
}

struct Vec {
  ll x, y;
  Vec (ll _x = 0, ll _y = 0) {
    x = _x, y = _y;
  }
} a[N];
Vec operator + (Vec x, Vec y) {
  return Vec(x.x + y.x, x.y + y.y);
}
Vec operator - (Vec x, Vec y) {
  return Vec(x.x - y.x, x.y - y.y);
}
ll Cross(Vec x, Vec y) {
  return x.x * y.y - x.y * y.x;
}

int n, m;

pii dp[N][N];
bool check(ll area) {
  for (int len = 3; len <= n; len++) {
    for (int i = 1, j = len; j <= n; i++, j++) {
      dp[i][j] = {-1e9, 0};
      for (int k = i + 1; k <= j - 1; k++) {
        pii f = {dp[i][k].fir + dp[k][j].fir, dp[i][k].sec + dp[k][j].sec + Cross(a[k] - a[i], a[j] - a[i])};
        if (f.sec >= area) f.fir++, f.sec = 0;
        ckmax(dp[i][j], f);
      } 
    }
  }
  return dp[1][n].fir >= m;
}

int main() {
  n = read(), m = read() + 1;
  rep(i, 1, n) a[i].x = read(), a[i].y = read();
  ll l = 0, r = 1e18;
  while (l < r) {
    ll mid = l + r + 1 >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  print(l, '\n');
  return 0;
}