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
int n, m;
ll a[maxn], sum[maxn], ans[maxn];

int main() {
  cin >> n >> m;
  rep(i, 1, m) a[i] = read();
  per(i, m, 1) sum[i] = sum[i + 1] + a[i];
  if (sum[1] < n) return puts("-1"), 0;
  rep(i, 1, m) if (n - i + 1 > sum[i]) {
    rep(j, i, m) if (j + a[j] - 1 > n) {
      return puts("-1"), 0;
    } else ans[j] = n - sum[j] + 1;
    break;
  } else {
    if (i + a[i] - 1 > n) return puts("-1"), 0;
    ans[i] = i;
  }
  rep(i, 1, m) printf("%d ", ans[i]);
  return 0;
}