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

int cnt[2][N], pre[N];
int n, a[N], ans = 0;

int main() {
  memset(cnt, 0x3f, sizeof(cnt));
  n = read();
  rep(i, 1, n) a[i] = read();
  rep(bit, 0, 20) {
    rep(i, 1, n) pre[i] = pre[i - 1] ^ (a[i] >> bit << bit);
    rep(i, 1, n) {
      if (!(a[i] >> bit & 1)) continue;
      int j = i;
      while (j + 1 <= n && (a[j + 1] >> bit & 1)) ++j;
      rep(k, i, j) {
        ckmin(cnt[(k - 1) & 1][pre[k - 1]], k - 1);
        ckmax(ans, k - cnt[k & 1][pre[k]]);
      }
      rep(k, i, j) {
        cnt[(k - 1) & 1][pre[k - 1]] = 1e9;
      }
      i = j;
    }
  }
  print(ans, '\n');
  return 0;
}