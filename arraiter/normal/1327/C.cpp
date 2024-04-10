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
int n, m, k;
string ans = "";

struct node {
  int x, y;
} a[205];

int main() {
  cin >> n >> m >> k;
  rep(i, 1, k) {
    a[i].x = read(), a[i].y = read();
  }
  rep(i, 1, n - 1) ans += 'U';
  rep(i, 1, m - 1) ans += 'L';
  rep(i, 1, n) {
    rep(j, 1, m - 1) ans += i & 1 ? 'R' : 'L';
    if (i < n) ans += 'D';
  }
  printf("%d\n", (int) ans.size());
  cout << ans;
  return 0;
}