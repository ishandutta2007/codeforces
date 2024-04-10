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

int calc(int n, int P) {
  n = n * 2 + 1;
  int res = 2;
  rep(i, 1, n / 2 - 1) {
    res = (1ll * res * ((1 << i) + 1)) % P;
  }
  return res % P;
}

void solve() {
  int n = read(), P = read();
  int res = 1;
  rep(i, 1, 29) {
    if (n < (1 << i)) break;
    int cur = (1 << i) - 1;
    res = (res + 1ll * (min((1 << (i + 1)) - 1, n) - (1 << i) + 1) * calc(i, P)) % P;
  }
  cout << res % P << endl;
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}