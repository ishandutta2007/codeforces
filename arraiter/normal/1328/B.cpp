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
#define int long long
typedef long long ll;
char ans[100010];

void solve(){
  int n=read(),k=read();
  int pos1 = 0, pos2 = 0;
  int now = 0;
  k = n * (n - 1) / 2 - k + 1;
  rep(i, 1, n) {
    now += n - i;
    if (k <= now) {
      now -= k;
      pos1 = i;
      pos2 = n - now;
      break;
    }
  }
  rep(i, 1, n) {
    putchar(i == pos1 || i == pos2 ? 'b' : 'a');
  }
  puts("");
}
signed main() {
  int T = read();
  while (T--)solve();
  return 0;
}