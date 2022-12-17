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
const int maxn = 2e5 + 10;
char str[maxn];
int n, k, cnt[26];

void solve() {
  scanf("%d %d %s", &n, &k, str + 1);
  int res = 0;
  rep(i, 1, (k + 1) / 2) {
    int all = 0;
    int tmp = k - i + 1 - i;
    memset(cnt, 0, sizeof cnt);
    for (int j = i; j <= n; j += k) {
      all += 2;
      cnt[str[j] - 'a']++, cnt[str[j + tmp] - 'a']++;
    }
    int mx = 0;
    rep(j, 0, 25) chkmax(mx, cnt[j]);
    if (k % 2 == 1 && i == (k + 1) / 2) {
      res += (all - mx) / 2;
    } else {
      res += all - mx;
    }
  }
  cout << res << endl;
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}