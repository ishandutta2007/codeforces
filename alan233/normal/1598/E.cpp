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

ll can[1005][1005];
int a[1005][1005];
int n, m, q;
ll ans;

int main() {
  n = read(), m = read(), q = read();
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      can[i][j] = can[i + 1][j + 1] + 1 + (i < n) + (j < m) + (i < n && j < m);
      // printf("can[%d][%d] = %lld\n", i, j, can[i][j]);
      ans += can[i][j];
    }
  }
  while (q--) {
    int x = read(), y = read();
    if (a[x][y]) { // free (x, y)
      a[x][y] = 0;
      int x0 = 0, y0 = 0;
      {
        int zx = x, zy = y;
        int dir = 0;
        while (zx >= 1 && zy >= 1 && !a[zx][zy]) {
          x0++;
          if (dir) zx--;
          else zy--;
          dir ^= 1;
        }
      }
      {
        int zx = x, zy = y;
        int dir = 1;
        while (zx <= n && zy <= m && !a[zx][zy]) {
          y0++;
          if (dir) zx++;
          else zy++;
          dir ^= 1;
        }
      }
      ans += 1ll * x0 * y0;
      x0 = 0, y0 = 0;
      {
        int zx = x, zy = y;
        int dir = 1;
        while (zx >= 1 && zy >= 1 && !a[zx][zy]) {
          x0++;
          if (dir) zx--;
          else zy--;
          dir ^= 1;
        }
      }
      {
        int zx = x, zy = y;
        int dir = 0;
        while (zx <= n && zy <= m && !a[zx][zy]) {
          y0++;
          if (dir) zx++;
          else zy++;
          dir ^= 1;
        }
      }
      ans += 1ll * x0 * y0 - 1;
    } else { // locked (x, y)
      int x0 = 0, y0 = 0;
      {
        int zx = x, zy = y;
        int dir = 0;
        while (zx >= 1 && zy >= 1 && !a[zx][zy]) {
          x0++;
          if (dir) zx--;
          else zy--;
          dir ^= 1;
        }
      }
      {
        int zx = x, zy = y;
        int dir = 1;
        while (zx <= n && zy <= m && !a[zx][zy]) {
          y0++;
          if (dir) zx++;
          else zy++;
          dir ^= 1;
        }
      }
      ans -= 1ll * x0 * y0;
      x0 = 0, y0 = 0;
      {
        int zx = x, zy = y;
        int dir = 1;
        while (zx >= 1 && zy >= 1 && !a[zx][zy]) {
          x0++;
          if (dir) zx--;
          else zy--;
          dir ^= 1;
        }
      }
      {
        int zx = x, zy = y;
        int dir = 0;
        while (zx <= n && zy <= m && !a[zx][zy]) {
          y0++;
          if (dir) zx++;
          else zy++;
          dir ^= 1;
        }
      }
      ans -= 1ll * x0 * y0 - 1;
      a[x][y] = 1;
    }
    print(ans, '\n');
  }
}