// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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
char readc() {
  char ch = getchar();
  while (ch != 'W' && ch != 'B') ch = getchar();
  return ch == 'B';
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 505;
int a[N][N], n, m;

int main() {
  n = read(), m = read();
  rep(i, 1, n) {
    rep(j, 1, m) {
      int t = readc();
      a[i - 1][j - 1] ^= t;
      a[i - 1][j] ^= t;
      a[i][j - 1] ^= t;
      a[i][j] ^= t;
    }
  }
  int one = 0;
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (a[i][j]) one++;
    }
  }
  rep(i, 1, n - 1) {
    rep(j, 1, m - 1) {
      if (a[i][j] && a[i][m] && a[n][j] && a[n][m]) {
        one--;
        goto end;
      }
    }
  }
  end: ;
  print(one, '\n');
  return 0;
}