// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int(x.size()))
#define fir first
#define sec second

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}

const int N = 500005;

char tmp[N];
int x[N], y[N], X, Y, n;

void cross(int &l1, int &r1, int l2, int r2) {
  ckmax(l1, l2), ckmin(r1, r2);
}
bool check(int len) {
  int xi = 0, xa = 1e9, yi = 0, ya = 1e9, xyi = -1e9, xya = 1e9;
  for (int i = 1; i <= n; i++) {
    cross(xi, xa, x[i] - len, x[i] + len);
    cross(yi, ya, y[i] - len, y[i] + len);
    cross(xyi, xya, x[i] - y[i] - len, x[i] - y[i] + len);
  }
  int xl = xi, xr = xa;
  cross(xl, xr, yi + xyi, ya + xya);
  if (xl > xr) return false;
  X = xr;
  int yl = yi, yr = ya;
  cross(yl, yr, X - xya, X - xyi);
  if (yl > yr) return false;
  Y = yr;
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", tmp + 1);
    for (int j = 1; tmp[j] != '\0'; j++) {
      if (tmp[j] == 'B') x[i]++;
      else y[i]++;
    }
  }  
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  check(l);
  printf("%d\n", l);
  rep(i, 1, X) putchar('B');
  rep(i, 1, Y) putchar('N');
  return 0;  
}