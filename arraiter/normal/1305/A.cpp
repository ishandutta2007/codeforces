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
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

int n, a[105], b[105];

void solve() {
  n = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) b[i] = read();
  sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
  rep(i,1,n)printf("%d%c",a[i],"\n "[i<n]);
  rep(i,1,n)printf("%d%c",b[i],"\n "[i<n]);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}