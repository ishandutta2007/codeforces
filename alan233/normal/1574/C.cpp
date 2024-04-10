// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 200005;

ll a[N], sum;
int n, q;

int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  scanf("%d", &q);
  while (q--) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    ll ans = 5e18;
    int pos = lower_bound(a + 1, a + n + 1, x) - a;
    if (pos != n + 1) {
      ckmin(ans, max(0ll, y - (sum - a[pos])));
    }
    if (pos != 1) {
      ckmin(ans, x - a[pos - 1] + max(0ll, y - (sum - a[pos - 1])));
    }
    printf("%lld\n", ans);
  }
  return 0;
}