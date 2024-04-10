// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 2000005;
const int mod = 1e9 + 7;

int a[N], fac[N];
int d[N], n;

int main() {
  n = read();
  fac[0] = 1;
  rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % mod;
  rep(i, 1, n) {
    a[i] = read();
    d[1000000 + -(a[i] - 1)]++;
    d[1000000 + (a[i] - 1) + 2]--;
  }
  int ind = 1;
  int ans1 = 0, ans2 = 1;
  for (int i = 1; i <= 2000000; i++) {
    d[i] += d[i - 2];
    if (d[i]) {
      ans1 = (ans1 + 1ll * d[i] * (2 * ind + d[i] - 1) / 2 % mod * (i - 1000000)) % mod;
      ans2 = 1ll * ans2 * fac[d[i]] % mod;
      ind = (ind + d[i]) % mod;
    }
  }
  ans1 = (ans1 + mod) % mod;
  printf("%d %d\n", ans1, ans2);
  return 0;
}