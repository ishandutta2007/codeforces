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
bool isp[1010];
int cnt, tid[1010],mp[1010];
bool vis[20];
int n, a[1010], col[1010], tot, is[20];

bool pd(int x) {
  int tmp = sqrt(x);
  rep(i, 2, tmp) if (x % i == 0) {
    return 0;
  }
  return x > 1;
}

void solve() {
  cin >> n;
  rep(i,1, n) a[i] = read();
  memset(vis, 0, sizeof vis);
  rep(i, 1, n) {
    int x = a[i];
    int pos = 0;
    rep(j, 2, x) {
      if (isp[j] && x % j == 0) {
        pos = j; break;
      }
    }
    col[i] = mp[pos];
    vis[col[i]] = 1;
  }
  tot = 0;
  rep(i, 1, 11) if (vis[i]) is[i] = ++tot;
  printf("%d\n", tot);
  rep(i, 1, n)printf("%d%c",is[col[i]],"\n "[i<n]);
}

int main() {
  rep(i, 2, 1010)
  {isp[i] = pd(i);
  if (isp[i]) tid[++cnt] = i,mp[i]=cnt;
  }
  int T = read();
  while (T--) solve();
  return 0;
}