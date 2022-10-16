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

const int N = 200005;
const int mod = 1e9 + 7;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}

int a[N], cnt[4], ccnt[4], n;
int ans = 1;

int main() {
  n = read();
  rep(i, 1, n) {
    a[i] = read();
    ans = 2 * ans % mod;
  }
  ans = (ans + mod - 1) % mod;
  for (int bit = 1; bit <= 30; bit++) {
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] & 1) continue;
      ans = (ans + mod - cnt[(2 - a[i] % 4 + 1048576) % 4]) % mod;
      memcpy(ccnt, cnt, sizeof(cnt));
      for (int j = 0; j < 4; j++) {
        add(cnt[(j + a[i]) % 4], ccnt[j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 0) a[i] /= 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}