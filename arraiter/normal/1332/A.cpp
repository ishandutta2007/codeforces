#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  bool flg = 0;
  while (c < 48) flg |= c == '-', c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return flg ? -x : x;
  #undef nc
}

typedef long long ll;

void solve() {
  int a = read(), b = read(), c = read(), d = read();
  int x = read(), y = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read();
  if (x == x1 && x == x2 && (a || b)) {
    puts("No"); return;
  }
  if (y == y1 && y == y2 && (c || d)) {
    return puts("No"), void();
  }
  int tmp = min(a, b);
  a -= tmp, b -= tmp;
  tmp = min(c, d);
  c -= tmp, d -= tmp;
  if (x - a >= x1 && x + b <= x2 && y - c >= y1 && y + d <= y2) {puts("Yes");
  } else puts("No");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}