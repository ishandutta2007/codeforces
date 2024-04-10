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

typedef long long ll;

void solve() {
  int n = read(), k = read();
  if (k == 1) {
    puts(n & 1 ? "YES" : "NO");
    return;
  }
  ll sum = 1ll * (k - 1) * (k - 1);
  if (n - sum < 2 * k - 1) {
    puts("NO");
  } else if ((n - sum) % 2 == 0) {
    puts("NO");
  } else {
    puts("YES");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}