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
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 1005;

int a[N][N], f[N][N];
int n, m, q;

int find(int i, int x) {
  return f[x][i] == x ? x : f[x][i] = find(i, f[x][i]); 
}
void mer(int i, int x, int y) {
  x = find(i, x), y = find(i, y);
  if (x == y) return ;
  f[x][i] = f[y][i];
}

int main() {
  n = read(), m = read(), q = read();
  rep(i, 1, n) {
    rep(j, 1, m) {
      a[i][j] = read();
      f[i][j] = i;
    }
  }
  rep(j, 1, m) {
    f[n + 1][j] = n + 1;
  }
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (a[i][j] == 2)
        mer(j, i, i + 1);
    }
  }
  while (q--) {
    int x = 1, y = read();
    while (x <= n) {
      if (a[x][y] == 1) {
        a[x][y] = 2;
        mer(y, x, x + 1);
        y++;
      } else if (a[x][y] == 3) {
        a[x][y] = 2;
        mer(y, x, x + 1);
        y--;
      } else {
        x = find(y, x);
      }
    }
    print(y, ' ');
  }
  return 0;
}